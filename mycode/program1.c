#include <stddef.h>  // NULL 的定义
#include <stdbool.h>  // bool 的定义

#define TRUE 1   // macro
#define FALSE 0  // #define identifier token-stringopt
#define MSG_DRIVER_SIZE 1000 

typedef struct msg_node {
    void *param;
    void (*handler) (void *param);
} msg_node_t;

typedef struct msg_driver {
    unsigned int in;   // 写入位置
    unsigned int out;  // 读取位置
    msg_node_t *buf[MSG_DRIVER_SIZE];
} msg_driver_t;

bool is_msg_buf_full(msg_driver_t *msg_buf) {
    if(msg_buf->in == MSG_DRIVER_SIZE)
        return TRUE;
    return FALSE;
}

bool is_msg_buf_empty(msg_driver_t *msg_buf) {
    if(msg_buf->out == MSG_DRIVER_SIZE)
        return TRUE;
    return FALSE;
}

// 将消息插入到消息队列中
bool publish_msg(msg_driver_t *msg_buf, msg_node_t *msg) {
    if(is_msg_buf_full(msg_buf) == TRUE) {
        return FALSE;
    }
    msg_buf->buf[msg_buf->in] = msg;
    msg_buf->in = (++msg_buf->in) % MSG_DRIVER_SIZE;  // 防止越界
    return TRUE;
}

// 从消息队列中读取消息
static msg_node_t* get_message(msg_driver_t *msg_buf) {
    msg_node_t *msg = NULL;
    if(is_msg_buf_empty(msg_buf)) {
        return NULL;
    }
    msg = msg_buf->buf[msg_buf->out];
    msg_buf->out = (++msg_buf->out) % MSG_DRIVER_SIZE;
    return msg;
}

void message_driver_handler(msg_driver_t *msg_buf) {
    msg_node_t *msg;
    // msg = get_message(msg_buf); // 若将此方法外置，将会进入死循环
    while((msg = get_message(msg_buf)) != NULL) {
        if(msg->handler != NULL)
            msg->handler(msg->param);
    }
}

#include <stdio.h>

msg_driver_t msg_driver;

static void msg1_handler(void *param) {
    printf("gets msg1:%s\n", param);
}

static void msg2_handler(void *param) {
    printf("gets msg2:%s\n", param);
}

static void msg3_handler(void *param) {
    printf("gets msg3:%s\n", param);
}

// 实例化后为成员赋值
msg_node_t msg1 = {
  .param = "hello world",  // 点符号初始化 
  .handler = msg1_handler, // 结尾是 ',' 不是 ';'
};

msg_node_t msg2 = {
  param : "welcome",
  handler : msg2_handler,  // 冒号初始化
};

msg_node_t msg3 = { 
    NULL,         // 顺序初始化 
    msg3_handler  // 最后一个没有 ','
}; 

int main() {

    publish_msg(&msg_driver, &msg1);  // 若被调用的函数，未放到调用函数内或者循环内，导致的错误
    publish_msg(&msg_driver, &msg2);  // expected declaration specifiers or '...' before '&' token
    publish_msg(&msg_driver, &msg3);

    int i = 3;
    // while(i > 0) {
    while(1)  {
        message_driver_handler(&msg_driver);
        i--;
    }
}