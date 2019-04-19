#include <stdio.h>
#include "queue.h"
int main()
{
    queue q = {0};
    //初始化队列
    queue_init(&q);
    int size = queue_size(&q);
    //判断队列数字个数情况
    if (queue_full(&q))
    {
        printf("队列满\n");
    }
    else if (queue_empty(&q))
    {
        printf("队列空\n");
    }
    else
    {
        printf("队列里数字个数:%d\n还有%d个空位", size, SIZE - size);
    }

    /*******************************************************/

    //向队列里加入数字
    for (int i = 0; i < SIZE - 1; i++)
    {
        queue_push(&q, 10 * i);
    }
    //判断队列数字个数情况
    size = queue_size(&q);
    if (queue_full(&q))
    {
        printf("队列满\n");
    }
    else if (queue_empty(&q))
    {
        printf("队列空\n");
    }
    else
    {
        printf("队列里数字个数:%d\n还有%d个空位\n", size, SIZE - size);
    }

    /*******************************************************/

    //从队列里取数字
    int val = 0;
    size = queue_size(&q);
    for (int i = 0; i < size; i++)
    {
        queue_pop(&q, &val);
        printf("%d ", val);
    }
    printf("\n");

    queue_deinit(&q);
}