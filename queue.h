#ifndef __QUEUE_H__
#define __QUEUE_H__
#define SIZE 7

typedef struct
{
    int arr[SIZE]; //存放队列里的数字
    int head;    //记录最前面的数字所在位置
    int tail;    //记录下一个数字应该存放的位置,当队列里没有数字时head = tail
} queue;
typedef struct
{
    int arr[SIZE]; //记录数字
    int tail;      //记录下一个数字的存放位置
    int qty;       //记录队列里数字个数
} cr_queue;

//初始化队列
void queue_init(queue *);
//清理队列
void queue_deinit(queue *);
//判断队列是否空
int queue_empty(const queue *);
//判断队列是否满
int queue_full(const queue *);
//获得队列里的数字个数
int queue_size(const queue *);
//向队列里加入数字
int queue_push(queue *, int);
//从队列里获得数字(取完删除)
int queue_pop(queue *, int *);
//从队列里获得数字(不删除)
int queue_front(queue *, int *);

/********循环队列********/

//计算循环队列第一个数字的位置
//int get_head(const cr_queue *);  //禁止调用
//循环队列的初始化
void c_queue_init(cr_queue *);
//清理循环队列
void c_queue_deinit(cr_queue *);
//计算循环队列数字个数
int c_queue_size(const cr_queue *);
//计算循环队列数字个数
int c_queue_size(const cr_queue *);
//判断循环队列是否空
int c_queue_empty(const cr_queue *);
//判断循环队列是否满
int c_queue_full(const cr_queue *);
//向循环队列加入数字
int c_queue_push(cr_queue *, int );
//从循环队列取数字(取完删除)
int c_queue_pop(cr_queue *, int *);
//从循环队列取数字
int c_queue_front(const cr_queue *, int *);
#endif