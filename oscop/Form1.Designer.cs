namespace Servo
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            this.btnConnect = new System.Windows.Forms.Button();
            this.btnRefreshPort = new System.Windows.Forms.Button();
            this.lblPorts = new System.Windows.Forms.Label();
            this.cbxSerialPort = new System.Windows.Forms.ComboBox();
            this.MySerial = new System.IO.Ports.SerialPort(this.components);
            this.Update1_Timer = new System.Windows.Forms.Timer(this.components);
            this.gbxADC = new System.Windows.Forms.GroupBox();
            this.rdbAnalog6 = new System.Windows.Forms.RadioButton();
            this.rdbAnalog5 = new System.Windows.Forms.RadioButton();
            this.rdbAnalog4 = new System.Windows.Forms.RadioButton();
            this.rdbAnalog3 = new System.Windows.Forms.RadioButton();
            this.rdbAnalog2 = new System.Windows.Forms.RadioButton();
            this.rdbAnalog1 = new System.Windows.Forms.RadioButton();
            this.lblAnalog6 = new System.Windows.Forms.Label();
            this.lblAnalog5 = new System.Windows.Forms.Label();
            this.lblAnalog4 = new System.Windows.Forms.Label();
            this.txtAnalog6 = new System.Windows.Forms.TextBox();
            this.txtAnalog5 = new System.Windows.Forms.TextBox();
            this.txtAnalog4 = new System.Windows.Forms.TextBox();
            this.lblAnalog3 = new System.Windows.Forms.Label();
            this.txtAnalog3 = new System.Windows.Forms.TextBox();
            this.lblAnalog2 = new System.Windows.Forms.Label();
            this.txtAnalog2 = new System.Windows.Forms.TextBox();
            this.lblAnalog1 = new System.Windows.Forms.Label();
            this.txtAnalog1 = new System.Windows.Forms.TextBox();
            this.chart = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.gbxConnectionSetting = new System.Windows.Forms.GroupBox();
            this.bgwchart = new System.ComponentModel.BackgroundWorker();
            this.numUpdate1 = new System.Windows.Forms.NumericUpDown();
            this.label19 = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.btnUpdate1 = new System.Windows.Forms.Button();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.labelphase = new System.Windows.Forms.Label();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.phase = new System.Windows.Forms.Label();
            this.set_step_button = new System.Windows.Forms.Button();
            this.calibrate = new System.Windows.Forms.Button();
            this.base_phase_label = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.gbxADC.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart)).BeginInit();
            this.gbxConnectionSetting.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numUpdate1)).BeginInit();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnConnect
            // 
            this.btnConnect.Font = new System.Drawing.Font("Arial Narrow", 12F);
            this.btnConnect.ForeColor = System.Drawing.Color.Black;
            this.btnConnect.Location = new System.Drawing.Point(168, 41);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(100, 27);
            this.btnConnect.TabIndex = 17;
            this.btnConnect.Text = "Connect";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // btnRefreshPort
            // 
            this.btnRefreshPort.Font = new System.Drawing.Font("Arial Narrow", 12F);
            this.btnRefreshPort.ForeColor = System.Drawing.Color.Black;
            this.btnRefreshPort.Location = new System.Drawing.Point(135, 42);
            this.btnRefreshPort.Name = "btnRefreshPort";
            this.btnRefreshPort.Size = new System.Drawing.Size(27, 27);
            this.btnRefreshPort.TabIndex = 16;
            this.btnRefreshPort.Text = "R";
            this.btnRefreshPort.UseVisualStyleBackColor = true;
            this.btnRefreshPort.Click += new System.EventHandler(this.btnRefreshPorts_Click);
            // 
            // lblPorts
            // 
            this.lblPorts.AutoSize = true;
            this.lblPorts.Font = new System.Drawing.Font("Arial Narrow", 12F);
            this.lblPorts.Location = new System.Drawing.Point(6, 45);
            this.lblPorts.Name = "lblPorts";
            this.lblPorts.Size = new System.Drawing.Size(44, 20);
            this.lblPorts.TabIndex = 15;
            this.lblPorts.Text = "Ports:";
            // 
            // cbxSerialPort
            // 
            this.cbxSerialPort.Font = new System.Drawing.Font("Arial Narrow", 12F);
            this.cbxSerialPort.FormattingEnabled = true;
            this.cbxSerialPort.Location = new System.Drawing.Point(50, 41);
            this.cbxSerialPort.Name = "cbxSerialPort";
            this.cbxSerialPort.Size = new System.Drawing.Size(79, 28);
            this.cbxSerialPort.TabIndex = 13;
            // 
            // Update1_Timer
            // 
            this.Update1_Timer.Tick += new System.EventHandler(this.Update_Timer_Tick);
            // 
            // gbxADC
            // 
            this.gbxADC.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.gbxADC.Controls.Add(this.rdbAnalog6);
            this.gbxADC.Controls.Add(this.rdbAnalog5);
            this.gbxADC.Controls.Add(this.rdbAnalog4);
            this.gbxADC.Controls.Add(this.rdbAnalog3);
            this.gbxADC.Controls.Add(this.rdbAnalog2);
            this.gbxADC.Controls.Add(this.rdbAnalog1);
            this.gbxADC.Controls.Add(this.lblAnalog6);
            this.gbxADC.Controls.Add(this.lblAnalog5);
            this.gbxADC.Controls.Add(this.lblAnalog4);
            this.gbxADC.Controls.Add(this.txtAnalog6);
            this.gbxADC.Controls.Add(this.txtAnalog5);
            this.gbxADC.Controls.Add(this.txtAnalog4);
            this.gbxADC.Controls.Add(this.lblAnalog3);
            this.gbxADC.Controls.Add(this.txtAnalog3);
            this.gbxADC.Controls.Add(this.lblAnalog2);
            this.gbxADC.Controls.Add(this.txtAnalog2);
            this.gbxADC.Controls.Add(this.lblAnalog1);
            this.gbxADC.Controls.Add(this.txtAnalog1);
            this.gbxADC.Controls.Add(this.chart);
            this.gbxADC.Font = new System.Drawing.Font("Arial Narrow", 12F);
            this.gbxADC.Location = new System.Drawing.Point(9, 119);
            this.gbxADC.Margin = new System.Windows.Forms.Padding(10, 3, 10, 3);
            this.gbxADC.Name = "gbxADC";
            this.gbxADC.Size = new System.Drawing.Size(1110, 406);
            this.gbxADC.TabIndex = 44;
            this.gbxADC.TabStop = false;
            this.gbxADC.Text = "ADC";
            // 
            // rdbAnalog6
            // 
            this.rdbAnalog6.AutoSize = true;
            this.rdbAnalog6.Location = new System.Drawing.Point(970, 35);
            this.rdbAnalog6.Name = "rdbAnalog6";
            this.rdbAnalog6.Size = new System.Drawing.Size(14, 13);
            this.rdbAnalog6.TabIndex = 79;
            this.rdbAnalog6.UseVisualStyleBackColor = true;
            // 
            // rdbAnalog5
            // 
            this.rdbAnalog5.AutoSize = true;
            this.rdbAnalog5.Location = new System.Drawing.Point(809, 35);
            this.rdbAnalog5.Name = "rdbAnalog5";
            this.rdbAnalog5.Size = new System.Drawing.Size(14, 13);
            this.rdbAnalog5.TabIndex = 78;
            this.rdbAnalog5.UseVisualStyleBackColor = true;
            // 
            // rdbAnalog4
            // 
            this.rdbAnalog4.AutoSize = true;
            this.rdbAnalog4.Location = new System.Drawing.Point(641, 36);
            this.rdbAnalog4.Name = "rdbAnalog4";
            this.rdbAnalog4.Size = new System.Drawing.Size(14, 13);
            this.rdbAnalog4.TabIndex = 77;
            this.rdbAnalog4.UseVisualStyleBackColor = true;
            // 
            // rdbAnalog3
            // 
            this.rdbAnalog3.AutoSize = true;
            this.rdbAnalog3.Location = new System.Drawing.Point(493, 36);
            this.rdbAnalog3.Name = "rdbAnalog3";
            this.rdbAnalog3.Size = new System.Drawing.Size(14, 13);
            this.rdbAnalog3.TabIndex = 76;
            this.rdbAnalog3.UseVisualStyleBackColor = true;
            // 
            // rdbAnalog2
            // 
            this.rdbAnalog2.AutoSize = true;
            this.rdbAnalog2.Location = new System.Drawing.Point(304, 35);
            this.rdbAnalog2.Name = "rdbAnalog2";
            this.rdbAnalog2.Size = new System.Drawing.Size(14, 13);
            this.rdbAnalog2.TabIndex = 75;
            this.rdbAnalog2.UseVisualStyleBackColor = true;
            // 
            // rdbAnalog1
            // 
            this.rdbAnalog1.AutoSize = true;
            this.rdbAnalog1.Checked = true;
            this.rdbAnalog1.Location = new System.Drawing.Point(121, 36);
            this.rdbAnalog1.Name = "rdbAnalog1";
            this.rdbAnalog1.Size = new System.Drawing.Size(14, 13);
            this.rdbAnalog1.TabIndex = 74;
            this.rdbAnalog1.TabStop = true;
            this.rdbAnalog1.UseVisualStyleBackColor = true;
            // 
            // lblAnalog6
            // 
            this.lblAnalog6.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.lblAnalog6.AutoSize = true;
            this.lblAnalog6.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAnalog6.ForeColor = System.Drawing.Color.Red;
            this.lblAnalog6.Location = new System.Drawing.Point(848, 31);
            this.lblAnalog6.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblAnalog6.Name = "lblAnalog6";
            this.lblAnalog6.Size = new System.Drawing.Size(47, 20);
            this.lblAnalog6.TabIndex = 71;
            this.lblAnalog6.Text = "VmagI";
            // 
            // lblAnalog5
            // 
            this.lblAnalog5.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.lblAnalog5.AutoSize = true;
            this.lblAnalog5.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAnalog5.ForeColor = System.Drawing.Color.Red;
            this.lblAnalog5.Location = new System.Drawing.Point(698, 31);
            this.lblAnalog5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblAnalog5.Name = "lblAnalog5";
            this.lblAnalog5.Size = new System.Drawing.Size(36, 20);
            this.lblAnalog5.TabIndex = 70;
            this.lblAnalog5.Text = "VrefI";
            // 
            // lblAnalog4
            // 
            this.lblAnalog4.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.lblAnalog4.AutoSize = true;
            this.lblAnalog4.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAnalog4.ForeColor = System.Drawing.Color.Red;
            this.lblAnalog4.Location = new System.Drawing.Point(530, 30);
            this.lblAnalog4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblAnalog4.Name = "lblAnalog4";
            this.lblAnalog4.Size = new System.Drawing.Size(36, 20);
            this.lblAnalog4.TabIndex = 69;
            this.lblAnalog4.Text = "VphI";
            // 
            // txtAnalog6
            // 
            this.txtAnalog6.BackColor = System.Drawing.Color.White;
            this.txtAnalog6.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtAnalog6.ForeColor = System.Drawing.Color.Black;
            this.txtAnalog6.Location = new System.Drawing.Point(903, 27);
            this.txtAnalog6.Margin = new System.Windows.Forms.Padding(4);
            this.txtAnalog6.Name = "txtAnalog6";
            this.txtAnalog6.ReadOnly = true;
            this.txtAnalog6.Size = new System.Drawing.Size(60, 26);
            this.txtAnalog6.TabIndex = 51;
            this.txtAnalog6.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // txtAnalog5
            // 
            this.txtAnalog5.BackColor = System.Drawing.Color.White;
            this.txtAnalog5.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtAnalog5.ForeColor = System.Drawing.Color.Black;
            this.txtAnalog5.Location = new System.Drawing.Point(742, 27);
            this.txtAnalog5.Margin = new System.Windows.Forms.Padding(4);
            this.txtAnalog5.Name = "txtAnalog5";
            this.txtAnalog5.ReadOnly = true;
            this.txtAnalog5.Size = new System.Drawing.Size(60, 26);
            this.txtAnalog5.TabIndex = 49;
            this.txtAnalog5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // txtAnalog4
            // 
            this.txtAnalog4.BackColor = System.Drawing.Color.White;
            this.txtAnalog4.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtAnalog4.ForeColor = System.Drawing.Color.Black;
            this.txtAnalog4.Location = new System.Drawing.Point(574, 28);
            this.txtAnalog4.Margin = new System.Windows.Forms.Padding(4);
            this.txtAnalog4.Name = "txtAnalog4";
            this.txtAnalog4.ReadOnly = true;
            this.txtAnalog4.Size = new System.Drawing.Size(60, 26);
            this.txtAnalog4.TabIndex = 47;
            this.txtAnalog4.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lblAnalog3
            // 
            this.lblAnalog3.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.lblAnalog3.AutoSize = true;
            this.lblAnalog3.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAnalog3.ForeColor = System.Drawing.Color.Red;
            this.lblAnalog3.Location = new System.Drawing.Point(375, 31);
            this.lblAnalog3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblAnalog3.Name = "lblAnalog3";
            this.lblAnalog3.Size = new System.Drawing.Size(43, 20);
            this.lblAnalog3.TabIndex = 46;
            this.lblAnalog3.Text = "VrefQ";
            // 
            // txtAnalog3
            // 
            this.txtAnalog3.BackColor = System.Drawing.Color.White;
            this.txtAnalog3.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtAnalog3.ForeColor = System.Drawing.Color.Black;
            this.txtAnalog3.Location = new System.Drawing.Point(426, 28);
            this.txtAnalog3.Margin = new System.Windows.Forms.Padding(4);
            this.txtAnalog3.Name = "txtAnalog3";
            this.txtAnalog3.ReadOnly = true;
            this.txtAnalog3.Size = new System.Drawing.Size(60, 26);
            this.txtAnalog3.TabIndex = 45;
            this.txtAnalog3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lblAnalog2
            // 
            this.lblAnalog2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.lblAnalog2.AutoSize = true;
            this.lblAnalog2.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAnalog2.ForeColor = System.Drawing.Color.Red;
            this.lblAnalog2.Location = new System.Drawing.Point(175, 31);
            this.lblAnalog2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblAnalog2.Name = "lblAnalog2";
            this.lblAnalog2.Size = new System.Drawing.Size(54, 20);
            this.lblAnalog2.TabIndex = 44;
            this.lblAnalog2.Text = "VmagQ";
            // 
            // txtAnalog2
            // 
            this.txtAnalog2.BackColor = System.Drawing.Color.White;
            this.txtAnalog2.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtAnalog2.ForeColor = System.Drawing.Color.Black;
            this.txtAnalog2.Location = new System.Drawing.Point(237, 27);
            this.txtAnalog2.Margin = new System.Windows.Forms.Padding(4);
            this.txtAnalog2.Name = "txtAnalog2";
            this.txtAnalog2.ReadOnly = true;
            this.txtAnalog2.Size = new System.Drawing.Size(60, 26);
            this.txtAnalog2.TabIndex = 43;
            this.txtAnalog2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lblAnalog1
            // 
            this.lblAnalog1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.lblAnalog1.AutoSize = true;
            this.lblAnalog1.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAnalog1.ForeColor = System.Drawing.Color.Red;
            this.lblAnalog1.Location = new System.Drawing.Point(5, 30);
            this.lblAnalog1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblAnalog1.Name = "lblAnalog1";
            this.lblAnalog1.Size = new System.Drawing.Size(43, 20);
            this.lblAnalog1.TabIndex = 42;
            this.lblAnalog1.Text = "VphQ";
            // 
            // txtAnalog1
            // 
            this.txtAnalog1.BackColor = System.Drawing.Color.White;
            this.txtAnalog1.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtAnalog1.ForeColor = System.Drawing.Color.Black;
            this.txtAnalog1.Location = new System.Drawing.Point(56, 28);
            this.txtAnalog1.Margin = new System.Windows.Forms.Padding(4);
            this.txtAnalog1.Name = "txtAnalog1";
            this.txtAnalog1.ReadOnly = true;
            this.txtAnalog1.Size = new System.Drawing.Size(60, 26);
            this.txtAnalog1.TabIndex = 41;
            this.txtAnalog1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // chart
            // 
            chartArea1.Name = "ChartArea1";
            this.chart.ChartAreas.Add(chartArea1);
            this.chart.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.chart.Location = new System.Drawing.Point(3, 61);
            this.chart.Name = "chart";
            this.chart.Size = new System.Drawing.Size(1104, 342);
            this.chart.TabIndex = 73;
            this.chart.Text = "chart1";
            // 
            // gbxConnectionSetting
            // 
            this.gbxConnectionSetting.Controls.Add(this.btnConnect);
            this.gbxConnectionSetting.Controls.Add(this.btnRefreshPort);
            this.gbxConnectionSetting.Controls.Add(this.lblPorts);
            this.gbxConnectionSetting.Controls.Add(this.cbxSerialPort);
            this.gbxConnectionSetting.Font = new System.Drawing.Font("Arial Narrow", 12F);
            this.gbxConnectionSetting.Location = new System.Drawing.Point(12, 10);
            this.gbxConnectionSetting.Name = "gbxConnectionSetting";
            this.gbxConnectionSetting.Size = new System.Drawing.Size(274, 102);
            this.gbxConnectionSetting.TabIndex = 45;
            this.gbxConnectionSetting.TabStop = false;
            this.gbxConnectionSetting.Text = "Connection Setting";
            // 
            // bgwchart
            // 
            this.bgwchart.DoWork += new System.ComponentModel.DoWorkEventHandler(this.bgwchart_DoWork);
            // 
            // numUpdate1
            // 
            this.numUpdate1.Location = new System.Drawing.Point(113, 24);
            this.numUpdate1.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.numUpdate1.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numUpdate1.Name = "numUpdate1";
            this.numUpdate1.Size = new System.Drawing.Size(53, 20);
            this.numUpdate1.TabIndex = 54;
            this.numUpdate1.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.numUpdate1.ValueChanged += new System.EventHandler(this.numUpdate1_ValueChanged);
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Location = new System.Drawing.Point(24, 28);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(89, 13);
            this.label19.TabIndex = 55;
            this.label19.Text = "Update 1 Interval";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.label18.Location = new System.Drawing.Point(168, 28);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(20, 13);
            this.label18.TabIndex = 57;
            this.label18.Text = "ms";
            // 
            // btnUpdate1
            // 
            this.btnUpdate1.Location = new System.Drawing.Point(190, 23);
            this.btnUpdate1.Name = "btnUpdate1";
            this.btnUpdate1.Size = new System.Drawing.Size(47, 23);
            this.btnUpdate1.TabIndex = 59;
            this.btnUpdate1.Text = "Start";
            this.btnUpdate1.UseVisualStyleBackColor = true;
            this.btnUpdate1.Click += new System.EventHandler(this.btnUpdate1_Click);
            // 
            // tabControl1
            // 
            this.tabControl1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Location = new System.Drawing.Point(292, 10);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(831, 102);
            this.tabControl1.TabIndex = 18;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.labelphase);
            this.tabPage1.Controls.Add(this.btnUpdate1);
            this.tabPage1.Controls.Add(this.numUpdate1);
            this.tabPage1.Controls.Add(this.label19);
            this.tabPage1.Controls.Add(this.label18);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(823, 76);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Timer setting";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // labelphase
            // 
            this.labelphase.AutoSize = true;
            this.labelphase.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelphase.Location = new System.Drawing.Point(296, 27);
            this.labelphase.Name = "labelphase";
            this.labelphase.Size = new System.Drawing.Size(51, 17);
            this.labelphase.TabIndex = 60;
            this.labelphase.Text = "phase:";
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.phase);
            this.tabPage2.Controls.Add(this.set_step_button);
            this.tabPage2.Controls.Add(this.calibrate);
            this.tabPage2.Controls.Add(this.base_phase_label);
            this.tabPage2.Controls.Add(this.label1);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(823, 76);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "calibration";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // phase
            // 
            this.phase.AutoSize = true;
            this.phase.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.phase.Location = new System.Drawing.Point(368, 31);
            this.phase.Name = "phase";
            this.phase.Size = new System.Drawing.Size(147, 17);
            this.phase.TabIndex = 67;
            this.phase.Text = "set phase at 0 degree";
            // 
            // set_step_button
            // 
            this.set_step_button.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.set_step_button.Location = new System.Drawing.Point(264, 27);
            this.set_step_button.Name = "set_step_button";
            this.set_step_button.Size = new System.Drawing.Size(86, 26);
            this.set_step_button.TabIndex = 66;
            this.set_step_button.Text = "set";
            this.set_step_button.UseVisualStyleBackColor = true;
            this.set_step_button.Click += new System.EventHandler(this.set_step_button_Click);
            // 
            // calibrate
            // 
            this.calibrate.Enabled = false;
            this.calibrate.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.calibrate.Location = new System.Drawing.Point(561, 28);
            this.calibrate.Name = "calibrate";
            this.calibrate.Size = new System.Drawing.Size(89, 26);
            this.calibrate.TabIndex = 65;
            this.calibrate.Text = "calibrate";
            this.calibrate.UseVisualStyleBackColor = true;
            this.calibrate.Click += new System.EventHandler(this.calibrate_Click_1);
            // 
            // base_phase_label
            // 
            this.base_phase_label.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.base_phase_label.Location = new System.Drawing.Point(133, 28);
            this.base_phase_label.Name = "base_phase_label";
            this.base_phase_label.Size = new System.Drawing.Size(100, 23);
            this.base_phase_label.TabIndex = 64;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(4, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(109, 17);
            this.label1.TabIndex = 63;
            this.label1.Text = "set base phase:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1126, 532);
            this.Controls.Add(this.gbxConnectionSetting);
            this.Controls.Add(this.gbxADC);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.gbxADC.ResumeLayout(false);
            this.gbxADC.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart)).EndInit();
            this.gbxConnectionSetting.ResumeLayout(false);
            this.gbxConnectionSetting.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numUpdate1)).EndInit();
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.Button btnRefreshPort;
        private System.Windows.Forms.Label lblPorts;
        private System.Windows.Forms.ComboBox cbxSerialPort;
        private System.IO.Ports.SerialPort MySerial;
        private System.Windows.Forms.Timer Update1_Timer;
        private System.Windows.Forms.GroupBox gbxADC;
        private System.Windows.Forms.GroupBox gbxConnectionSetting;
        private System.Windows.Forms.Label lblAnalog1;
        private System.Windows.Forms.TextBox txtAnalog1;
        private System.Windows.Forms.TextBox txtAnalog6;
        private System.Windows.Forms.TextBox txtAnalog5;
        private System.Windows.Forms.TextBox txtAnalog4;
        private System.Windows.Forms.Label lblAnalog3;
        private System.Windows.Forms.TextBox txtAnalog3;
        private System.Windows.Forms.Label lblAnalog2;
        private System.Windows.Forms.TextBox txtAnalog2;
        private System.Windows.Forms.Label lblAnalog6;
        private System.Windows.Forms.Label lblAnalog5;
        private System.Windows.Forms.Label lblAnalog4;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart;
        private System.ComponentModel.BackgroundWorker bgwchart;
        private System.Windows.Forms.RadioButton rdbAnalog1;
        private System.Windows.Forms.RadioButton rdbAnalog6;
        private System.Windows.Forms.RadioButton rdbAnalog5;
        private System.Windows.Forms.RadioButton rdbAnalog4;
        private System.Windows.Forms.RadioButton rdbAnalog3;
        private System.Windows.Forms.RadioButton rdbAnalog2;
        private System.Windows.Forms.NumericUpDown numUpdate1;
        private System.Windows.Forms.Label label19;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.Button btnUpdate1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Label phase;
        private System.Windows.Forms.Button set_step_button;
        private System.Windows.Forms.Button calibrate;
        private System.Windows.Forms.TextBox base_phase_label;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Label labelphase;

    }
}

