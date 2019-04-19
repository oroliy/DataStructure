#include <stdio.h>
#include "stack.h"
//#define SIZE 7
/* typedef struct
{
    int a[SIZE];
    int qty; //栈里的数字个数
} stack;     //代表栈的结构体
//栈的初始化函数 */
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
    p_stack->a[p_stack->qty] = val;//把新数字赋值给qty成员变量做下表的存储区
    p_stack->qty++;//把栈里的数字 +1
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