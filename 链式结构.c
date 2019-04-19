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
            p_first->p = p_last;
            free(p_mid);
            p_mid->p = NULL;
        }
    }
    return 0;
}