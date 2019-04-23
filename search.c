#include <stdio.h>
//二分查找
int *half_search(const int *p_val, int size, int val)
{
    const int *start = p_val, *end = p_val + size - 1, *mid = NULL;
    while (start <= end)
    {
        //每次循环排除一半的存储区
        mid = start + (end - start + 1) / 2;
        if (*mid == val) //如果中间的就是要查找的数字
        {
            return (int *)mid; //返回地址  mid是const类型，返回时需要强制转换
        }
        else if (*mid > val) //中间数比要找的大
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return NULL;
}
void main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int c = 0;
    printf("请输入一个数字：");
    scanf("%d", &c);
    int *b = half_search(a, 10, c);
    if (b)
    {
        printf("找到了!\n");
    }
    else
    {
        printf("没有找到！\n");
    }
}
// * * * * * * * * * *
// 0 1 2 3 4 5 6 7 8 9