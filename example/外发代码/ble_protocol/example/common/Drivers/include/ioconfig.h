
/*****************************************************************************
*   ioconfig.h:  Header file for io function selection
*		ver 3.0
******************************************************************************/
#define	IOCONFIG_ENABLE			0x1  						//Enable Select function
#define	IOCONFIG_DISABLE		0x0							//Disable Select function

#define	PA_0_GPIO						0x2B0	  				//Select function PA_0
#define	PA_0_ADC0						0x1102					//Select function ADC0
			
#define	PA_1_GPIO						0x2B0	   				//Select function PA_1 
#define	PA_1_ADC1						0x1102					//Select function ADC1 
			
#define	PA_2_GPIO						0x2B0	         	//Select function PA_2
#define	PA_2_TIM7_CAP0			0x2B1						//Select function TIM7_CAP0
#define	PA_2_TIM7_MAT0			0x2B2						//Select function TIM7_MAT0
#define	PA_2_TX0						0x2B3	        	//Select function TX0
#define	PA_2_ADC2						0x1105	        //Select function ADC2
			
#define	PA_3_GPIO						0x2B0	          //Select function PA_3  
#define	PA_3_TIM7_CAP1			0x2B1	  				//Select function TIM7_CAP1
#define	PA_3_TIM7_MAT1			0x2B2						//Select function TIM7_MAT1 
#define	PA_3_RX0 						0x2B3	        	//Select function RX0 
#define	PA_3_ADC3						0x1105	        //Select function ADC3
			
#define	PA_4_GPIO						0x2B0	         	//Select function PA_4 
#define	PA_4_TIM7_CAP2			0x2B1						//Select function TIM7_CAP2
#define	PA_4_TIM7_MAT2			0x2B2						//Select function TIM7_MAT2
#define	PA_4_SPI_SSEL				0x2B3 					//Select function SPI_SSEL
#define	PA_4_ADC4						0x1104 	        //Select function ADC4 
			
#define	PA_5_GPIO						0x2B0	          //Select function PA_5 
#define	PA_5_SPI_SCK				0x2B1	        	//Select function SPI_SCK
#define	PA_5_ADC5						0x1102	        //Select function ADC5
			
#define	PA_6_GPIO						0x2B0	          //Select function PA_6
#define	PA_6_PWM_FAULT			0x2B1      			//Select function PWM_FAULT
#define	PA_6_TIM6_CAP0			0x2B2	    			//Select function TIM6_CAP0
#define	PA_6_TIM6_MAT0			0x2B3 	  			//Select function TIM6_MAT0
#define	PA_6_SPI_MISO				0x2B4	        	//Select function SPI_MISO
#define	PA_6_ADC6						0x1105	        //Select function ADC6
			
#define	PA_7_GPIO						0x2B0 	         //Select function PA_7
#define	PA_7_PWM1						0x2B1 	    		//Select function PWM1
#define	PA_7_TIM6_CAP1			0x2B2 	  			//Select function TIM6_CAP1
#define	PA_7_TIM6_MAT1			0x2B3	    			//Select function TIM6_MAT1
#define	PA_7_SPI_MOSI				0x2B4	        	//Select function SPI_MOSI
#define	PA_7_ADC7						0x1106	        //Select function ADC7
			
#define	PA_8_GPIO						0x2B0	          //Select function PA_8
#define	PA_8_PWM0						0x2B1	        	//Select function PWM0
#define	PA_8_TIM7_CAP3			0x2B2	      		//Select function TIM7_CAP3
#define	PA_8_TIM7_MAT3			0x2B3 	   			//Select function TIM7_MAT3
#define	PA_8_TOUCH1					0x1104					//Select function TOUCH1
#define	PA_8_LCD_SEG4				0x1104					//Select function LCD_SEG4
#define	PA_8_LED_SEG4				0x2B5						//Select function LED_SEG4

#define	PA_9_GPIO						0x2B0 	           //Select function PA_9. 
#define	PA_9_PWM2						0x2B1 	        //Select function PWM2
#define	PA_9_TX0						0x2B2	             //Select function TX0
#define	PA_9_I2C_SCL				0x2B4	        	//Select function I2C_SCL
#define	PA_9_LCD_SEG5				0x1105					//Select function LCD_SEG5
#define	PA_9_TOUCH2					0x1105					//Select function TOUCH2
#define	PA_9_LED_SEG5				0x2B6						//Select function LED_SEG5
			
#define	PA_10_GPIO					0x2B0 	      	//Select function PA_10 
#define	PA_10_PWM4					0x2B1    				//Select function PWM4
#define	PA_10_RX0						0x2B2	        	//Select function RX0
#define	PA_10_I2C_SDA				0x2B4	        	//Select function I2C_SDA
#define	PA_10_LCD_SEG6			0x1105					//Select function LCD_SEG6/TOUCH3
#define	PA_10_TOUCH3				0x1105					//Select function LCD_SEG6/TOUCH3
#define	PA_10_LED_SEG6			0x2B6						//Select function LED_SEG6
			
#define	PA_11_GPIO					0x2B0	          //Select function PA_11 
#define	PA_11_TIM6_CAP2			0x2B2	    			//Select function TIM6_CAP2
#define	PA_11_TIM6_MAT2			0x2B3	    			//Select function TIM6_MAT2
#define	PA_11_LCD_SEG7			0x1104					//Select function LCD_SEG7/TOUCH4
#define	PA_11_TOUCH4				0x1104					//Select function LCD_SEG7/TOUCH4
#define	PA_11_LED_SEG7			0x2B5						//Select function LED_SEG7
			
#define	PA_12_GPIO					0x2B0	          //Select function PA_12 
#define	PA_12_LCD_SEG8			0x1102					//Select function LCD_SEG8/TOUCH5
#define	PA_12_TOUCH5				0x1102					//Select function LCD_SEG8/TOUCH5
#define	PA_12_LED_COM6			0x2B3						//Select function LCD_SEG8

#define	PA_13_SWDIO					0x2B0	         	//Select function SWDIO 
#define	PA_13_GPIO					0x2B1	         	//Select function PA_13 
#define	PA_13_LCD_SEG9			0x1102					//Select function LCD_SEG9/TOUCH6
#define	PA_13_TOUCH6				0x1102					//Select function LCD_SEG9/TOUCH6

#define	PA_14_SWDCLK 				0x2B0						//Select function SWDCLK 
#define	PA_14_GPIO					0x2B1	  				//Select function PA_14
#define	PA_14_TX1						0x2B2	  				//Select function TX1 
#define	PA_14_TOUCH9				0x1103					//Select function TOUCH9
#define	PA_14_TIM6_CAP0			0x2B4			

#define	PA_15_GPIO					0x2B0	         	//Select function PA_15
#define	PA_15_SPI_SSEL			0x2B1	     			//Select function SPI_SSEL
#define	PA_15_RX1						0x2B2 	       	//Select function RX1 
#define	PA_15_TOUCH15				0x1103	     		//Select function TOUCH15
			
#define	PB_0_GPIO						0x2B0	          //Select function PB_0
#define	PB_0_PWM3						0x2B1	        	//Select function PWM3
#define	PB_0_TIM6_CAP2			0x2B2 	  			//Select function TIM6_CAP2 
#define	PB_0_TIM6_MAT2			0x2B3	    			//Select function TIM6_MAT2
#define	PB_0_LCD_SEG12			0x1104	        //Select function LCD SEG12
#define	PB_0_TOUCH18				0x1104	        //Select function TOUCH18

			
#define	PB_1_GPIO						0x2B0	          //Select function PB_1
#define	PB_1_PWM5						0x2B1	        	//Select function PWM5
#define	PB_1_TIM6_CAP3 			0x2B2	   				//Select function TIM6_CAP3 
#define	PB_1_TIM6_MAT3			0x2B3	    			//Select function TIM6_MAT3
#define	PB_1_LCD_SEG13			0x1104	        //Select function LCD SEG13
#define	PB_1_TOUCH19				0x1104	        //Select function TOUCH19

#define	PB_2_GPIO						0x2B0 	   			//Select function PB_2
#define	PB_2_LED_COM0				0x2B2						//Select function LED_COM0
#define	PB_2_LCD_COM0				0x1103					//Select function LCD_COM0
			
#define	PB_3_GPIO						0x2B0	     			//Select function PB_3 
#define	PB_3_SPI_SCK				0x2B1						//Select function SPI_SCK 
#define	PB_3_TOUCH16				0x1102					//Select function TOUCH16
			
#define	PB_4_GPIO						0x2B0	          //Select function PB_4 
#define	PB_4_SPI_MISO				0x2B1 	        //Select function SPI_MISO
#define	PB_4_TIM6_CAP0 			0x2B2 	    		//Select function TIM6_CAP0 
#define	PB_4_TIM6_MAT0			0x2B3	      		//Select function TIM6_MAT0
#define	PB_4_TOUCH10				0x1104	        //Select function TOUCH10
			
#define	PB_5_GPIO						0x2B0	          //Select function PB_5 
#define	PB_5_SPI_MOSI				0x2B1 	        //Select function SPI_MOSI 
#define	PB_5_TIM6_CAP1 			0x2B2	      		//Select function TIM6_CAP1 
#define	PB_5_TIM6_MAT1			0x2B3	      		//Select function TIM6_MAT1
#define	PB_5_TOUCH11				0x1104 	        //Select function TOUCH11
			
#define	PB_6_GPIO						0x2B0	          //Select function PB_6
#define	PB_6_I2C_SCL				0x2B1	        	//Select function I2C_SCL
#define	PB_6_TX1						0x2B2	          //Select function TX1
#define	PB_6_TIM7_CAP0 			0x2B4	    			//Select function TIM7_CAP0 
#define	PB_6_TIM7_MAT0			0x2B5	    			//Select function TIM7_MAT0
#define	PB_6_LCD_COM3				0x1106	      	//Select function LCD_COM3
#define	PB_6_LED_COM3				0x2B7	      		//Select function LED_COM3
			
#define	PB_7_GPIO						0x2B0	          //Select function PB_7 
#define	PB_7_I2C_SDA				0x2B1	          //Select function I2C_SDA 
#define	PB_7_RX1						0x2B2	          //Select function RX1
#define	PB_7_TIM7_CAP1 			0x2B4	        	//Select function TIM7_CAP1 
#define	PB_7_TIM7_MAT1			0x2B5	        	//Select function TIM7_MAT1
#define	PB_7_LCD_COM4				0x1106 					//Select function LCD_COM4/TOUCH21
#define	PB_7_TOUCH21				0x1106 					//Select function LCD_COM4/TOUCH21
#define	PB_7_LED_COM4				0x2B7	      		//Select function LED_COM4

#define	PB_8_GPIO						0x2B0	          //Select function PB_8
#define	PB_8_I2C_SCL				0x2B1	          //Select function I2C_SCL 
#define	PB_8_TIM7_CAP2 			0x2B2	        	//Select function TIM7_CAP2 
#define	PB_8_TIM7_MAT2			0x2B3	        	//Select function TIM7_MAT2
#define	PB_8_TOUCH13				0x1104					//Select function TOUCH13/ LCD_SEG14
#define	PB_8_LCD_SEG14			0x1104					//Select function TOUCH13/ LCD_SEG14

#define	PB_9_GPIO						0x2B0	          //Select function PB_9 
#define	PB_9_I2C_SDA				0x2B1 	        //Select function I2C_SDA 
#define	PB_9_LCD_SEG15			0x1103					//Select function LCD_SEG15/TOUCH14
#define	PB_9_TOUCH14				0x1103					//Select function LCD_SEG15/TOUCH14
			
#define	PB_10_GPIO					0x2B0	     			//Select function PB_10 
#define	PB_10_I2C_SCL				0x2B1 	 				//Select function I2C_SCL
#define	PB_10_LED_COM1			0x2B2						//Select function LED_COM1
#define	PB_10_LCD_COM1			0x1103					//Select function LCD_COM1
			
#define	PB_11_GPIO					0x2B0	    			//Select function PB_11 
#define	PB_11_I2C_SDA				0x2B1	  				//Select function I2C_SDA
#define	PB_11_LED_COM2			0x2B2						//Select function LED_SEG2
#define	PB_11_LCD_COM2			0x1103					//Select function LCD_COM2
			
#define	PB_12_GPIO					0x2B0	    			//Select function PB_12 
#define	PB_12_SPI_SSEL 			0x2B1						//Select function SPI_SSEL 
#define	PB_12_PWM_FAULT			0x2B2						//Select function PWM Fault
#define	PB_12_LED_SEG0			0x2B3						//Select function LED_SEG0
#define	PB_12_LCD_SEG0			0x1104					//Select function LCD_SEG0
			
#define	PB_13_GPIO					0x2B0 	  			//Select function PB_13
#define	PB_13_SPI_SCK				0x2B1	  				//Select function SPI_SCK
#define	PB_13_PWM1					0x2B2						//Select function PWM1
#define	PB_13_LED_SEG1			0x2B3						//Select function LED_SEG1
#define	PB_13_LCD_SEG1			0x1104					//Select function LCD_SEG1
			
#define	PB_14_GPIO					0x2B0	          //Select function PB_14 
#define	PB_14_SPI_MISO			0x2B1	      		//Select function SPI_MISO
#define	PB_14_TIM6_CAP3 		0x2B2	  				//Select function TIM6_CAP3 
#define	PB_14_TIM6_MAT3			0x2B3	    			//Select function TIM6_MAT3
#define	PB_14_PWM3					0x2B4	      		//Select function PWM3
#define	PB_14_LED_SEG2			0x2B5     			//Select function LED_SEG2
#define	PB_14_LCD_SEG2			0x1106	      	//Select function LCD_SEG2
			
#define	PB_15_GPIO					0x2B0 	        //Select function PB_15 
#define	PB_15_SPI_MOSI			0x2B1	      		//Select function SPI_MOSI 
#define	PB_15_TIM7_CAP3 		0x2B2	  				//Select function TIM7_CAP3 
#define	PB_15_TIM7_MAT3			0x2B3	    			//Select function TIM7_MAT3
#define	PB_15_PWM5					0x2B4	      		//Select function PWM5
#define	PB_15_LCD_SEG3			0x1105					//Select function LCD_SEG3/TOUCH2
#define	PB_15_TOUCH0				0x1105					//Select function LCD_SEG3/TOUCH2
#define	PB_15_LED_SEG3			0x2B6						//Select function LED_SEG3

#define	PC_0_GPIO						0x2B0	          //Select function PC_0

#define	PC_1_GPIO						0x2B0	          //Select function PC_1

#define	PC_2_GPIO						0x2B0	          //Select function PC_2
#define	PC_2_ADC10					0x1101	        //Select function ADC10

#define	PC_3_GPIO						0x2B0	          //Select function PC_3
#define	PC_3_ADC11					0x1101	        //Select function ADC11

#define	PC_4_GPIO						0x2B0	          //Select function PC_4
#define	PC_4_PWM6						0x2B1	          //Select function PWM6

#define	PC_5_GPIO						0x2B0	          //Select function PC_5
#define	PC_5_PWM7						0x2B1	          //Select function PWM7

#define	PC_6_GPIO						0x2B0	          //Select function PC_6
#define	PC_6_PWM0						0x2B1	         	//Select function PWM0
#define	PC_6_TIM7_CAP0 			0x2B2	  				//Select function TIM7_CAP0 
#define	PC_6_TIM7_MAT0			0x2B3	    			//Select function TIM7_MAT0

#define	PC_7_GPIO						0x2B0	          //Select function PC_7
			
#define	PC_8_GPIO						0x2B0	          //Select function PC_8 
#define	PC_8_CLKOUT					0x2B1	          //Select function PC_8 

#define	PC_9_NRST						0x2B0	          //Select function NRST
#define	PC_9_GPIO						0x2B1 	        //Select function PC_9 
			
#define	PC_10_GPIO					0x2B0	          //Select function PC_10 
#define	PC_10_I2C_SCL				0x2B2	          //Select function I2C_SCL
#define	PC_10_LCD_SEG10			0x1104					//Select function LCD_SEG10
#define	PC_10_TOUCH7				0x1104					//Select function TOUCH7
#define	PC_10_LED_COM7			0x2B5						//Select function LED_COM7

#define	PC_11_GPIO					0x2B0 	        //Select function PC_11 
#define	PC_11_I2C_SDA				0x2B1	          //Select function I2C_SDA
#define	PC_11_LCD_SEG11			0x1102					//Select function LCD_SEG11
#define	PC_11_TOUCH8				0x1102					//Select function TOUCH8
			
#define	PC_12_GPIO					0x2B1 	        //Select function PC_12
#define	PC_12_LCD_COM5			0x1102					//Select function LCD_COM5 
#define	PC_12_TOUCH12				0x1102					//Select function TOUCH12 
#define	PC_12_LED_COM5			0x2B3						//Select function LED_COM5 

#define	PC_13_GPIO					0x2B0	   				//Select function PC_13
#define	PC_13_CLKOUT				0x2B1	          //Select function CLKOUT		

#define	PC_14_GPIO					0x2B0           //Select function PC_14 
			
#define	PC_15_GPIO					0x2B0	          // Select function PC_15 


#define	PD_0_GPIO						0x2B0	          //Select function PD_0
#define	PD_0_PWM2						0x2B1	          //Select function PWM2
#define	PD_0_TIM7_CAP2 			0x2B2	  				//Select function TIM7_CAP2 
#define	PD_0_TIM7_MAT2			0x2B3	    			//Select function TIM7_MAT2

#define	PD_1_GPIO						0x2B0	          //Select function PD_1
#define	PD_1_PWM3						0x2B1	          //Select function PWM3
#define	PD_1_TIM7_CAP3 			0x2B2	  				//Select function TIM7_CAP3 
#define	PD_1_TIM7_MAT3			0x2B3	    			//Select function TIM7_MAT3

#define	PD_2_GPIO						0x2B0	          //Select function PD_2
#define	PD_2_PWM6						0x2B1	          //Select function PWM6
#define	PD_2_TIM6_CAP2 			0x2B2	  				//Select function TIM6_CAP2 
#define	PD_2_TIM6_MAT2			0x2B3	    			//Select function TIM6_MAT2
#define	PD_2_TOUCH_IN				0x1104					//Select function TOUCH_IN
#define	PD_2_SPI_MOSI				0x2B5	  				//Select function SPI_MOSI


#define	PD_3_GPIO						0x2B0	           //Select function PD_3
#define	PD_3_PWM7						0x2B1	           //Select function PWM7
#define	PD_3_TIM6_CAP3 			0x2B2	  				 //Select function TIM6_CAP3 
#define	PD_3_TIM6_MAT3			0x2B3	    			 //Select function TIM6_MAT3
#define	PD_3_TOUCH_IN				0x1104					 //Select function TOUCH_IN
#define	PD_3_SPI_MISO				0x2B5	 					 //Select function SPI_MISO

#define	PD_4_GPIO						0x2B0            //Select function PD_4
#define	PD_4_ADC8						0x1101	               //Select function ADC8

#define	PD_5_GPIO						0x2B0	           //Select function PD_5
#define	PD_5_ADC9						0x1101	         //Select function ADC9

#define	PD_6_GPIO						0x2B0	           //Select function PD_6
#define	PD_6_PWM4						0x2B1	       		 //Select function PWM4
#define	PD_6_TIM6_CAP0 			0x2B2	  				 //Select function TIM6_CAP0 
#define	PD_6_TIM6_MAT0			0x2B3	    			 //Select function TIM6_MAT0
#define	PD_6_TOUCH17				0x1104					 //Select function TOUCH17
#define	PD_6_SPI_SCK				0x2B5	  				 //Select function SPI_SCK

#define	PD_7_GPIO						0x2B0	           //Select function PD_7
#define	PD_7_PWM5						0x2B1	           //Select function PWM4
#define	PD_7_TIM6_CAP1 			0x2B2	  				 //Select function TIM6_CAP1 
#define	PD_7_TIM6_MAT1			0x2B3	    			 //Select function TIM6_MAT1
#define	PD_7_TOUCH20				0x1104					 //Select function TOUCH20
#define	PD_7_SPI_MISO				0x2B5	  				 //Select function SPI_MISO

#define	PD_8_GPIO						0x2B0	           //Select function PD_8 
#define	PD_8_PWM1						0x2B1	           //Select function PWM1
#define	PD_8_TIM7_CAP1 			0x2B2	  				 //Select function TIM7_CAP0 
#define	PD_8_TIM7_MAT1			0x2B3	    			 //Select function TIM7_MAT0

//PA IO PINs
#define  PA_0_INIT(PA_0_function)						IOCON->PA_0 = PA_0_function
#define  PA_0_PULLUP(enable)								IOCON->PA_0_b.PUE = enable
#define  PA_0_PULLDOWN(enable)							IOCON->PA_0_b.PDE = enable
#define  PA_0_IOFilter(enable)							IOCON->PA_0_b.S_MODE = enable
#define  PA_1_INIT(PA_1_function) 					IOCON->PA_1 = PA_1_function
#define  PA_1_PULLUP(enable)								IOCON->PA_1_b.PUE = enable
#define  PA_1_PULLDOWN(enable)							IOCON->PA_1_b.PDE = enable
#define  PA_1_IOFilter(enable)							IOCON->PA_1_b.S_MODE = enable
#define  PA_2_INIT(PA_2_function) 					IOCON->PA_2 = PA_2_function
#define  PA_2_PULLUP(enable)								IOCON->PA_2_b.PUE = enable
#define  PA_2_PULLDOWN(enable)							IOCON->PA_2_b.PDE = enable
#define  PA_2_IOFilter(enable)							IOCON->PA_2_b.S_MODE = enable
#define  PA_3_INIT(PA_3_function) 					IOCON->PA_3 = PA_3_function
#define  PA_3_PULLUP(enable)								IOCON->PA_3_b.PUE = enable
#define  PA_3_PULLDOWN(enable)							IOCON->PA_3_b.PDE = enable
#define  PA_3_IOFilter(enable)							IOCON->PA_3_b.S_MODE = enable
#define  PA_4_INIT(PA_4_function) 					IOCON->PA_4 = PA_4_function
#define  PA_4_PULLUP(enable)								IOCON->PA_4_b.PUE = enable
#define  PA_4_PULLDOWN(enable)							IOCON->PA_4_b.PDE = enable
#define  PA_4_IOFilter(enable)							IOCON->PA_4_b.S_MODE = enable
#define  PA_5_INIT(PA_5_function) 					IOCON->PA_5 = PA_5_function
#define  PA_5_PULLUP(enable)								IOCON->PA_5_b.PUE = enable
#define  PA_5_PULLDOWN(enable)							IOCON->PA_5_b.PDE = enable
#define  PA_5_IOFilter(enable)							IOCON->PA_5_b.S_MODE = enable
#define  PA_6_INIT(PA_6_function) 					IOCON->PA_6 = PA_6_function
#define  PA_6_PULLUP(enable)								IOCON->PA_6_b.PUE = enable
#define  PA_6_PULLDOWN(enable)							IOCON->PA_6_b.PDE = enable
#define  PA_6_IOFilter(enable)							IOCON->PA_6_b.S_MODE = enable
#define  PA_7_INIT(PA_7_function) 					IOCON->PA_7 = PA_7_function
#define  PA_7_PULLUP(enable)								IOCON->PA_7_b.PUE = enable
#define  PA_7_PULLDOWN(enable)							IOCON->PA_7_b.PDE = enable
#define  PA_7_IOFilter(enable)							IOCON->PA_7_b.S_MODE = enable
#define  PA_8_INIT(PA_8_function) 					IOCON->PA_8 = PA_8_function
#define  PA_8_PULLUP(enable)								IOCON->PA_8_b.PUE = enable
#define  PA_8_PULLDOWN(enable)							IOCON->PA_8_b.PDE = enable
#define  PA_8_IOFilter(enable)							IOCON->PA_8_b.S_MODE = enable
#define  PA_9_INIT(PA_9_function) 					IOCON->PA_9 = PA_9_function
#define  PA_9_PULLUP(enable)								IOCON->PA_9_b.PUE = enable
#define  PA_9_PULLDOWN(enable)							IOCON->PA_9_b.PDE = enable
#define  PA_9_IOFilter(enable)							IOCON->PA_9_b.S_MODE = enable
#define  PA_10_INIT(PA_10_function) 				IOCON->PA_10 = PA_10_function
#define  PA_10_PULLUP(enable)								IOCON->PA_10_b.PUE = enable
#define  PA_10_PULLDOWN(enable)							IOCON->PA_10_b.PDE = enable
#define  PA_10_IOFilter(enable)							IOCON->PA_10_b.S_MODE = enable
#define  PA_11_INIT(PA_11_function) 				IOCON->PA_11 = PA_11_function
#define  PA_11_PULLUP(enable)								IOCON->PA_11_b.PUE = enable
#define  PA_11_PULLDOWN(enable)							IOCON->PA_11_b.PDE = enable
#define  PA_11_IOFilter(enable)							IOCON->PA_11_b.S_MODE = enable
#define  PA_12_INIT(PA_12_function) 				IOCON->PA_12 = PA_12_function
#define  PA_12_PULLUP(enable)								IOCON->PA_12_b.PUE = enable
#define  PA_12_PULLDOWN(enable)							IOCON->PA_12_b.PDE = enable
#define  PA_12_IOFilter(enable)							IOCON->PA_12_b.S_MODE = enable
#define  PA_13_INIT(PA_13_function) 				IOCON->PA_13 = PA_13_function
#define  PA_13_PULLUP(enable)								IOCON->PA_13_b.PUE = enable
#define  PA_13_PULLDOWN(enable)							IOCON->PA_13_b.PDE = enable
#define  PA_13_IOFilter(enable)							IOCON->PA_13_b.S_MODE = enable
#define  PA_14_INIT(PA_14_function) 				IOCON->PA_14 = PA_14_function
#define  PA_14_PULLUP(enable)								IOCON->PA_14_b.PUE = enable
#define  PA_14_PULLDOWN(enable)							IOCON->PA_14_b.PDE = enable
#define  PA_14_IOFilter(enable)							IOCON->PA_14_b.S_MODE = enable
#define  PA_15_INIT(PA_15_function) 				IOCON->PA_15 = PA_15_function
#define  PA_15_PULLUP(enable)								IOCON->PA_15_b.PUE = enable
#define  PA_15_PULLDOWN(enable)							IOCON->PA_15_b.PDE = enable
#define  PA_15_IOFilter(enable)							IOCON->PA_15_b.S_MODE = enable
//PB IO PINs
#define  PB_0_INIT(PB_0_function) 					IOCON->PB_0 = PB_0_function
#define  PB_0_PULLUP(enable)								IOCON->PB_0_b.PUE = enable
#define  PB_0_PULLDOWN(enable)							IOCON->PB_0_b.PDE = enable
#define  PB_0_IOFilter(enable)							IOCON->PB_0_b.S_MODE = enable
#define  PB_1_INIT(PB_1_function) 					IOCON->PB_1 = PB_1_function
#define  PB_1_PULLUP(enable)								IOCON->PB_1_b.PUE = enable
#define  PB_1_PULLDOWN(enable)							IOCON->PB_1_b.PDE = enable
#define  PB_1_IOFilter(enable)							IOCON->PB_1_b.S_MODE = enable
#define  PB_2_INIT(PB_2_function) 					IOCON->PB_2 = PB_2_function
#define  PB_2_PULLUP(enable)								IOCON->PB_2_b.PUE = enable
#define  PB_2_PULLDOWN(enable)							IOCON->PB_2_b.PDE = enable
#define  PB_2_IOFilter(enable)							IOCON->PB_2_b.S_MODE = enable
#define  PB_3_INIT(PB_3_function) 					IOCON->PB_3 = PB_3_function
#define  PB_3_PULLUP(enable)								IOCON->PB_3_b.PUE = enable
#define  PB_3_PULLDOWN(enable)							IOCON->PB_3_b.PDE = enable
#define  PB_3_IOFilter(enable)							IOCON->PB_3_b.S_MODE = enable
#define  PB_4_INIT(PB_4_function) 					IOCON->PB_4 = PB_4_function
#define  PB_4_PULLUP(enable)								IOCON->PB_4_b.PUE = enable
#define  PB_4_PULLDOWN(enable)							IOCON->PB_4_b.PDE = enable
#define  PB_4_IOFilter(enable)							IOCON->PB_4_b.S_MODE = enable
#define  PB_5_INIT(PB_5_function) 					IOCON->PB_5 = PB_5_function
#define  PB_5_PULLUP(enable)								IOCON->PB_5_b.PUE = enable
#define  PB_5_PULLDOWN(enable)							IOCON->PB_5_b.PDE = enable
#define  PB_5_IOFilter(enable)							IOCON->PB_5_b.S_MODE = enable
#define  PB_6_INIT(PB_6_function) 					IOCON->PB_6 = PB_6_function
#define  PB_6_PULLUP(enable)								IOCON->PB_6_b.PUE = enable
#define  PB_6_PULLDOWN(enable)							IOCON->PB_6_b.PDE = enable
#define  PB_6_IOFilter(enable)							IOCON->PB_6_b.S_MODE = enable
#define  PB_7_INIT(PB_7_function) 					IOCON->PB_7 = PB_7_function
#define  PB_7_PULLUP(enable)								IOCON->PB_7_b.PUE = enable
#define  PB_7_PULLDOWN(enable)							IOCON->PB_7_b.PDE = enable
#define  PB_7_IOFilter(enable)							IOCON->PB_7_b.S_MODE = enable
#define  PB_8_INIT(PB_8_function) 					IOCON->PB_8 = PB_8_function
#define  PB_8_PULLUP(enable)								IOCON->PB_8_b.PUE = enable
#define  PB_8_PULLDOWN(enable)							IOCON->PB_8_b.PDE = enable
#define  PB_8_IOFilter(enable)							IOCON->PB_8_b.S_MODE = enable
#define  PB_9_INIT(PB_9_function) 					IOCON->PB_9 = PB_9_function
#define  PB_9_PULLUP(enable)								IOCON->PB_9_b.PUE = enable
#define  PB_9_PULLDOWN(enable)							IOCON->PB_9_b.PDE = enable
#define  PB_9_IOFilter(enable)							IOCON->PB_9_b.S_MODE = enable
#define  PB_10_INIT(PB_10_function) 				IOCON->PB_10 = PB_10_function
#define  PB_10_PULLUP(enable)								IOCON->PB_10_b.PUE = enable
#define  PB_10_PULLDOWN(enable)							IOCON->PB_10_b.PDE = enable
#define  PB_10_IOFilter(enable)							IOCON->PB_10_b.S_MODE = enable
#define  PB_11_INIT(PB_11_function) 				IOCON->PB_11 = PB_11_function
#define  PB_11_PULLUP(enable)								IOCON->PB_11_b.PUE = enable
#define  PB_11_PULLDOWN(enable)							IOCON->PB_11_b.PDE = enable
#define  PB_11_IOFilter(enable)							IOCON->PB_11_b.S_MODE = enable
#define  PB_12_INIT(PB_12_function) 				IOCON->PB_12 = PB_12_function
#define  PB_12_PULLUP(enable)								IOCON->PB_12_b.PUE = enable
#define  PB_12_PULLDOWN(enable)							IOCON->PB_12_b.PDE = enable
#define  PB_12_IOFilter(enable)							IOCON->PB_12_b.S_MODE = enable
#define  PB_13_INIT(PB_13_function) 				IOCON->PB_13 = PB_13_function
#define  PB_13_PULLUP(enable)								IOCON->PB_13_b.PUE = enable
#define  PB_13_PULLDOWN(enable)							IOCON->PB_13_b.PDE = enable
#define  PB_13_IOFilter(enable)							IOCON->PB_13_b.S_MODE = enable
#define  PB_14_INIT(PB_14_function) 				IOCON->PB_14 = PB_14_function
#define  PB_14_PULLUP(enable)								IOCON->PB_14_b.PUE = enable
#define  PB_14_PULLDOWN(enable)							IOCON->PB_14_b.PDE = enable
#define  PB_14_IOFilter(enable)							IOCON->PB_14_b.S_MODE = enable
#define  PB_15_INIT(PB_15_function) 				IOCON->PB_15 = PB_15_function
#define  PB_15_PULLUP(enable)								IOCON->PB_15_b.PUE = enable
#define  PB_15_PULLDOWN(enable)							IOCON->PB_15_b.PDE = enable
#define  PB_15_IOFilter(enable)							IOCON->PB_15_b.S_MODE = enable
//PC IO PINs
#define  PC_0_INIT(PC_0_function) 					IOCON->PC_0 = PC_0_function
#define  PC_0_PULLUP(enable)								IOCON->PC_0_b.PUE = enable
#define  PC_0_PULLDOWN(enable)							IOCON->PC_0_b.PDE = enable
#define  PC_0_IOFilter(enable)							IOCON->PC_0_b.S_MODE = enable
#define  PC_1_INIT(PC_1_function) 					IOCON->PC_1 = PC_1_function
#define  PC_1_PULLUP(enable)								IOCON->PC_1_b.PUE = enable
#define  PC_1_PULLDOWN(enable)							IOCON->PC_1_b.PDE = enable
#define  PC_1_IOFilter(enable)							IOCON->PC_1_b.S_MODE = enable
#define  PC_2_INIT(PC_2_function) 					IOCON->PC_2 = PC_2_function
#define  PC_2_PULLUP(enable)								IOCON->PC_2_b.PUE = enable
#define  PC_2_PULLDOWN(enable)							IOCON->PC_2_b.PDE = enable
#define  PC_2_IOFilter(enable)							IOCON->PC_2_b.S_MODE = enable
#define  PC_3_INIT(PC_3_function) 					IOCON->PC_3 = PC_3_function
#define  PC_3_PULLUP(enable)								IOCON->PC_3_b.PUE = enable
#define  PC_3_PULLDOWN(enable)							IOCON->PC_3_b.PDE = enable
#define  PC_3_IOFilter(enable)							IOCON->PC_3_b.S_MODE = enable
#define  PC_4_INIT(PC_4_function) 					IOCON->PC_4 = PC_4_function
#define  PC_4_PULLUP(enable)								IOCON->PC_4_b.PUE = enable
#define  PC_4_PULLDOWN(enable)							IOCON->PC_4_b.PDE = enable
#define  PC_4_IOFilter(enable)							IOCON->PC_4_b.S_MODE = enable
#define  PC_5_INIT(PC_5_function) 					IOCON->PC_5 = PC_5_function
#define  PC_5_PULLUP(enable)								IOCON->PC_5_b.PUE = enable
#define  PC_5_PULLDOWN(enable)							IOCON->PC_5_b.PDE = enable
#define  PC_5_IOFilter(enable)							IOCON->PC_5_b.S_MODE = enable
#define  PC_6_INIT(PC_6_function) 					IOCON->PC_6 = PC_6_function
#define  PC_6_PULLUP(enable)								IOCON->PC_6_b.PUE = enable
#define  PC_6_PULLDOWN(enable)							IOCON->PC_6_b.PDE = enable
#define  PC_6_IOFilter(enable)							IOCON->PC_6_b.S_MODE = enable
#define  PC_7_INIT(PC_7_function) 					IOCON->PC_7 = PC_7_function
#define  PC_7_PULLUP(enable)								IOCON->PC_7_b.PUE = enable
#define  PC_7_PULLDOWN(enable)							IOCON->PC_7_b.PDE = enable
#define  PC_7_IOFilter(enable)							IOCON->PC_7_b.S_MODE = enable
#define  PC_8_INIT(PC_8_function) 					IOCON->PC_8 = PC_8_function
#define  PC_8_PULLUP(enable)								IOCON->PC_8_b.PUE = enable
#define  PC_8_PULLDOWN(enable)							IOCON->PC_8_b.PDE = enable
#define  PC_8_IOFilter(enable)							IOCON->PC_8_b.S_MODE = enable
#define  PC_9_INIT(PC_9_function) 					IOCON->PC_9 = PC_9_function
#define  PC_9_PULLUP(enable)								IOCON->PC_9_b.PUE = enable
#define  PC_9_PULLDOWN(enable)							IOCON->PC_9_b.PDE = enable
#define  PC_9_IOFilter(enable)							IOCON->PC_9_b.S_MODE = enable
#define  PC_10_INIT(PC_10_function) 				IOCON->PC_10 = PC_10_function
#define  PC_10_PULLUP(enable)								IOCON->PC_10_b.PUE = enable
#define  PC_10_PULLDOWN(enable)							IOCON->PC_10_b.PDE = enable
#define  PC_10_IOFilter(enable)							IOCON->PC_10_b.S_MODE = enable
#define  PC_11_INIT(PC_11_function) 				IOCON->PC_11 = PC_11_function
#define  PC_11_PULLUP(enable)								IOCON->PC_11_b.PUE = enable
#define  PC_11_PULLDOWN(enable)							IOCON->PC_11_b.PDE = enable
#define  PC_11_IOFilter(enable)							IOCON->PC_11_b.S_MODE = enable
#define  PC_12_INIT(PC_12_function) 				IOCON->PC_12 = PC_12_function
#define  PC_12_PULLUP(enable)								IOCON->PC_12_b.PUE = enable
#define  PC_12_PULLDOWN(enable)							IOCON->PC_12_b.PDE = enable
#define  PC_12_IOFilter(enable)							IOCON->PC_12_b.S_MODE = enable
#define  PC_13_INIT(PC_13_function) 				IOCON->PC_13 = PC_13_function
#define  PC_13_PULLUP(enable)								IOCON->PC_13_b.PUE = enable
#define  PC_13_PULLDOWN(enable)							IOCON->PC_13_b.PDE = enable
#define  PC_13_IOFilter(enable)							IOCON->PC_13_b.S_MODE = enable
#define  PC_14_INIT(PC_14_function) 				IOCON->PC_14 = PC_14_function
#define  PC_14_PULLUP(enable)								IOCON->PC_14_b.PUE = enable
#define  PC_14_PULLDOWN(enable)							IOCON->PC_14_b.PDE = enable
#define  PC_14_IOFilter(enable)							IOCON->PC_14_b.S_MODE = enable
#define  PC_15_INIT(PC_15_function) 				IOCON->PC_15 = PC_15_function
#define  PC_15_PULLUP(enable)								IOCON->PC_15_b.PUE = enable
#define  PC_15_PULLDOWN(enable)							IOCON->PC_15_b.PDE = enable
#define  PC_15_IOFilter(enable)							IOCON->PC_15_b.S_MODE = enable
//PD_IO PINs
#define  PD_0_INIT(PD_0_function) 					IOCON->PD_0 = PD_0_function
#define  PD_0_PULLUP(enable)								IOCON->PD_0_b.PUE = enable
#define  PD_0_PULLDOWN(enable)							IOCON->PD_0_b.PDE = enable
#define  PD_0_IOFilter(enable)							IOCON->PD_0_b.S_MODE = enable
#define  PD_1_INIT(PD_1_function) 					IOCON->PD_1 = PD_1_function
#define  PD_1_PULLUP(enable)								IOCON->PD_1_b.PUE = enable
#define  PD_1_PULLDOWN(enable)							IOCON->PD_1_b.PDE = enable
#define  PD_1_IOFilter(enable)							IOCON->PD_1_b.S_MODE = enable
#define  PD_2_INIT(PD_2_function) 					IOCON->PD_2 = PD_2_function
#define  PD_2_PULLUP(enable)								IOCON->PD_2_b.PUE = enable
#define  PD_2_PULLDOWN(enable)							IOCON->PD_2_b.PDE = enable
#define  PD_2_IOFilter(enable)							IOCON->PD_2_b.S_MODE = enable
#define  PD_3_INIT(PD_3_function) 					IOCON->PD_3 = PD_3_function
#define  PD_3_PULLUP(enable)								IOCON->PD_3_b.PUE = enable
#define  PD_3_PULLDOWN(enable)							IOCON->PD_3_b.PDE = enable
#define  PD_3_IOFilter(enable)							IOCON->PD_3_b.S_MODE = enable
#define  PD_4_INIT(PD_4_function) 					IOCON->PD_4 = PD_4_function
#define  PD_4_PULLUP(enable)								IOCON->PD_4_b.PUE = enable
#define  PD_4_PULLDOWN(enable)							IOCON->PD_4_b.PDE = enable
#define  PD_4_IOFilter(enable)							IOCON->PD_4_b.S_MODE = enable
#define  PD_5_INIT(PD_5_function) 					IOCON->PD_5 = PD_5_function
#define  PD_5_PULLUP(enable)								IOCON->PD_5_b.PUE = enable
#define  PD_5_PULLDOWN(enable)							IOCON->PD_5_b.PDE = enable
#define  PD_5_IOFilter(enable)							IOCON->PD_5_b.S_MODE = enable
#define  PD_6_INIT(PD_6_function) 					IOCON->PD_6 = PD_6_function
#define  PD_6_PULLUP(enable)								IOCON->PD_6_b.PUE = enable
#define  PD_6_PULLDOWN(enable)							IOCON->PD_6_b.PDE = enable
#define  PD_6_IOFilter(enable)							IOCON->PD_6_b.S_MODE = enable
#define  PD_7_INIT(PD_7_function) 					IOCON->PD_7 = PD_7_function
#define  PD_7_PULLUP(enable)								IOCON->PD_7_b.PUE = enable
#define  PD_7_PULLDOWN(enable)							IOCON->PD_7_b.PDE = enable
#define  PD_7_IOFilter(enable)							IOCON->PD_7_b.S_MODE = enable
#define  PD_8_INIT(PD_8_function) 					IOCON->PD_8 = PD_8_function
#define  PD_8_PULLUP(enable)								IOCON->PD_8_b.PUE = enable
#define  PD_8_PULLDOWN(enable)							IOCON->PD_8_b.PDE = enable
#define  PD_8_IOFilter(enable)							IOCON->PD_8_b.S_MODE = enable



