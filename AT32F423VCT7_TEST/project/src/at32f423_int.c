/* add user code begin Header */
/**
  **************************************************************************
  * @file     at32f423_int.c
  * @brief    main interrupt service routines.
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */
/* add user code end Header */

/* includes ------------------------------------------------------------------*/
#include "at32f423_int.h"
#include "wk_system.h"

/* private includes ----------------------------------------------------------*/
/* add user code begin private includes */
#include "freertos.h"
#include "task.h"
#include "key.h"
#include "at32f423_wk_config.h"
/* add user code end private includes */

/* private typedef -----------------------------------------------------------*/
/* add user code begin private typedef */

/* add user code end private typedef */

/* private define ------------------------------------------------------------*/
/* add user code begin private define */
#define UART_BUFFER_LEN 20
/* add user code end private define */

/* private macro -------------------------------------------------------------*/
/* add user code begin private macro */
uint8_t uart_buffer[UART_BUFFER_LEN] = {0};
uint8_t uart_rxindex = 0;
uint8_t uart_rxlen = 0;
uint8_t uart_txindex = 0;
uint8_t uart_txlen = 0;
/* add user code end private macro */

/* private variables ---------------------------------------------------------*/
/* add user code begin private variables */

/* add user code end private variables */

/* private function prototypes --------------------------------------------*/
/* add user code begin function prototypes */

/* add user code end function prototypes */

/* private user code ---------------------------------------------------------*/
/* add user code begin 0 */
void starttx()
{
  uart_txlen += uart_rxlen;
  uart_rxlen = 0;
  usart_interrupt_enable(USART1, USART_TDBE_INT, TRUE);
}
/* add user code end 0 */

/* external variables ---------------------------------------------------------*/
/* add user code begin external variables */

/* add user code end external variables */

/**
  * @brief  this function handles nmi exception.
  * @param  none
  * @retval none
  */
void NMI_Handler(void)
{
  /* add user code begin NonMaskableInt_IRQ 0 */

  /* add user code end NonMaskableInt_IRQ 0 */

  /* add user code begin NonMaskableInt_IRQ 1 */

  /* add user code end NonMaskableInt_IRQ 1 */
}

/**
  * @brief  this function handles hard fault exception.
  * @param  none
  * @retval none
  */
void HardFault_Handler(void)
{
  /* add user code begin HardFault_IRQ 0 */

  /* add user code end HardFault_IRQ 0 */
  /* go to infinite loop when hard fault exception occurs */
  while (1)
  {
    /* add user code begin W1_HardFault_IRQ 0 */

    /* add user code end W1_HardFault_IRQ 0 */
  }
}

/**
  * @brief  this function handles memory manage exception.
  * @param  none
  * @retval none
  */
void MemManage_Handler(void)
{
  /* add user code begin MemoryManagement_IRQ 0 */

  /* add user code end MemoryManagement_IRQ 0 */
  /* go to infinite loop when memory manage exception occurs */
  while (1)
  {
    /* add user code begin W1_MemoryManagement_IRQ 0 */

    /* add user code end W1_MemoryManagement_IRQ 0 */
  }
}

/**
  * @brief  this function handles bus fault exception.
  * @param  none
  * @retval none
  */
void BusFault_Handler(void)
{
  /* add user code begin BusFault_IRQ 0 */

  /* add user code end BusFault_IRQ 0 */
  /* go to infinite loop when bus fault exception occurs */
  while (1)
  {
    /* add user code begin W1_BusFault_IRQ 0 */

    /* add user code end W1_BusFault_IRQ 0 */
  }
}

/**
  * @brief  this function handles usage fault exception.
  * @param  none
  * @retval none
  */
void UsageFault_Handler(void)
{
  /* add user code begin UsageFault_IRQ 0 */

  /* add user code end UsageFault_IRQ 0 */
  /* go to infinite loop when usage fault exception occurs */
  while (1)
  {
    /* add user code begin W1_UsageFault_IRQ 0 */

    /* add user code end W1_UsageFault_IRQ 0 */
  }
}

/**
  * @brief  this function handles svcall exception.
  * @param  none
  * @retval none
  */
void SVC_Handler(void)
{
  /* add user code begin SVCall_IRQ 0 */

  /* add user code end SVCall_IRQ 0 */
  /* add user code begin SVCall_IRQ 1 */

  /* add user code end SVCall_IRQ 1 */
}

/**
  * @brief  this function handles debug monitor exception.
  * @param  none
  * @retval none
  */
void DebugMon_Handler(void)
{
  /* add user code begin DebugMonitor_IRQ 0 */

  /* add user code end DebugMonitor_IRQ 0 */
  /* add user code begin DebugMonitor_IRQ 1 */

  /* add user code end DebugMonitor_IRQ 1 */
}

/**
  * @brief  this function handles pendsv_handler exception.
  * @param  none
  * @retval none
  */
void PendSV_Handler(void)
{
  /* add user code begin PendSV_IRQ 0 */

  /* add user code end PendSV_IRQ 0 */
  /* add user code begin PendSV_IRQ 1 */

  /* add user code end PendSV_IRQ 1 */
}

/**
  * @brief  this function handles systick handler.
  * @param  none
  * @retval none
  */
void SysTick_Handler(void)
{
  /* add user code begin SysTick_IRQ 0 */

  /* add user code end SysTick_IRQ 0 */

  wk_timebase_handler();

  /* add user code begin SysTick_IRQ 1 */
  #if (INCLUDE_xTaskGetSchedulerState  == 1 )
    if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED)
    {
  #endif  /* INCLUDE_xTaskGetSchedulerState */  
      xPortSysTickHandler();
  #if (INCLUDE_xTaskGetSchedulerState  == 1 )
    }
  #endif  /* INCLUDE_xTaskGetSchedulerState */
  /* add user code end SysTick_IRQ 1 */
}

/**
  * @brief  this function handles EXINT Line 0 handler.
  * @param  none
  * @retval none
  */
void EXINT0_IRQHandler(void)
{
  /* add user code begin EXINT0_IRQ 0 */
  if (exint_flag_get(EXINT_LINE_0) != RESET)
  {
    set_key_signal();
    exint_flag_clear(EXINT_LINE_0);
  }
  /* add user code end EXINT0_IRQ 0 */
  /* add user code begin EXINT0_IRQ 1 */

  /* add user code end EXINT0_IRQ 1 */
}

/**
  * @brief  this function handles TMR4 handler.
  * @param  none
  * @retval none
  */
void TMR4_GLOBAL_IRQHandler(void)
{
  /* add user code begin TMR4_GLOBAL_IRQ 0 */
  static uint16_t pwm_cnt = 0;
  if (tmr_flag_get(TMR4, TMR_OVF_FLAG) != RESET) {
    pwm_cnt+=1;
    if (pwm_cnt > 1999) {
      pwm_cnt = 0;
    }
    if (pwm_cnt < 1000) {
      tmr_channel_value_set(TMR4,TMR_SELECT_CHANNEL_2,pwm_cnt);
    } else {
      tmr_channel_value_set(TMR4,TMR_SELECT_CHANNEL_2,2000-pwm_cnt);
    }
    tmr_flag_clear(TMR4,TMR_OVF_FLAG);
  }
  /* add user code end TMR4_GLOBAL_IRQ 0 */


  /* add user code begin TMR4_GLOBAL_IRQ 1 */

  /* add user code end TMR4_GLOBAL_IRQ 1 */
}

/**
  * @brief  this function handles USART1 handler.
  * @param  none
  * @retval none
  */
void USART1_IRQHandler(void)
{
  /* add user code begin USART1_IRQ 0 */
    if(usart_flag_get(USART1, USART_RDBF_FLAG) != RESET)
    {
        usart_flag_clear(USART1, USART_RDBF_FLAG);
        uart_buffer[uart_rxindex++] = usart_data_receive(USART1);
        if(uart_rxindex == UART_BUFFER_LEN)
            uart_rxindex = 0;
        uart_rxlen++;
    }
    if(usart_flag_get(USART1, USART_IDLEF_FLAG) != RESET || uart_rxlen == UART_BUFFER_LEN/2)
    {
        usart_flag_clear(USART1, USART_IDLEF_FLAG);
        starttx();
    }
    if(usart_flag_get(USART1, USART_TDBE_FLAG) != RESET)
    {
        usart_flag_clear(USART1, USART_TDBE_FLAG);
        if(uart_txlen > 0)
        {
            usart_data_transmit(USART1, uart_buffer[uart_txindex++]);
            if(uart_txindex == UART_BUFFER_LEN)
                uart_txindex = 0;
            uart_txlen--;
        }
        else
        {
            usart_interrupt_enable(USART1, USART_TDBE_INT, FALSE);
        }
    }
  /* add user code end USART1_IRQ 0 */
  /* add user code begin USART1_IRQ 1 */

  /* add user code end USART1_IRQ 1 */
}

/**
  * @brief  this function handles TMR6 & DAC handler.
  * @param  none
  * @retval none
  */
void TMR6_DAC_GLOBAL_IRQHandler(void)
{
  /* add user code begin TMR6_DAC_GLOBAL_IRQ 0 */
  static uint16_t time_cnt = 0;
  if(tmr_flag_get(TMR6, TMR_OVF_FLAG) != RESET)
  {
    time_cnt++;
    if (time_cnt == 1000) 
    {
      time_cnt = 0;
      gpio_bits_toggle(GPIOD,LED4_PIN);
    }
    tmr_flag_clear(TMR6,TMR_OVF_FLAG);
  }
  /* add user code end TMR6_DAC_GLOBAL_IRQ 0 */


  /* add user code begin TMR6_DAC_GLOBAL_IRQ 1 */

  /* add user code end TMR6_DAC_GLOBAL_IRQ 1 */
}

/* add user code begin 1 */

/* add user code end 1 */
