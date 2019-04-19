# 数据结构
     研究如何使用存储区记录数字
---
## 目录
- [目录](#目录)
- [逻辑结构](#逻辑结构)
- [物理结构](#物理结构)
- [顺序结构](#顺序结构)
  - [缺点](#缺点)
- [链式结构](#链式结构)
  - [节点](#节点)
  - [特性](#特性)
  - [演示](#演示)
- [栈(stack)](#栈stack)
  - [演示](#演示-1)
    - [栈相关函数](#栈相关函数)
    - [栈操作](#栈操作)
- [队列(queue)](#队列queue)
  - [演示](#演示-2)
    - [队列相关函数](#队列相关函数)
  - [循环队列](#循环队列)

---
## 逻辑结构
    1. 集合结构：所有数字可以看做一个整体
       
    2. 线性结构：可以用一条有顺序的线把所有数字串起来

    3. 树状结构：所有数字都是从一个数字开始向一个方向扩展出来的,任何数字可以扩展出多个其它数字

    4. 网状结构：任何两个数字之间都可以有直接的联系,不同数字之间的联系互相无关

---
## 物理结构
     物理结构(物理关系)表示记录数字的存储区之间的关系
---
## 顺序结构
    顺序结构是一种物理结构
    指多个存储区在内存里连续排列
    数组和动态分配内存都是顺序结构的例子

> 可以给顺序结构里每个存储区分配一个编号，可以直接通过编号找到某个存储区
    
`这种根据编号找到存储区的能力叫 **随机访问能力**`

### 缺点
    顺序结构里存储区个数很难改变(很容易造成内存浪费)
    顺序结构不适合进行插入和删除操作
---
## 链式结构
> 链式结构也是一种物理结构

    链式物理结构由多个结构体存储区构成,任何两个结构体存储区之间可以用指针连接
### 节点
    链式物理结构中的每个结构体存储区叫做一个节点

    单向线性链式物理结构是最简单的链式物理结构
    它里面的所有节点可以用一条线串起来
    任何两个节点之间都存在前后顺序
    每个节点里只需要一个指针
    最后一个节点里的指针必须是空指针

    可以在线性链式物理结构的前后各增加一个无效节点
    前面增加的无效节点叫头节点
    后面增加的无效节点叫尾节点
### 特性
>- 链式物理结构 **不支持随机访问能力** ,但是适合进行插入和删除操作,链式物理结构里的节点都是动态分配的,所以可以任意改变个数

### 演示

```c
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int a;          //记录数字
    struct node *p; //指向下一个结构体
} node;

int main()
{
    /************************单向线性链式物理结构******************************/

    node n1 = {10}, n2 = {20}, n3 = {30};
    n1.p = &n2; //n1的指针指向n2,表示n1在n2前面
    n2.p = &n3; //n2的指针指向n3,表示n2在n3前面
    //printf("%d\n", *n1.p);    //n2.a
    //printf("%d\n", *n1.p->p); //n3.a

    /*****************************循环示例**********************************/

    node head = {0}, tail = {0};
    head.p = &n1; //头节点指向原来最前面的节点,表示头节点在最前,本身是无效节点
    n3.p = &tail; //尾节点指向原来最后面的节点,表示尾节点在最后,本身是无效节点

    node *p_temp = NULL;
    for (p_temp = &head /*head为空*/; p_temp != &tail; p_temp = p_temp->p)
    //每次循环都会指向下一个节点,直到指向尾节点为止
    {

        //指向相邻的3个节点
        node *p_first = p_temp;
        //p_first 从head节点指到最后一个有效节点
        node *p_mid = p_first->p;
        //p_mid 从第一个有效节点一直指向到尾节点
        node *p_last = p_mid->p;
        if (p_mid != &tail) //处理除尾节点外的情况
        {
            printf("%d ", p_mid->a);
        }
    }
    printf("\n");

    /*****************************插入数字*********************************/
    node n4 = {31};
    for (p_temp = &head; p_temp != &tail; p_temp = p_temp->p)
    {
        node *p_first = p_temp;
        node *p_mid = p_first->p;
        node *p_last = p_mid->p;
        if (p_mid == &tail || p_mid->a > n4.a)
        //当p_mid指向尾节点或者p_mid指向的数字比新数字大的时候
        {
            p_first->p = &n4; //p_first指向新节点
            n4.p = p_mid;     //新节点指向p_mid指向的节点
            break;
        }
    }
    for (p_temp = &head; p_temp != &tail; p_temp = p_temp->p) //处理打印出来
    {
        node *p_first = p_temp;
        node *p_mid = p_first->p;
        node *p_last = p_mid->p;
        if (p_mid != &tail) //处理除尾节点外的情况
        {
            printf("%d ", p_mid->a);
        }
    }
    printf("\n");

    /*****************************删除数字*********************************/
    //只能删一个
    for (p_temp = &head; p_temp != &tail; p_temp = p_temp->p)
    {
        node *p_first = p_temp;
        node *p_mid = p_first->p;
        node *p_last = p_mid->p;
        if (p_mid != &tail && p_mid->a == 20)
        //当p_mid不指向尾节点并且p_mid指向的数字等于20的时候
        {
            p_first->p = p_last; //p_first指向p_last节点
            break;
        }
    }
    for (p_temp = &head; p_temp != &tail; p_temp = p_temp->p) //处理打印出来
    {
        node *p_first = p_temp;
        node *p_mid = p_first->p;
        node *p_last = p_mid->p;
        if (p_mid != &tail) //处理除尾节点外的情况
        {
            printf("%d ", p_mid->a);
        }
    }
    printf("\n");

    /*****************************动态分配*********************************/

    head.p = &tail; //头节点指向尾节点,构成一个空的链式物理结构
    node *p_node = (node *)malloc(sizeof(node));
    if (!p_node)
    { //动态分配内存失败返回0
        return 0;
    }
    else
    {
        //初始化动态分配节点
        p_node->a = 56;
        p_node->p = NULL;
        //把新节点加入到空的链式结构中
        head.p = p_node;
        p_node->p = &tail;
        //打印
        for (p_temp = &head; p_temp != &tail; p_temp = p_temp->p)
        {
            node *p_first = p_temp;
            node *p_mid = p_first->p;
            node *p_last = p_mid->p;
            if (p_mid != &tail)
            {
                printf("%d ", p_mid->a);
            }
        }
        printf("\n");
        //释放动态分配的内存
        while (head.p != &tail)//当头节点指向尾节点时退出循环
        {
        //每次循环删除最前面的有效节点
            node *p_first = &head;
            node *p_mid = p_first->p;
            node *p_last = p_mid->p;
            p_first->p = &p_last;
            free(p_mid);
            p_mid->p = NULL;
        }
    }
    return 0;
}
```
---
## 栈(stack)
>    1. 栈是一种数据结构,它可以用来存放数字
>    2. 一次只能向栈里加入一个数字
>    3. 可以从栈里获得数字,并且一次只能获得一个数字
>    4. 栈里的数字有前后顺序.先进入的数字在前,后进入的数字在后.
>    5. 每次从栈里获得的数字必须是最后放进去的数字
>>  这种使用数字的规则叫后进先出

    编写栈的时候需要提供
    - push函数 向栈里加入一个数字
    - pop函数  从栈里获得一个数字


### 演示  
#### 栈相关函数
```c
typedef struct
{
    int a[SIZE];
    int qty; //栈里的数字个数
} stack;     //代表栈的结构体

//栈的初始化函数
void stack_init(stack *p_stack)
{
    p_stack->qty = 0;
}

//清理栈内容的函数
void stack_deinit(stack *p_stack)
{
    p_stack->qty = 0;
}

//判断栈是否满的函数
int stack_full(const stack *p_stack)
{
    return p_stack->qty >= SIZE;
}

//判断栈是否空的函数
int stack_empty(const stack *p_stack)
{
    return !(p_stack->qty);
}

//获得数字个数的函数
int stack_size(const stack *p_stack)
{
    return p_stack->qty;
}

//向栈里加入数字的函数
int stack_push(stack *p_stack, int val)
{
    if (p_stack->qty >= SIZE)
    {
        return 0;
    }
    p_stack->a[p_stack->qty] = val;
    p_stack->qty++;
    return 1;
}

//从栈里获得数字的函数(同时从栈里删除数字)
int stack_pop(stack *p_stack, int *p_val)
{
    if (!(p_stack->qty))
    {
        return 0;
    }
    *p_val = p_stack->a[p_stack->qty - 1];
    p_stack->qty--;
    return 1;
}

//获得最后一个数字的函数(不会删除数字)
int stack_top(const stack *p_stack, int *p_val)
{
    if (!(p_stack->qty))
    {
        return 0;
    }
    *p_val = p_stack->a[p_stack->qty - 1];
    return 1;
}
```

#### 栈操作

```c
#include <stdio.h>
#include "stack.h"
int main()
{
    stack stk = {0}; //声明栈
    int size = 0;
    stack_init(&stk); //初始化栈

    /*******************************************************/

    size = stack_size(&stk); //获得栈里的数字个数
    if (!size)
    {
        printf("栈是空的\n");
    }
    else if (size == stk.qty)
    {
        printf("栈是满的\n");
        //return 0;
    }
    else
    {
        printf("栈里的数字个数:%d\n", size);
        printf("还有%d个空位\n", stk.qty - size);
    }

    /*******************************************************/

    //向栈里加入3个数字
    for(int  i = 0; i < SIZE; i++)
    {
        stack_push(&stk, i*10);
    }
    size = stack_size(&stk); //获得栈里的数字个数
    if (!size)
    {
        printf("栈是空的\n");
    }
    else if (size == SIZE)
    {
        printf("栈是满的\n");
        //return 0;
    }
    else
    {
        printf("栈里的数字个数:%d\n", size);
        printf("还有%d个空位\n", SIZE - size);
    }

    /*******************************************************/

    int a = 0, b = 0;
    //stack_top(&stk, &a);
    while(1)
    {
        b = stack_pop(&stk, &a);
        if (!b) {
            break;
        }
        printf("%d ", a);
    }
    printf("\n");

    stack_deinit(&stk); //清理栈
}
```
---
## 队列(queue)

>  - 队列也是一种数据结构
>  -  队列里也可以存放一组数字，队列里的数字之间也有顺序(先进入的数字在前，后进入的数字在后)
>  -  队列一次只能放一个数字，一次也只能获得一个数字
>  -  每次从队列里获得的数字一定是最前面的数字
>  -  队列这种使用数字的规则叫 **先进先出**

实现队列的时候也需要提供push函数用来向队列里加入数字
实现队列的时候同样需要提供pop函数用来从队列里获得数字

### 演示

#### 队列相关函数

```c
//队列  先进先出
#include <stdio.h>
#include "queue.h"
#define SIZE 7
typedef struct
{
    int a[SIZE]; //存放队列里的数字
    int head;    //记录最前面的数字所在位置
    int tail;    //记录下一个数字应该存放的位置,当队列里没有数字时head = tail
} queue;

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
    p_queue->a[p_queue->tail] = val;
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
    *p_val = p_queue->a[p_queue->head];
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
    *p_val = p_queue->a[p_queue->head];
    return 1;
}
```

### 循环队列

