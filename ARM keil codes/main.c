/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */
#include <string.h>
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
void UART_transmit_word(UART_HandleTypeDef *huart,char* buffer);
void UART_receive_word(UART_HandleTypeDef *huart , char* buffer);
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
	char buffer[256];
	HAL_UART_Receive(&huart1, (uint8_t *)buffer, 1, 3 );
	if(!strcmp(buffer,">")){
		HAL_UART_Receive(&huart1, (uint8_t *)buffer, 3, 5 );
		UART_transmit_word(&huart1, buffer);
	}
  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/* USER CODE END 0 */

int main(void)
{
	int i;
	char buffer[64];
	char chert[64];
	char buffer2[64];
	char buffer3[64];
	char temp[64];
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();

  /* USER CODE BEGIN 2 */
//__HAL_UART_ENABLE_IT(&huart1,UART_IT_RXNE);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		strcpy(buffer , "\n\n\n  conn = net.createConnection(net.TCP,false) \n");
		UART_transmit_word(&huart1, buffer);
		HAL_UART_Receive(&huart1, (uint8_t *)chert, 256, 10);
		for(i=0;i<100000;i++);
		strcpy(buffer ,"\n\n\n   conn:on(\"receive\",function(conn,pl)print(pl)end) \n");
		UART_transmit_word(&huart1, buffer);
		HAL_UART_Receive(&huart1, (uint8_t *)chert, 256, 10);
		for(i=0;i<100000;i++);
		strcpy(buffer ,"\n\n\n   a = conn:connect(7778,\"192.168.43.1\") \n");
		UART_transmit_word(&huart1, buffer);
		HAL_UART_Receive(&huart1, (uint8_t *)chert, 256, 10);
		for(i=0;i<100000;i++);
		
//		strcpy(buffer , "\n\n\n   conn:send(\"admin#admin\")" );
//		UART_transmit_word(&huart1, buffer);
//		HAL_UART_Receive(&huart1, (uint8_t *)chert, 256, 10);
//		for(i=0;i<100000;i++);
		
		UART_receive_word( &huart2 ,buffer3 );
			strcpy(temp ,"" );
			strcpy(temp,"\n\n   conn:send(\"");
			strcat(temp,buffer3);
			strcat(temp,"\") \n\n");
			strcpy(buffer,temp);
			UART_transmit_word(&huart1, buffer);
			UART_receive_word( &huart1 ,buffer2 );
			for(i=0;i<10;i++);
			UART_transmit_word( &huart2 ,buffer2 );
		
		HAL_UART_Receive(&huart1, (uint8_t *)chert, 256, 10);
		
		while(1){
			for(i=0;i<10;i++);
			UART_transmit_word( &huart2 ," $$ start $$ ");
			for(i=0;i<10;i++);
			UART_receive_word( &huart1 ,buffer2 );
			for(i=0;i<100000;i++);
			UART_transmit_word(&huart2 ,buffer2 );
			for(i=0;i<100000;i++);
			
			UART_receive_word( &huart2 ,buffer3 );
			strcpy(temp ,"" );
			strcpy(temp,"\n\n   conn:send(\"");
			strcat(temp,buffer3);
			strcat(temp,"\") \n\n");
			strcpy(buffer,temp);
			UART_transmit_word(&huart1, buffer);
			UART_receive_word( &huart1 ,buffer2 );
			for(i=0;i<10;i++);
			UART_transmit_word( &huart2 ,buffer2 );
		}
		
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}


/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  __PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USART1 init function */
void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart1);

}

/* USART2 init function */
void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart2);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __GPIOH_CLK_ENABLE();
  __GPIOA_CLK_ENABLE();
  __GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
void UART_transmit_word(UART_HandleTypeDef *huart,char* buffer){
	int length;
	length = strlen(buffer);
	HAL_UART_Transmit(huart, (uint8_t *)buffer, length, 50);
}

void UART_receive_word(UART_HandleTypeDef *huart ,char* buffer ){
	while(1){
				strcpy(buffer ,"" );
				HAL_UART_Receive(huart, (uint8_t *)buffer, 64, 20);
				if( strlen(buffer) > 0 )
					break;
	}
}
/* USER CODE END 4 */

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
