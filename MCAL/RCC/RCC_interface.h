/*********************************************************************************/
/****************   Auther    : Youssef Hussein              *********************/
/****************   Date      : 27 Feb 2026                  *********************/
/****************   Version.  : 0.1                          *********************/
/****************   File Name : RCC_interface.h              *********************/
/*********************************************************************************/


#ifndef     RCC_INTERFACE_H_
#define     RCC_INTERFACE_H_ 

/*=================================================================================
  @Module: RCC (Reset and Clock Control)
  @Description: This header file contains the interface for controlling the system
                and peripheral clocks of STM32 MCUs. It defines bus IDs, peripheral
                IDs, and function prototypes for initializing and managing clocks.
=================================================================================*/

/*------------------- Bus IDs -------------------*/
#define RCC_AHB                 0   // Advanced High-performance Bus
#define RCC_APB1                1   // Peripheral Bus 1
#define RCC_APB2                2   // Peripheral Bus 2

/*------------------- AHB Peripheral IDs -------------------*/
#define RCC_AHB_DMA1EN          0   // DMA1 clock enable
#define RCC_AHB_DMA2EN          1   // DMA2 clock enable
#define RCC_AHB_SRAMEN          2   // SRAM interface clock enable
#define RCC_AHB_FLITFEN         4   // Flash interface clock enable
#define RCC_AHB_CRCEN           6   // CRC calculation unit clock enable
#define RCC_AHB_OTGFSEN         12  // USB OTG Full Speed clock enable
#define RCC_AHB_ETHMACEN        14  // Ethernet MAC clock enable
#define RCC_AHB_ETHMACTXEN      15  // Ethernet MAC transmitter clock enable
#define RCC_AHN_ETHMACRXEN      16  // Ethernet MAC receiver clock enable (note: typo in original name)

/*------------------- APB1 Peripheral IDs -------------------*/
#define RCC_APB1_TIM2EN         0   // Timer 2 clock enable
#define RCC_APB1_TIM3EN         1   // Timer 3 clock enable
#define RCC_APB1_TIM4EN         2   // Timer 4 clock enable
#define RCC_APB1_TIM5EN         3   // Timer 5 clock enable
#define RCC_APB1_TIM6EN         4   // Timer 6 clock enable
#define RCC_APB1_TIM7EN         5   // Timer 7 clock enable
#define RCC_APB1_WWDGEN         11  // Window Watchdog clock enable
#define RCC_APB1_SPI2EN         14  // SPI2 clock enable
#define RCC_APB1_SPI3EN         15  // SPI3 clock enable
#define RCC_APB1_USART2EN       17  // USART2 clock enable
#define RCC_APB1_USART3EN       18  // USART3 clock enable
#define RCC_APB1_UART4EN        19  // UART4 clock enable
#define RCC_APB1_UART5EN        20  // UART5 clock enable
#define RCC_APB1_I2C1EN         21  // I2C1 clock enable
#define RCC_APB1_I2C2EN         22  // I2C2 clock enable
#define RCC_APB1_CAN1EN         25  // CAN1 clock enable
#define RCC_APB1_CAN2EN         26  // CAN2 clock enable
#define RCC_APB1_BKPEN          27  // Backup interface clock enable
#define RCC_APB1_PWREN          28  // Power interface clock enable
#define RCC_APB1_DACEN          29  // DAC interface clock enable

/*------------------- APB2 Peripheral IDs -------------------*/
/**< APB2 peripheral clock enable register (RCC_APB2ENR) */
#define RCC_APB2_AFIOEN         0   // Alternate Function I/O clock enable
#define RCC_APB2_IOPAEN         2   // GPIO port A clock enable
#define RCC_APB2_IOPBEN         3   // GPIO port B clock enable
#define RCC_APB2_IOPCEN         4   // GPIO port C clock enable
#define RCC_APB2_IOPDEN         5   // GPIO port D clock enable
#define RCC_APB2_IOPEEN         6   // GPIO port E clock enable
#define RCC_APB2_ADC1EN         9   // ADC1 clock enable
#define RCC_APB2_ADC2EN         10  // ADC2 clock enable
#define RCC_APB2_TIM1EN         11  // Timer 1 clock enable
#define RCC_APB2_SPI1EN         12  // SPI1 clock enable
#define RCC_APB2_USART1EN       14  // USART1 clock enable

/*=================================================================================
  @Function Prototypes
  @Descriptions:
    - Rcc_InitSysClock: Initialize the system clock according to configuration.
    - Rcc_EnablePeripheral: Enable the clock for a specific peripheral on a bus.
    - Rcc_DisablePeripheral: Disable the clock for a specific peripheral on a bus.
  @Parameters:
    - Copy_PeripheralId: ID of the peripheral to enable/disable
    - Copy_BusId: ID of the bus (AHB/APB1/APB2) where the peripheral resides
  @Return:
    - Std_ReturnType: Standard return type indicating success or error
=================================================================================*/
Std_ReturnType Rcc_InitSysClock();
Std_ReturnType Rcc_EnablePeripheral(u8 Copy_PeripheralId , u8 Copy_BusId);
Std_ReturnType Rcc_DisablePeripheral(u8 Copy_PeripheralId , u8 Copy_BusId);

#endif // RCC_INTERFACE_H_