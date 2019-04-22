#ifndef __LINK_H__
#define __LINK_H__
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *p;
} node; //节点结构体
typedef struct
{
    node head; //头节点
    node tail; //尾节点
} link;        //链表结构体

/******************************************************************************/

typedef struct c_node //双向节点
{
    int val;
    struct c_node *p_prev;
    struct c_node *p_next;
} c_node; //双向节点结构体
typedef struct
{
    c_node head;   //头节点
    c_node tail;   //尾节点
    c_node *p_cur; //记录遍历过程中上一个操作的节点
} c_link;          //双向链表结构体

/***************************************单向链表声明*********************************/

//链表初始化
void link_init(link *);

//清理链表
void link_deinit(link *);

//判断链表是否空
int link_empty(const link *);

//获得链表里数字个数
int link_size(const link *);

//在链表末尾插入新数字
int link_append(link *, int);

//在链表头插入新数字
int link_add_head(link *, int);

//按照从小到大的顺序在链表中间插入新节点
int link_insert(link *, int);

//删除最后节点
int link_remove_tail(link *);

//删除第一个有效节点
int link_remove_head(link *);

//删除链表里某个数字
int link_remove(link *, int);

//获得链表最后一个数字
int link_get_tail(const link *, int *);

//获得链表第一个数字
int link_get_head(const link *, int *);

//根据编号提取链表里的数字
int link_get(const link *, int *, int);

/***************************************双向链表声明*********************************/

//链表初始化函数
void c_link_init(c_link *);

//链表清理函数
void c_link_deinit(c_link *);

//统计数字个数的函数
int c_link_size(const c_link *);

//在链表最前面增加数字的函数
int c_link_add_head(c_link *, int);

//在链表最后加入新数字的函数
int c_link_append(c_link *, int);

//按照从小到大的顺序在链表里加入新数字的函数
int c_link_insert(c_link *, int);

//从链表里删除最前面数字的函数
int c_link_remove_head(c_link *);

//删除最后面数字的函数
int c_link_remove_tail(c_link *);

//删除某个数字的函数
int c_link_remove(c_link *, int);

//获得最前面数字的函数
int c_link_get_head(const c_link *, int *);

//获得最后一个数字的函数
int c_link_get_tail(const c_link *, int *);

//根据编号找到数字的函数
int c_link_get(const c_link *, int *, int);

//开始从前向后遍历链表
void c_link_begin(c_link *);

//在从前向后遍历过程中获得下一个数字的函数
int c_link_next(c_link *, int *);

//开始从后向前遍历链表
void c_link_r_begin(c_link *);

//从后向前遍历获得数字的函数
int c_link_prev(c_link *, int *);

/***************************************单向链表*********************************/

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

/***************************************双向链表*********************************/

//链表初始化函数
void c_link_init(c_link *p_link)
{
    p_link->head.p_prev = NULL;
    p_link->head.p_next = &(p_link->tail);
    p_link->tail.p_prev = &(p_link->head);
    p_link->tail.p_next = NULL;
    p_link->p_cur = NULL; //空指针表示链表不在遍历过程中
}
//链表清理函数
void c_link_deinit(c_link *p_link)
{
    p_link->p_cur = NULL;
    while (p_link->head.p_next != &(p_link->tail))
    {
        c_node *p_first = &(p_link->head);
        c_node *p_mid = p_first->p_next;
        c_node *p_last = p_mid->p_next;
        p_first->p_next = p_last;
        p_last->p_prev = p_first;
        free(p_mid);
        p_mid = NULL;
    }
}
//统计数字个数的函数
int c_link_size(const c_link *p_link)
{
    int cnt = 0;
    const c_node *p_node = NULL;
    for (p_node = &(p_link->head); p_node != &(p_link->tail); p_node = p_node->p_next)
    {
        const c_node *p_first = p_node;
        const c_node *p_mid = p_first->p_next;
        const c_node *p_last = p_mid->p_next;
        if (p_mid != &(p_link->tail))
        {
            cnt++;
        }
    }
    return cnt;
}
//在链表最前面增加数字的函数
int c_link_add_head(c_link *p_link, int val)
{
    c_node *p_first = NULL, *p_mid = NULL, *p_last = NULL;
    c_node *p_node = NULL;
    p_link->p_cur = NULL; //结束遍历过程
    p_node = (c_node *)malloc(sizeof(c_node));
    if (!p_node)
    {
        return 0;
    }
    p_node->val = val;
    p_node->p_prev = NULL;
    p_node->p_next = NULL;
    p_first = &(p_link->head);
    p_mid = p_first->p_next;
    p_last = p_mid->p_next;
    p_first->p_next = p_node;
    p_node->p_next = p_mid;
    p_mid->p_prev = p_node;
    p_node->p_prev = p_first;
    return 1;
}
//在链表最后加入新数字的函数
int c_link_append(c_link *p_link, int val)
{
    c_node *p_first = NULL, *p_mid = NULL, *p_last = NULL;
    c_node *p_node = NULL;
    p_link->p_cur = NULL;
    p_node = (c_node *)malloc(sizeof(c_node));
    if (!p_node)
    {
        return 0;
    }
    p_node->val = val;
    p_node->p_prev = NULL;
    p_node->p_next = NULL;
    p_mid = &(p_link->tail);
    p_first = p_mid->p_prev;
    p_last = p_mid->p_next;
    p_first->p_next = p_node;
    p_node->p_next = p_mid;
    p_mid->p_prev = p_node;
    p_node->p_prev = p_first;
    return 1;
}
/*int link_append(c_link *p_link, int val) {
    c_node *p_tmp = NULL;
    c_node *p_node = NULL;
    p_link->p_cur = NULL;
    p_node = (c_node *)malloc(sizeof(c_node));
    if (!p_node) {
        return 0;
    }
    p_node->val = val;
    p_node->p_prev = NULL;
    p_node->p_next = NULL;
    for (p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next) {
        c_node *p_first = p_tmp;
        c_node *p_mid = p_first->p_next;
        c_node *p_last = p_mid->p_next;
        if (p_mid == &(p_link->tail)) {
            p_first->p_next = p_node;
            p_node->p_next = p_mid;
            p_mid->p_prev = p_node;
            p_node->p_prev = p_first;
            break;
        }
    }
    return 1;
}*/
//按照从小到大的顺序在链表里加入新数字的函数
int c_link_insert(c_link *p_link, int val)
{
    c_node *p_tmp = NULL;
    c_node *p_node = NULL;
    p_link->p_cur = NULL;
    p_node = (c_node *)malloc(sizeof(c_node));
    if (!p_node)
    {
        return 0;
    }
    p_node->val = val;
    p_node->p_prev = NULL;
    p_node->p_next = NULL;
    for (p_tmp = &(p_link->head); p_tmp != &(p_link->tail); p_tmp = p_tmp->p_next)
    {
        c_node *p_first = p_tmp;
        c_node *p_mid = p_first->p_next;
        c_node *p_last = p_mid->p_next;
        if (p_mid == &(p_link->tail) || p_mid->val > val)
        {
            p_first->p_next = p_node;
            p_node->p_next = p_mid;
            p_mid->p_prev = p_node;
            p_node->p_prev = p_first;
            break;
        }
    }
    return 1;
}
//从链表里删除最前面数字的函数
int c_link_remove_head(c_link *p_link)
{
    c_node *p_first = NULL, *p_mid = NULL, *p_last = NULL;
    p_link->p_cur = NULL;
    p_first = &(p_link->head);
    p_mid = p_first->p_next;
    p_last = p_mid->p_next;
    if (p_mid != &(p_link->tail))
    {
        p_first->p_next = p_last;
        p_last->p_prev = p_first;
        free(p_mid);
        p_mid = NULL;
        return 1;
    }
    else
    {
        return 0;
    }
}
//删除最后面数字的函数
int c_link_remove_tail(c_link *p_link)
{
    c_node *p_first = NULL, *p_mid = NULL, *p_last = NULL;
    p_link->p_cur = NULL;
    p_last = &(p_link->tail);
    p_mid = p_last->p_prev;
    p_first = p_mid->p_prev;
    if (p_mid != &(p_link->head))
    {
        p_first->p_next = p_last;
        p_last->p_prev = p_first;
        free(p_mid);
        p_mid = NULL;
        return 1;
    }
    else
    {
        return 0;
    }
}
/*int link_remove_tail(c_link *p_link) {
    c_node *p_tmp = NULL;
    p_link->p_cur = NULL;
    for (p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next) {
        c_node *p_first = p_tmp;
        c_node *p_mid = p_first->p_next;
        c_node *p_last = p_mid->p_next;
        if (p_last == &(p_link->tail)) {
            p_first->p_next = p_last;
            p_last->p_prev = p_first;
            free(p_mid);
            p_mid = NULL;
            return 1;
        }
    }
    return 0;
}*/
//删除某个数字的函数
int c_link_remove(c_link *p_link, int val)
{
    c_node *p_tmp = NULL;
    p_link->p_cur = NULL;
    for (p_tmp = &(p_link->head); p_tmp != &(p_link->tail); p_tmp = p_tmp->p_next)
    {
        c_node *p_first = p_tmp;
        c_node *p_mid = p_first->p_next;
        c_node *p_last = p_mid->p_next;
        if (p_mid != &(p_link->tail) && p_mid->val == val)
        {
            p_first->p_next = p_last;
            p_last->p_prev = p_first;
            free(p_mid);
            p_mid = NULL;
            return 1;
        }
    }
    return 0;
}
//获得最前面数字的函数
int c_link_get_head(const c_link *p_link, int *p_val)
{
    const c_node *p_first = NULL, *p_mid = NULL, *p_last = NULL;
    p_first = &(p_link->head);
    p_mid = p_first->p_next;
    p_last = p_mid->p_next;
    if (p_mid != &(p_link->tail))
    {
        *p_val = p_mid->val;
        return 1;
    }
    else
    {
        return 0;
    }
}
//获得最后一个数字的函数
int c_link_get_tail(const c_link *p_link, int *p_val)
{
    const c_node *p_first = NULL, *p_mid = NULL, *p_last = NULL;
    p_last = &(p_link->tail);
    p_mid = p_last->p_prev;
    p_first = p_mid->p_prev;
    if (p_mid != &(p_link->head))
    {
        *p_val = p_mid->val;
        return 1;
    }
    else
    {
        return 0;
    }
}
/*int link_get_tail(const c_link *p_link, int *p_val) {
    const c_node *p_tmp = NULL;
    for (p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next) {
        const c_node *p_first = p_tmp;
        const c_node *p_mid = p_first->p_next;
        const c_node *p_last = p_mid->p_next;
        if (p_last == &(p_link->tail)) {
            *p_val = p_mid->val;
            return 1;
        }
    }
    return 0;
}*/
//根据编号找到数字的函数
int c_link_get(const c_link *p_link, int *p_val, int sn)
{
    int cnt = 0;
    const c_node *p_tmp = NULL;
    for (p_tmp = &(p_link->head); p_tmp != &(p_link->tail); p_tmp = p_tmp->p_next)
    {
        const c_node *p_first = p_tmp;
        const c_node *p_mid = p_first->p_next;
        const c_node *p_last = p_mid->p_next;
        if (p_mid != &(p_link->tail) && cnt == sn)
        {
            *p_val = p_mid->val;
            return 1;
        }
        cnt++;
    }
    return 0;
}
//开始从前向后遍历链表
void c_link_begin(c_link *p_link)
{
    p_link->p_cur = &(p_link->head);
}
//在从前向后遍历过程中获得下一个数字的函数
int c_link_next(c_link *p_link, int *p_val)
{
    if (!(p_link->p_cur))
    {
        //链表没有处于遍历过程中
        return 0;
    }
    p_link->p_cur = p_link->p_cur->p_next;
    if (p_link->p_cur == &(p_link->tail))
    {
        //指针指向尾节点时，表示遍历完成，初始化
        p_link->p_cur = NULL;
        return 0;
    }
    else
    {
        //把当前节点里的数字传递给调用函数
        *p_val = p_link->p_cur->val;
        return 1;
    }
}
//开始从后向前遍历链表
void c_link_r_begin(c_link *p_link)
{
    p_link->p_cur = &(p_link->tail);
}
//从后向前遍历获得数字的函数
int c_link_prev(c_link *p_link,int *p_val)
{
    if (!p_link->p_cur) {
        return 0;
    }
    p_link->p_cur = p_link->p_cur->p_prev;
    if (p_link->p_cur==&(p_link->head)) {
        p_link->p_cur = NULL;
        return 0;
    }
    else
    {
        *p_val = p_link->p_cur->val;
        return 1;
    }
}
#endif