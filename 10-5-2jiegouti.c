//这一章将进行结构体的讲解
//结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量
//描述一个学生
//名字，年龄，电话，性别
//struct 结构体关键字   Stu  结构体标签   struct Stu - 结构体类型
//struct Stu
//{
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//};
//
//数据结构--线性数据结构
//链表，顺序表，栈（先进的后出，后进的先出），队列


//1、实现函数init初始化数组为0；2.实现print（）函数打印数组的每个元素；实现reverse（）函数完成数组元素的逆转
#include<stdio.h>
//void Init(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		arr[i] = 0;
//	}
//}
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//Init(arr,sz);
//	Print(arr, sz);
//	reverse(arr, sz);
//	Print(arr, sz);
//	return 0;
//}
//2.将数组A中的内容和数组B中的内容进行交换（数组一样大）
//只需要定义一个零食变量就可以了
//int main()
//{
//	int arr1[] = { 1,3,5,7,9 };
//	int arr2[] = { 2,4,6,8,10 };
//	int tmp = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr1[i] = tmp;
//	}
//	return 0;
//}


//三子棋

////全局变量不初始化-默认是0
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a;// a=6,c=6
//	b = ++c, c++,++a, a++;  //c=8 b =7; a= 8                    这是一个逗号表达式，真正有作用的是最后一个表达式，但是也要按照顺序进行
//	b += a++ + c;
//	printf("a = %d b = %d c = %d\n", a, b, c);
//	return 0;
//}