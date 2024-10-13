#include "FreeRTOS_TASK.h"
/* user file */
#include "led.h"
#include "key.h"

 /* 创建任务句柄 */
TaskHandle_t AppTaskCreate_Handle = NULL;
static TaskHandle_t Task_10ms_Handle = NULL;
static TaskHandle_t Task_1000ms_Handle = NULL;

static void task_10ms(void);
static void task_1000ms(void);

void AppTaskCreate(void)
{
  BaseType_t xReturn = pdPASS;
  
  taskENTER_CRITICAL();
  /* task_10ms */
  xReturn = xTaskCreate((TaskFunction_t )task_10ms,
                        (const char*    )"task_10ms",
                        (uint16_t       )64,
                        (void*          )NULL,
                        (UBaseType_t    )2,
                        (TaskHandle_t*  )&Task_10ms_Handle);
  if(pdPASS == xReturn) {

  }

  /* task_1000ms */
  xReturn = xTaskCreate((TaskFunction_t )task_1000ms,
                        (const char*    )"task_1000ms",
                        (uint16_t       )64,
                        (void*          )NULL,
                        (UBaseType_t    )3,
                        (TaskHandle_t*  )&Task_1000ms_Handle);
  if(pdPASS == xReturn) {

  }
  
  vTaskDelete(AppTaskCreate_Handle); //删除AppTaskCreate任务
  
  taskEXIT_CRITICAL();            //退出临界区
}

static void task_10ms(void)
{
  while (1)
  {
    key_mainfunction();
    vTaskDelay(10);
  }
}

static void task_1000ms(void)
{
  while (1)
  {
    led_mainfunction();
    vTaskDelay(1000);
  }
  
}
