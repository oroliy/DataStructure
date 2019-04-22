#include <stdio.h>
#include "tree.h"

int tree_height(tree *, int *,int *);
void print_tree(int);
void main()
{
    tree test = {0};
    tree_init(&test);
    tree_insert(&test, 50);
    tree_insert(&test, 25);
    tree_insert(&test, 75);
    tree_insert(&test, 13);
    tree_insert(&test, 37);
    tree_insert(&test, 67);
    tree_insert(&test, 88);
    tree_insert(&test, 7);

    tree_fiter(&test, print_tree);
    printf("\n");
    tree_miter(&test, print_tree);
    printf("\n");
    tree_liter(&test, print_tree);
    printf("\n");

    int val1 = 0, val2 = 0, a = 0;
    a = tree_height(&test, &val1,&val2);
    printf("%d %d\n", val1,val2);
    tree_deinit(&test);
}
void print_tree(int val1)
{
    printf("%d ", val1);
}
int tree_height(tree *p_tree, int *p_val,int *p_val2)
{
    if (!p_tree->p_node)
    {
        return 0;
    }
    (*p_val)++;
    tree_height(&p_tree->p_node->left, p_val,p_val2);
    tree_height(&p_tree->p_node->right, p_val,p_val2);
    (*p_val2)++;
    return 0;
}