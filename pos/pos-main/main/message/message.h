#ifndef MESSAGE_H
#define MESSAGE_H

typedef enum
{
  MSG_QUE_KEYPAD,
  MSG_QUE_FILE,
  MSG_QUE_DISPLAY,
  MSG_QUE_PRINT,
  MSG_QUE_POS,
  MSG_QUE_QR,
  MSG_QUE_SERVER,
  MSG_QUE_MAIN,
  MSG_QUE_NUM
} MsgQue;

typedef struct
{
  MsgQue queue;
  void *p_msg;
} Message;

typedef struct
{
  // Keypad message data
  // ...
} KeypadMsg;

typedef struct
{
  // File message data
  // ...
} FileMsg;

typedef struct
{
  // Display message data
  // ...
} DisplayMsg;

typedef struct
{
  // Print message data
  // ...
} PrintMsg;

typedef struct
{
  // Position message data
  // ...
} PosMsg;

typedef struct
{
  // QR message data
  // ...
} QRMsg;

typedef struct
{
  // Server message data
  // ...
} ServerMsg;

typedef struct
{
  // Main message data
  // ...
} PaymentMsg;

void msg_que_init();
void msg_que_send(MsgQue que, void *data);

#endif