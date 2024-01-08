#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"

#include "message/message.h"
#include "memory/mem_mgr.h"

static const char *TAG = "QrTask";
extern QueueHandle_t qr_que;

static void task(void *parameter)
{
  while (1)
  {
    ESP_LOGD(TAG, "Task Loop");

    // Check if there is a message in the qr_que queue
    if (qr_que != NULL && uxQueueMessagesWaiting(qr_que) > 0)
    {
      // Allocate memory for the message structure
      Message *msg = (Message *)mem_alloc(sizeof(Message));
      if (msg != NULL)
      {
        // Receive the message from the qr_que queue
        if (xQueueReceive(qr_que, msg, 0) == pdPASS)
        {
          // Process the received file message
          // ...
          ESP_LOGD(TAG, "Processing message");
        }
        else
        {
          // Failed to receive file message from the queue
          mem_free(msg);
        }
      }
    }

    // Delay
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void init_task_qr()
{
  // Create file task
  BaseType_t taskCreated = xTaskCreate(task, TAG, 1024 * 16, NULL, tskIDLE_PRIORITY + 1, NULL);

  if (taskCreated != pdPASS)
  {
    // Task creation failed
    ESP_LOGD(TAG, "Failed to create task");
  }
  else
  {
    ESP_LOGD(TAG, "Task created");
  }
}