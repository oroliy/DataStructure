#include <stdio.h>
#include <stdlib.h>
#include "link.h"
/* typedef struct node
{
    int val;
    struct node *p;
} node; //节点结构体
typedef struct
{
    node head; //头节点
    node tail; //尾节点
} link;        //链表结构体 */

//链表初始化
void link_init(link *p_link)
{
    p_link->head.p = &p_link->tail; //头节点指针指向尾节点
    p_link->tail.p = NULL;          //尾节点指针初始化
}

//清理链表
void link_deinit(link *p_link)
{
    while (p_link->head.p != &(p_link->tail))
    //每次循环删除最前面的有效节点
    {
        node *p_first = &p_link->head;
        node *p_mid = p_first->p;
        //指向第一个有效节点
        node *p_last = p_mid->p;

        p_first->p = p_last; //把p_mid清理掉

        free(p_mid); //释放动态内存
        p_mid = NULL;
    }
}

//判断链表是否空
int link_empty(const link *p_link)
{
    return p_link->head.p == &(p_link->tail); //头节点指向尾节点则为空链表
}

//获得链表里数字个数
int link_size(const link *p_link)
{
    int cnt = 0;
    for (const node *p_temp = &p_link->head; p_temp != &(p_link->tail); p_temp = p_temp->p)
    {
        const node *p_first = p_temp;
        const node *p_mid = p_first->p;
        const node *p_last = p_mid->p;
        if (p_mid != &(p_link->tail))
        {
            //当p_mid不是指向尾节点时 cnt++
            cnt++;
        }
    }
    return cnt; //cnt则是链表长度
}

//在链表末尾插入新数字
int link_append(link *p_link, int val)
{
    node *p_link_new = (node *)malloc(sizeof(node));
    if (!p_link_new)
    {
        return 0;
    }
    p_link_new->val = val;
    p_link_new->p = NULL;
    for (node *p_temp = &p_link->head; p_temp != &(p_link->tail); p_temp = p_temp->p)
    {
        node *p_first = p_temp;
        node *p_mid = p_first->p;
        node *p_last = p_mid->p;
        if (p_mid == &(p_link->tail))
        {
            p_first->p = p_link_new;
            p_link_new->p = p_mid;
            break;
        }
    }
    /* while (p_link->head.p != &p_link->tail)//当头节点指向尾节点时退出循环
        {
        //每次循环删除最前面的有效节点
            node *p_first = &p_link->head;
            node *p_mid = p_first->p;
            node *p_last = p_mid->p;
            p_first->p = p_last;
            free(p_mid);
            p_mid->p = NULL;
        } */
    return 1;
}

//在链表头插入新数字
int link_add_head(link *p_link, int val)
{
    node *p_link_new = (node *)malloc(sizeof(node));
    if (!p_link_new)
    {
        return 0;
    }
    p_link_new->val = val;
    p_link_new->p = NULL;

    node *p_first = NULL, *p_mid = NULL;
    p_first = &(p_link->head);
    p_mid = p_first->p;

    p_first->p = p_link_new;
    p_link_new->p = p_mid;
    /* p_link_new->val = val;
    p_link_new->p = p_link->head.p;
    p_link->head.p = &p_link_new; */
    return 1;
}

//按照从小到大的顺序在链表中间插入新节点
int link_insert(link *p_link, int val)
{
    node *p_link_new = (node *)malloc(sizeof(node));
    if (!p_link_new)
    {
        return 0;
    }
    p_link_new->val = val;
    p_link_new->p = NULL;
    for (node *p_tmp = &(p_link->head); p_tmp != &(p_link->tail); p_tmp = p_tmp->p)
    {
        node *p_first = p_tmp;
        node *p_mid = p_first->p;
        if (p_mid == &(p_link->tail) || p_mid->val > val)
        {
            p_first->p = p_link_new;
            p_link_new->p = p_mid;
            break;
        }
    }
    return 1;
}

//删除最后节点
int link_remove_tail(link *p_link)
{
    node *p_tmp = NULL;
    for (p_tmp = &(p_link->head); p_tmp != &(p_link->tail); p_tmp = p_tmp->p)
    {
        node *p_first = p_tmp;
        node *p_mid = p_first->p;
        node *p_last = p_mid->p;
        if (p_last == &(p_link->tail))
        {
            p_first->p = p_last;
            free(p_mid);
            p_mid = NULL;
            return 1;
        }
    }
    return 0;
}

//删除第一个有效节点
int link_remove_head(link *p_link)
{
    if (p_link->head.p == &(p_link->tail))
    {
        return 0;
    }
    node *p_first = NULL, *p_mid = NULL, *p_last = NULL;
    p_first = &(p_link->head);
    p_mid = p_first->p;
    p_last = p_mid->p;
    p_first->p = p_last;
    free(p_mid);
    p_mid = NULL;
    return 1;
}

//删除链表里某个数字
int link_remove(link *p_link, int val)
{
    for (node *p_tmp = &(p_link->head); p_tmp != &(p_link->tail); p_tmp = p_tmp->p)
    {
        node *p_first = p_tmp;
        node *p_mid = p_first->p;
        node *p_last = p_mid->p;
        if (p_mid != &(p_link->tail) && p_mid->val == val)
        {
            p_first->p = p_last;
            free(p_mid);
            p_mid = NULL;
            return 1;
        }
    }
    return 0;
}

//获得链表最后一个数字
int link_get_tail(const link *p_link, int *p_val)
{
    for (const node *p_tmp = &(p_link->head); p_tmp != &(p_link->tail); p_tmp = p_tmp->p)
    {
        const node *p_first = p_tmp;
        const node *p_mid = p_first->p;
        const node *p_last = p_mid->p;
        if (p_last == &(p_link->tail))
        {
            *p_val = p_mid->val;
            return 1;
        }
    }
    return 0;
}

//获得链表第一个数字
int link_get_head(const link *p_link, int *p_val)
{
    if (p_link->head.p == &(p_link->tail))
    {
        return 0;
    }
    //*p_val = p_link->head.p->val;

    const node *p_tmp = &(p_link->head);
    const node *p_first = p_tmp;
    const node *p_mid = p_first->p;
    *p_val = p_mid->val;
    return 1;
}

//根据编号提取链表里的数字
int link_get(const link *p_link, int *p_val, int n)
{
    int cnt = 0;
    for (const node *p_tmp = &(p_link->head); p_tmp != &(p_link->tail); p_tmp = p_tmp->p)
    {
        const node *p_first = p_tmp;
        const node *p_mid = p_first->p;
        const node *p_last = p_mid->p;
        
        if (p_mid != &(p_link->tail) && cnt == n)
        {
            *p_val = p_mid->val;
            return 1;
        }
        cnt++;
    }
    return 0;
}