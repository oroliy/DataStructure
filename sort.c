#include <stdio.h>
//冒泡排序
void bubble_sort(int *p_val, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (*(p_val + j) < *(p_val + j + 1)) //从小到大
			{
				*(p_val + j) ^= *(p_val + j + 1);
				*(p_val + j + 1) ^= *(p_val + j);
				*(p_val + j) ^= *(p_val + j + 1);
			}
		}
	}
}
//选择排序
void choice_sort(int *p_val, int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (*(p_val + i) < *(p_val + j)) //从小到大
			{
				*(p_val + i) ^= *(p_val + j);
				*(p_val + j) ^= *(p_val + i);
				*(p_val + i) ^= *(p_val + j);
			}
		}
	}
}
//插入排序
void insert_sort(int *p_val, int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (*(p_val + j) > *(p_val + j + 1))
			{
				*(p_val + j) ^= *(p_val + j + 1);
				*(p_val + j + 1) ^= *(p_val + j);
				*(p_val + j) ^= *(p_val + j + 1);
			}
			else
			{
				break;
			}
		}
	}
}
//快速排序
void quick_sort(int *p_val, int size)
{
	int base = *p_val; //记录最开始的数字
	int *p_start = p_val, *p_end = p_val + size - 1;
	//定义两个指针指向两头的数字来进行比较
	if (size <= 1)
	{
		//当需要处理的数字只有一个，结束
		return;
	}
	while (p_start < p_end) //p_start < p_end的时候说明指针相遇，调整完成
	{
		if (*p_start > *p_end) //前面的数字比后面的大，调换
		{
			*p_start ^= *p_end;
			*p_end ^= *p_start;
			*p_start ^= *p_end;
		}
		//把非选定数字排除在外，并使两个指针一个指向base 一个指向下一个需要处理的数字
		if (*p_start == base) //说明选择的数字比较小
		{
			//结尾的指针前移，把大的数字放在右侧
			p_end--;
		}
		else
		{
			//把小的数字放在左侧，p_start右移移位处理下一个，此时*p_end==base
			p_start++;
		}
		//递归处理左侧的数字，从第一个开始，到base结束
		quick_sort(p_val, p_start - p_val);
		//从选定数字下一个开始处理右侧的数字，个数为总个数减去左侧的
		quick_sort(p_start + 1, size - 1 - (p_start - p_val));
	}
}
void main()
{
	int a[8] = {30, 10, 80, 50, 40, 20, 60, 70};
	//bubble_sort(a, 8);
	//choice_sort(a, 8);
	//insert_sort(a, 8);
	quick_sort(a, 8);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}