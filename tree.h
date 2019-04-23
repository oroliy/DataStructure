// 二叉树演示
#ifndef __TREE_H__
#define __TREE_H__
#include <stdlib.h>
struct node; //声明结构体
typedef struct
{
    struct node *p_node;
} tree;
typedef struct node
{
    int val;
    tree left;
    tree right;
} node;
typedef void (*p_func_t)(int); //创建函数指针类型
/*************************************************/
//树的初始化函数
void tree_init(tree *);

//树的清理函数
void tree_deinit(tree *);

//在有序二叉树里查找某个数字所在节点,返回值为指向该节点的指针
tree *tree_search(const tree *, int);

//在有序二叉树里插入数字
int tree_insert(tree *, int);

//以前序遍历方式处理有序二叉树里所有节点
void tree_fiter(const tree *, p_func_t);

//以中序遍历方式处理有序二叉树里所有节点
void tree_miter(const tree *, p_func_t);

//以后序遍历方式处理有序二叉树里所有节点
void tree_liter(const tree *, p_func_t);

//计算树的最大深度（高度），返回值为高度整数
int tree_max_height(const tree *);

/*************************************************/

//树的初始化函数
void tree_init(tree *p_tree)
{
    p_tree->p_node = NULL; //代表没有节点的空树
}

//树的清理函数
void tree_deinit(tree *p_tree)
{
    if (!p_tree->p_node)
    {
        return;
    }
    else
    {
        tree_deinit(&p_tree->p_node->left);  //递归调用清理左子树
        tree_deinit(&p_tree->p_node->right); //递归调用清理右子树
        free(p_tree->p_node);                //释放根节点
        p_tree->p_node = NULL;
    }
}
//在有序二叉树里查找某个数字所在位置
tree *tree_search(const tree *p_tree, int val) //返回值为指向该数字的指针
{
    if (!p_tree->p_node) //树是空的
    {
        return (tree *)p_tree;
    }
    if (p_tree->p_node->val == val) //根节点里的数字就是要找的
    {
        return (tree *)p_tree;
    }
    else if (val < p_tree->p_node->val) //根节点的树比需要找的数大，则要找的数字在左子树里
    {
        return tree_search(&p_tree->p_node->left, val);
    }
    else //根节点的树比需要找的数小，则要找的数字在右子树里
    {
        return tree_search(&p_tree->p_node->right, val);
    }
}
//在有序二叉树里插入数字
int tree_insert(tree *p_tree, int val)
{
    tree *p_tr = tree_search(p_tree, val); //查找插入数字的位置
    if (p_tr->p_node)
    {
        //找到的节点已经放着要查找的数字，则不能插入数字
        return 0;
    }
    node *p_new = (node *)malloc(sizeof(node)); //新建一个节点
    if (!p_new)
    {
        //分配内存失败，节点创建失败
        return 0;
    }
    p_tr->p_node = p_new;      //将新节点填入找到的位置，即把上面找到的指针指向新节点
    p_new->val = val;          //将数字填入
    p_new->left.p_node = NULL; //把指针置空，防止出现野指针
    p_new->right.p_node = NULL;
    return 1;
}
//以中序遍历方式处理有序二叉树里所有节点
void tree_miter(const tree *p_tree, p_func_t p_func)
{
    if (!(p_tree->p_node))
    {
        return;
    }
    tree_miter(&(p_tree->p_node->left), p_func); //中序遍历左子树
    p_func(p_tree->p_node->val);
    tree_miter(&(p_tree->p_node->right), p_func); //中序遍历右子树
}
//以前序遍历方式处理有序二叉树里所有节点
void tree_fiter(const tree *p_tree, p_func_t p_func)
{
    if (!(p_tree->p_node))
    {
        return;
    }
    p_func(p_tree->p_node->val);                  //先处理根节点
    tree_miter(&(p_tree->p_node->left), p_func);  //前序遍历左子树
    tree_miter(&(p_tree->p_node->right), p_func); //前序遍历右子树
}
//以后序遍历方式处理有序二叉树里所有节点
void tree_liter(const tree *p_tree, p_func_t p_func)
{
    if (!(p_tree->p_node))
    {
        return;
    }
    tree_miter(&(p_tree->p_node->left), p_func);  //后序遍历左子树
    tree_miter(&(p_tree->p_node->right), p_func); //后序遍历右子树
    p_func(p_tree->p_node->val);                  //最后处理根节点
}
//计算树的最大深度（高度），返回值为高度整数
int tree_max_height(const tree *p_tree)
{
    int left_height = 0, right_height = 0;
    if (!p_tree->p_node)
    {
        return 0;
    }
    left_height = tree_max_height(&p_tree->p_node->left);//递归调用计算左子树高度
    right_height = tree_max_height(&p_tree->p_node->right);//递归调用计算右子树高度
    return (left_height > right_height ? left_height : right_height) + 1;//比较两个高度返回大的并加一就是树的高度
}

#endif