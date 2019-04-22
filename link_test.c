#include <stdio.h>
#include "link.h"
int main()
{
    int val=0,size=0;
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
    for(int i = 0; i < size; i++)
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
    
}