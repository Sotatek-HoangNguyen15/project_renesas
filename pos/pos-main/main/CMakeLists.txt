idf_component_register(
    SRCS "main.c"
    SRCS "memory/mem_mgr.c"
    SRCS "message/message.c"
    SRCS "task/task_display.c"
    SRCS "task/task_payment.c"
    SRCS "task/task_keypad.c"
    SRCS "task/task_storage.c"
    SRCS "task/task_print.c"
    SRCS "task/task_pos.c"
    SRCS "task/task_server.c"
    SRCS "task/task_qr.c"
    INCLUDE_DIRS "."
)