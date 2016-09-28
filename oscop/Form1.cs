using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;
using System.Windows.Forms.DataVisualization.Charting;
using System.Data.OleDb;
using System.Runtime.InteropServices;
using Microsoft.Win32.SafeHandles;
using System.Collections;
using System.Runtime.Serialization.Formatters.Binary;
using System.Net.Sockets;
using System.Net;
using System.Timers;
using System.Diagnostics;
using System.IO;
using Excel = Microsoft.Office.Interop.Excel;
namespace Servo
{
    public partial class Form1 : Form
    {
        Thread SerialThread;

        Mutex SerialPortMutex = new Mutex();

        const int window_size = 100;

        Excel.Application xlapp;
        Excel.Workbook xlworkbook;
        Excel.Worksheet xlworksheet;

        DataTable dtexcel = new DataTable();

        float linear_phase;
        public Form1()
        {
            InitializeComponent();
            SerialThread = new Thread(ReadSerial);
            ReadExcel(System.Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\Calibration.xls" );
        }

        private void btnRefreshPorts_Click(object sender, EventArgs e)
        {
            GetAvailablePorts();
        }

        void GetAvailablePorts()
        {
            cbxSerialPort.Items.Clear();
            string[] Ports = SerialPort.GetPortNames();
            cbxSerialPort.Items.AddRange(Ports);
            if (cbxSerialPort.Items.Count > 0)
            {
                cbxSerialPort.SelectedIndex = 0;
            }
        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            try
            {
                if (!MySerial.IsOpen && cbxSerialPort.SelectedIndex != -1)
                {
                    ConnectSerialPort();
                }
                else
                {
                    DisconnectSerialPort();
                }
            }
            catch (Exception ex) { MessageBox.Show(ex.Message); }
        }

        private void ConnectSerialPort()
        {
            try
            {
                MySerial.PortName = cbxSerialPort.SelectedItem.ToString();
                MySerial.StopBits = System.IO.Ports.StopBits.One;
                MySerial.Parity = System.IO.Ports.Parity.None;
                MySerial.BaudRate = 115200;
                MySerial.DataBits = 8;
                MySerial.Open();
                btnConnect.Text = "Disconnect";
                if (SerialThread.IsAlive)
                {
                    SerialThread.Abort();
                }
                SerialThread = new Thread(ReadSerial);
                SerialThread.Start();
                SerialThread.Priority = System.Threading.ThreadPriority.Highest;
            }
            catch (Exception ex) { MessageBox.Show(ex.Message); }
        }

        private void DisconnectSerialPort()
        {
            try
            {
                SerialPortMutex.WaitOne();
                MySerial.Close();
                btnConnect.Text = "Connect";
                if (SerialThread.IsAlive)
                {
                    SerialThread.Abort();
                }
                gbxConnectionSetting.Enabled = true;
                Update1_Timer.Stop();
           //     panel1.Enabled = panel2.Enabled = panel3.Enabled = panel4.Enabled = panel5.Enabled = panel6.Enabled = gbxPhaseAttenuator.Enabled = gbxADC.Enabled = false;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                MySerial.Dispose();
            }
        }

        private void Update_Timer_Tick(object sender, EventArgs e)
        {
            try
            {
                byte[] Update1 = { 1 };
                MySerial.Write(Update1, 0, 1);
            }
            catch (Exception)
            {
                DisconnectSerialPort();
                MessageBox.Show("Serial port is disconnected");
            }
            labelphase.Text = "phase:" + linear_phase.ToString("00.000");
        }

        byte[] Recieved_Data = new byte[30];

        private void ReadSerial()
        {
            chart.Invoke(new Action(() => chart.ChartAreas[0].AxisX.IsStartedFromZero = false));
            chart.Invoke(new Action(() => chart.ChartAreas[0].AxisY.Maximum = double.NaN));
            //chart.Invoke(new Action(() => chart.ChartAreas[0].AxisY.Minimum = -.2));
            chart.Invoke(new Action(() => chart.ChartAreas[0].AxisY.IsStartedFromZero = false));
            chart.Invoke(new Action(() => chart.ChartAreas[0].AxisX.LabelStyle.Enabled = false));
            chart.Invoke(new Action(() => chart.ChartAreas[0].RecalculateAxesScale()));

            while (MySerial.IsOpen)
            {
                if (MySerial.BytesToRead > 23)
                {
                    MySerial.Read(Recieved_Data, 0, 24);
                }               
                ProcessData();   
            }
        }

        float []Analog1 = new float[window_size];
        float []Analog2 = new float[window_size];
        float []Analog3= new float[window_size];
        float []Analog4= new float[window_size]; 
        float []Analog5= new float[window_size];
        float []Analog6= new float[window_size];
        float mean1, mean2, mean3, mean4, mean5, mean6;
        private void ProcessData()
        {
            shift_All();

            mean1 = calculate_mean(Analog1);
            mean2 = calculate_mean(Analog2);
            mean3 = calculate_mean(Analog3);
            mean4 = calculate_mean(Analog4);
            mean5 = calculate_mean(Analog5);
            mean6 = calculate_mean(Analog6);

            txtAnalog1.Invoke(new Action(() => txtAnalog1.Text = mean1.ToString("00.000")));
            txtAnalog2.Invoke(new Action(() => txtAnalog2.Text = mean2.ToString("00.000")));
            txtAnalog3.Invoke(new Action(() => txtAnalog3.Text = mean3.ToString("00.000")));
            txtAnalog4.Invoke(new Action(() => txtAnalog4.Text = mean4.ToString("00.000")));
            txtAnalog5.Invoke(new Action(() => txtAnalog5.Text = mean5.ToString("00.000")));
            txtAnalog6.Invoke(new Action(() => txtAnalog6.Text = mean6.ToString("00.000")));

            if (!bgwchart.IsBusy)
            {
                bgwchart.RunWorkerAsync();
            }
            float Qmax_below_v = 0, Qmin_up_v = 3, Imax_below_v = 0, Imin_up_v = 3, Qfirst , Qsec , Ifirst , Isec;
            float max_below_deg = 0, min_up_deg = 360;
            for (int i = 1; i<dtexcel.Rows.Count - 1; i++)
            {
                Qfirst = Convert.ToSingle( dtexcel.Rows[i][1].ToString() );
                Qsec = Convert.ToSingle( dtexcel.Rows[i+1][1].ToString() );
                Ifirst = Convert.ToSingle( dtexcel.Rows[i][2].ToString() );
                Isec = Convert.ToSingle( dtexcel.Rows[i+1][2].ToString() );
                if ((mean1 < Qfirst && mean1 > Qsec) || (mean1 > Qfirst && mean1 < Qsec))
                {
                    if ((mean4 < Ifirst && mean4 > Isec) || (mean4 > Ifirst && mean4 < Isec))
                    {
                        if (Qfirst > Qsec)
                        {
                            Qmax_below_v = Qsec;
                            Qmin_up_v = Qfirst;
                        }
                        else
                        {
                            Qmax_below_v = Qfirst;
                            Qmin_up_v = Qsec;
                        }
                        if (Ifirst > Isec)
                        {
                            Imax_below_v = Isec;
                            Imin_up_v = Ifirst;
                        }
                        else
                        {
                            Imax_below_v = Ifirst;
                            Imin_up_v = Isec;
                        }
                        min_up_deg = Convert.ToSingle(dtexcel.Rows[i][0].ToString());
                        max_below_deg = Convert.ToSingle(dtexcel.Rows[i+1][0].ToString());
                    }
                }
            }
            if ((min_up_deg > 45 && min_up_deg < 135) || (min_up_deg > 225 && min_up_deg < 315))
                linear_phase = ((mean1 - Qmax_below_v) * (min_up_deg - max_below_deg))/ (Qmin_up_v - Qmax_below_v) + max_below_deg;
            else
                linear_phase = ((mean1 - Imax_below_v) * (min_up_deg - max_below_deg))/ (Imin_up_v- Imax_below_v) + max_below_deg;
        }
        private void shift_All()
        {
            int i;
            for (i = 0; i < window_size-1; i++)
            {
                Analog1[i] = Analog1[i + 1];
                Analog2[i] = Analog2[i + 1];
                Analog3[i] = Analog3[i + 1];
                Analog4[i] = Analog4[i + 1];
                Analog5[i] = Analog5[i + 1];
                Analog6[i] = Analog6[i + 1];
            }
            Analog1[window_size - 1] = BitConverter.ToSingle(Recieved_Data, 0);
            Analog2[window_size - 1] = BitConverter.ToSingle(Recieved_Data, 4);
            Analog3[window_size - 1] = BitConverter.ToSingle(Recieved_Data, 8);
            Analog4[window_size - 1] = BitConverter.ToSingle(Recieved_Data, 12);
            Analog5[window_size - 1] = BitConverter.ToSingle(Recieved_Data, 16);
            Analog6[window_size - 1] = BitConverter.ToSingle(Recieved_Data, 20);
        }

        private float calculate_mean(float[] Analogs)
        {
            float sum = 0; int i;
            for (i = 0; i < window_size; i++) 
                sum += Analogs[i];
            return sum / Convert.ToSingle( window_size);
        }

        float Analog;
        Series AnalogSeries = new Series();
        int time = 0;

        private void bgwchart_DoWork(object sender, DoWorkEventArgs e)
        {
            time++;

            if (rdbAnalog1.Checked)
            {
                Analog = mean1;
            }
            else if (rdbAnalog2.Checked)
            {
                Analog = mean2;
            }
            else if (rdbAnalog3.Checked)
            {
                Analog = mean3;
            }
            else if (rdbAnalog4.Checked)
            {
                Analog = mean4;
            }
            else if (rdbAnalog5.Checked)
            {
                Analog = mean5;
            }
            else if (rdbAnalog6.Checked)
            {
                Analog = mean6;
            }


            chart.Invoke(new Action(() => AnalogSeries.Points.AddXY(time, Analog)));
            chart.Invoke(new Action(() => chart.ChartAreas[0].AxisX.Maximum = time));
            chart.Invoke(new Action(() => chart.ChartAreas[0].AxisX.Minimum = time - 100));
            //chart.Invoke(new Action(() => chart.ChartAreas[0].AxisX.IsStartedFromZero = false));
           /// chart.Invoke(new Action(() => chart.ChartAreas[0].AxisY.Maximum = 2));
          ///  chart.Invoke(new Action(() => chart.ChartAreas[0].AxisY.Minimum = -.2));
          //  chart.Invoke(new Action(() => chart.ChartAreas[0].AxisY.IsStartedFromZero = false));
            //chart.Invoke(new Action(() => chart.ChartAreas[0].RecalculateAxesScale()));
            chart.Invoke(new Action(() => chart.Series.Clear()));
          //  chart.Invoke(new Action(() => chart.Legends.Clear()));
            chart.Invoke(new Action(() => chart.Series.Add(AnalogSeries)));
          //  chart.Invoke(new Action(() => chart.Titles.Clear()));
         //   chart.Invoke(new Action(() => chart.Titles.Add("")));
        //    chart.Invoke(new Action(() => chart.Series[0].BorderColor = Color.Red));
            chart.Invoke(new Action(() => chart.Series[0].BorderWidth = 3));
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            AnalogSeries.ChartType = SeriesChartType.FastLine;
            chart.Titles.Clear();
            chart.Series.Clear();
            chart.ChartAreas[0].AxisX.MajorGrid.LineColor = Color.Green;
            chart.ChartAreas[0].AxisY.MajorGrid.LineColor = Color.Green;
            chart.ChartAreas[0].AxisX.MajorGrid.LineWidth = 1;
            chart.ChartAreas[0].AxisY.MajorGrid.LineWidth = 1;
            chart.ChartAreas[0].AxisX.Interval = 100;
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            MySerial.Close();
            Thread.Sleep(10);
            SerialThread.Abort();
            Thread.Sleep(10);
            DisconnectSerialPort();
            Application.Exit();
        }

        private void numUpdate1_ValueChanged(object sender, EventArgs e)
        {
            Update1_Timer.Interval = Convert.ToInt16(numUpdate1.Value);
        }
        private void btnUpdate1_Click(object sender, EventArgs e)
        {
            try
            {
                if (btnUpdate1.Text == "Start")
                {
                    Update1_Timer.Start();
                    btnUpdate1.Text = "Stop";
                }
                else
                {
                    Update1_Timer.Stop();
                    btnUpdate1.Text = "Start";
                }
            }
            catch (Exception)
            {
                MessageBox.Show("serial port is disconnected");
                DisconnectSerialPort();
            }
        }
        float base_phase;
        int calibrate_counter;
        
        object misvalue = System.Reflection.Missing.Value;
        private void set_step_button_Click(object sender, EventArgs e)
        {
            xlapp = new Excel.Application();
            xlworkbook = xlapp.Workbooks.Add(misvalue);
            xlworksheet = (Excel.Worksheet)xlworkbook.Worksheets.get_Item(1);
            xlworksheet.Cells[1, 1] = "phase";
            xlworksheet.Cells[1, 2] = "quadrature phase voltage";
            xlworksheet.Cells[1, 3] = "inphase phase voltage";
            phase.Text = "set phase at 0 degree";
            try
            {
                base_phase = Convert.ToSingle(base_phase_label.Text);
            }
            catch (Exception ex) { MessageBox.Show(ex.Message.ToString()); return; }
            calibrate.Enabled = true;
            base_phase_label.Enabled = false;
            set_step_button.Enabled = false;
        }
        private void calibrate_Click_1(object sender, EventArgs e)
        {
            xlworksheet.Cells[calibrate_counter + 2, 1] =  Convert.ToSingle(calibrate_counter) * base_phase;
            xlworksheet.Cells[calibrate_counter + 2, 2] = mean1;
            xlworksheet.Cells[calibrate_counter + 2, 3] = mean4;
            
            calibrate_counter++;
            if (Convert.ToSingle(calibrate_counter) * base_phase > 360)
            {
                string path = System.Environment.GetFolderPath(Environment.SpecialFolder.Desktop);
                calibrate_counter = 0;
                phase.Text = "calibration finished";
                try
                {
                    xlworkbook.SaveAs(path + "\\Calibration.xls", Excel.XlFileFormat.xlWorkbookNormal, misvalue, misvalue, misvalue, misvalue, Excel.XlSaveAsAccessMode.xlExclusive, misvalue, misvalue, misvalue, misvalue, misvalue);
                }
                catch (Exception ex) {}
                xlworkbook.Close(true, misvalue, misvalue);
                xlapp.Quit();
                calibrate.Enabled = false;
                base_phase_label.Text = "";
                base_phase_label.Enabled = true;
                set_step_button.Enabled = true;
                ReadExcel(path + "\\Calibration.xls");
            }
            else
                phase.Text = "set phase at " + Convert.ToString(Convert.ToSingle(calibrate_counter) * base_phase) + " degree";
        }
        

        public void ReadExcel(string fileName)
        {
            string conn = string.Empty;
            conn = @"provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + fileName + ";Extended Properties='Excel 8.0;HRD=Yes;IMEX=1';";//for below excel 2007
            using (OleDbConnection con = new OleDbConnection(conn))
            {
                try
                {
                    OleDbDataAdapter oleAdpt = new OleDbDataAdapter("select * from [Sheet1$]", con);//here we read data from sheet1
                    oleAdpt.Fill(dtexcel);//fill excel data into dataTable
                    oleAdpt.Dispose();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message.ToString());
                }
            }
        }
    }
}