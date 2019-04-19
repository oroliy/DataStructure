//循环队列演示
#include "queue.h"
#include <stdio.h>
int main(){
    cr_queue q = {0};
    //初始化队列
    c_queue_init(&q);
    int size = c_queue_size(&q);
    int val = 0;
    for (int i = 0; i < SIZE; i++)
    {
        c_queue_push(&q, 10 + i);
        c_queue_pop(&q, &val);
        printf("%d\n", val);
    }

    c_queue_deinit(&q);
}