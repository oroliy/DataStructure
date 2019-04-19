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