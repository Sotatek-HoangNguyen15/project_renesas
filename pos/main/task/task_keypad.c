#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"

#include "message/message.h"
#include "memory/mem_mgr.h"

static const char *TAG = "KeypadTask";
extern QueueHandle_t keypad_que;

static void task(void *parameter)
{
  while (1)
  {
    ESP_LOGD(TAG, "Task Loop");

    // Check if there is a message in the keypad_que queue
    if (keypad_que != NULL && uxQueueMessagesWaiting(keypad_que) > 0)
    {
      // Allocate memory for the message structure
      Message *msg = (Message *)mem_alloc(sizeof(Message));
      if (msg != NULL)
      {
        // Receive the message from the keypad_que queue
        if (xQueueReceive(keypad_que, msg, 0) == pdPASS)
        {
          // Process the received keypad message
          // ...
          ESP_LOGD(TAG, "processing message");
        }
        else
        {
          // Failed to receive keypad message from the queue
          mem_free(msg);
        }
      }
    }

    // Delay
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void init_task_keypad()
{
  // Create keypad task
  BaseType_t taskCreated = xTaskCreate(task, TAG, 1024 * 16, NULL, tskIDLE_PRIORITY + 1, NULL);

  if (taskCreated != pdPASS)
  {
    // Task creation failed
    ESP_LOGD(TAG, "Fail to create Task");
  }
  else
  {
    ESP_LOGD(TAG, "Task created");
  }
}