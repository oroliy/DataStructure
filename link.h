#ifndef __LINK_H__
#define __LINK_H__
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
#endif