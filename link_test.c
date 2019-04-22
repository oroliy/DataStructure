#include <stdio.h>
#include "link.h"
void main()
{
    int val = 0, size = 0;
    link test = {0};
    link_init(&test);
    link_add_head(&test, 20);
    link_add_head(&test, 10);
    link_append(&test, 90);
    link_append(&test, 100);
    link_insert(&test, 30);
    link_insert(&test, 80);
    link_remove(&test, 30);

    size = link_size(&test);
    for (int i = 0; i < size; i++)
    {
        link_get(&test, &val, i);
        printf("%d ", val);
    }
    printf("\n");
    link_get_head(&test, &val);
    printf("第一个数字是%d\n", val);
    link_get_tail(&test, &val);
    printf("最后一个数字是%d\n", val);
    link_deinit(&test);
/********************************************************/
    int c_val = 0, ret = 0;
    c_link c_test = {0};
    c_link_init(&c_test);
    c_link_add_head(&c_test, 20);
    c_link_add_head(&c_test, 10);
    c_link_append(&c_test, 90);
    c_link_append(&c_test, 100);
    c_link_insert(&c_test, 30);
    c_link_insert(&c_test, 80);
    c_link_remove(&c_test, 30);
    c_link_begin(&c_test);
    while (1)
    {
        ret = c_link_next(&c_test, &c_val);
        if (!ret)
        {
            break;
        }
        printf("%d ", c_val);
    }
    printf("\n");
    c_link_deinit(&c_test);
/********************************************************/
    c_val = 0, ret = 0;
    c_link c_r_test = {0};
    c_link_init(&c_r_test);
    c_link_add_head(&c_r_test, 20);
    c_link_add_head(&c_r_test, 10);
    c_link_append(&c_r_test, 90);
    c_link_append(&c_r_test, 100);
    c_link_insert(&c_r_test, 30);
    c_link_insert(&c_r_test, 80);
    c_link_remove(&c_r_test, 30);
    c_link_r_begin(&c_r_test);
    while (1)
    {
        ret = c_link_prev(&c_r_test, &c_val);
        if (!ret)
        {
            break;
        }
        printf("%d ", c_val);
    }
    printf("\n");
    c_link_deinit(&c_r_test);
}