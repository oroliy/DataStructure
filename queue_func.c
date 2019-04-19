//队列  先进先出
#include "queue.h"

//初始化队列
void queue_init(queue *p_queue)
{
    p_queue->head = 0;
    p_queue->tail = 0;
}
//清理队列
void queue_deinit(queue *p_queue)
{
    p_queue->head = 0;
    p_queue->tail = 0;
}
//判断队列是否空
int queue_empty(const queue *p_queue)
{
    return p_queue->tail == p_queue->head;
}
//判断队列是否满
int queue_full(const queue *p_queue)
{
    return p_queue->tail >= SIZE;
}
//获得队列里的数字个数
int queue_size(const queue *p_queue)
{
    return p_queue->tail - p_queue->head;
}
//向队列里加入数字
int queue_push(queue *p_queue, int val)
{
    if (p_queue->tail >= SIZE)
    {
        return 0;
    }
    p_queue->arr[p_queue->tail] = val;
    p_queue->tail++;
    return 1;
}
//从队列里获得数字(取完删除)
int queue_pop(queue *p_queue, int *p_val)
{
    if (p_queue->tail == p_queue->head)
    {
        return 0;
    }
    *p_val = p_queue->arr[p_queue->head];
    p_queue->head++;
    return 1;
}
//从队列里获得数字(不删除)
int queue_front(queue *p_queue, int *p_val)
{
    if (p_queue->tail == p_queue->head)
    {
        return 0;
    }
    *p_val = p_queue->arr[p_queue->head];
    return 1;
}