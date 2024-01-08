#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_err.h"
#include "esp_log.h"

#include "message/message.h"
#include "memory/mem_mgr.h"

extern void init_task_payment();
extern void init_task_display();
extern void init_task_storage();
extern void init_task_keypad();
extern void init_task_pos();
extern void init_task_print();
extern void init_task_qr();
extern void init_task_server();

void app_main(void)
{
  ESP_LOGD("app_main", "APP START");
  // Initialize memmory, message queue
  mem_init();
  msg_que_init();

  // Initialize tasks
  init_task_display();
  init_task_storage();
  init_task_keypad();
  init_task_pos();
  init_task_print();
  init_task_qr();
  init_task_server();

  init_task_payment();
}
