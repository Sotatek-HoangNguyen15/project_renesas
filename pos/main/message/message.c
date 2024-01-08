#include <stddef.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#include "message/message.h"

#define QUEUE_SIZE 64

QueueHandle_t keypad_que;
QueueHandle_t storage_que;
QueueHandle_t display_que;
QueueHandle_t print_que;
QueueHandle_t pos_que;
QueueHandle_t qr_que;
QueueHandle_t server_que;
QueueHandle_t payment_que;

void msg_que_init()
{
  // Create keypad message queue
  keypad_que = xQueueCreate(QUEUE_SIZE, sizeof(KeypadMsg));
  if (keypad_que == NULL)
  {
    printf("Error creating keypad message queue\n");
  }

  // Create file queue
  storage_que = xQueueCreate(QUEUE_SIZE, sizeof(FileMsg));
  if (storage_que == NULL)
  {
    printf("Error creating file queue\n");
  }

  // Create display queue
  display_que = xQueueCreate(QUEUE_SIZE, sizeof(DisplayMsg));
  if (display_que == NULL)
  {
    printf("Error creating display queue\n");
  }

  // Create print queue
  print_que = xQueueCreate(QUEUE_SIZE, sizeof(PrintMsg));
  if (print_que == NULL)
  {
    printf("Error creating print queue\n");
  }

  // Create position queue
  pos_que = xQueueCreate(QUEUE_SIZE, sizeof(PosMsg));
  if (pos_que == NULL)
  {
    printf("Error creating position queue\n");
  }

  // Create QR queue
  qr_que = xQueueCreate(QUEUE_SIZE, sizeof(QRMsg));
  if (qr_que == NULL)
  {
    printf("Error creating QR queue\n");
  }

  // Create server queue
  server_que = xQueueCreate(QUEUE_SIZE, sizeof(ServerMsg));
  if (server_que == NULL)
  {
    printf("Error creating server queue\n");
  }

  // Create main queue
  payment_que = xQueueCreate(QUEUE_SIZE, sizeof(PaymentMsg));
  if (payment_que == NULL)
  {
    printf("Error creating main queue\n");
  }
}

void msg_que_send(MsgQue queue, void *data)
{
  Message message;
  message.queue = queue;
  message.p_msg = data;

  BaseType_t ret = errQUEUE_FULL;

  switch (queue)
  {
  case MSG_QUE_KEYPAD:
    ret = xQueueSend(keypad_que, &message, portMAX_DELAY);
    break;
  case MSG_QUE_FILE:
    ret = xQueueSend(storage_que, &message, portMAX_DELAY);
    break;
  case MSG_QUE_DISPLAY:
    ret = xQueueSend(display_que, &message, portMAX_DELAY);
    break;
  case MSG_QUE_PRINT:
    ret = xQueueSend(print_que, &message, portMAX_DELAY);
    break;
  case MSG_QUE_POS:
    ret = xQueueSend(pos_que, &message, portMAX_DELAY);
    break;
  case MSG_QUE_QR:
    ret = xQueueSend(qr_que, &message, portMAX_DELAY);
    break;
  case MSG_QUE_SERVER:
    ret = xQueueSend(server_que, &message, portMAX_DELAY);
    break;
  case MSG_QUE_MAIN:
    ret = xQueueSend(payment_que, &message, portMAX_DELAY);
    break;
  default:
    // Invalid taskID
    break;
  }

  if (ret != pdTRUE)
  {
    // check error
    // TODO: Retry?
  }
}