#include <stdio.h>
#include "tree.h"
void print_tree(int);
static int sum = 0;
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
    /*  tree_miter(&test, print_tree);
    printf("\n");
    tree_liter(&test, print_tree);
    printf("\n"); */

    int val = 0;
    printf("%d %d\n", tree_max_height(&test), sum);
    tree_deinit(&test);
}
void print_tree(int val)
{
    sum += val;
    printf("%d ", val);
}