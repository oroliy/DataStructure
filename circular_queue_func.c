#include "queue.h"
/* typedef struct
{
    int arr[SIZE]; //记录数字
    int tail;      //记录下一个数字的存放位置
    int qty;       //记录队列里数字个数
} cr_queue; */
//计算第一个数字的位置
int get_head(const cr_queue *queue)
{
    if (queue->tail >= queue->qty)
    {
        return queue->tail - queue->qty;
    }
    else
    {
        return SIZE + queue->tail - queue->qty;
    }
}
//队列的初始化
void c_queue_init(cr_queue *queue)
{
    queue->tail = 0; //下一个数字放在队列头
    queue->qty = 0;  //队列里数字个数为 0
}
//清理队列
void c_queue_deinit(cr_queue *queue)
{
    queue->tail = 0; //下一个数字放在队列头
    queue->qty = 0;  //队列里数字个数为 0
}
//计算队列数字个数
int c_queue_size(const cr_queue *queue)
{
    return queue->qty;
}
//判断队列是否空
int c_queue_empty(const cr_queue *queue)
{
    return !queue->qty;
}
//判断队列是否满
int c_queue_full(const cr_queue *queue)
{
    return queue->qty >= SIZE;
}
//向循环队列加入数字
int c_queue_push(cr_queue *queue, int val)
{
    if (queue->qty >= SIZE)
    {
        return 0;
    }
    queue->arr[queue->tail] = val; //把数字存进尾巴
    queue->qty++;
    queue->tail++;
    if (queue->tail >= SIZE)//当tail超过数组范围时置0
    {
        queue->tail = 0;
    }
    return 1;
}
//从循环队列取数字(取完删除)
int c_queue_pop(cr_queue *queue, int *val)
{
    if (!queue->qty)
    {
        return 0;
    }
    *val = queue->arr[get_head(queue)];
    queue->qty--;
    return 1;
}
//从循环队列取数字
int c_queue_front(const cr_queue *queue, int *val)
{
    if (!queue->qty)
    {
        return 0;
    }
    *val = queue->arr[get_head(queue)];
    return 1;
}
