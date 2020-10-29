#define _CRT_SECURE_NO_WARNINGS 1
//自定义类型：结构体，枚举，联合
// char int short long float double 都是内置类型--c语言自己的数据类型
//但是面对复杂类型比如 书 人等  我们可以创建自定义类型 
//结构体
//①结构体类型的声明
//②结构体的自引用
//③结构体变量的定义和初始化
//④结构体内存对齐
//⑤结构体传参
//⑥结构体实现位段（位段的填充&可移植性）


//①结构体类型的声明
//结构是一些值的集合，这些值是成员变量。结构的每个成员可以是不同类型的变量

//③结构体变量的定义和初始化
//#include<stdio.h>
////结构体里面可以包含结构体
//struct T
//{
//	double weight;
//	short age;
//};
//struct S
//{
//	char c;
//	struct T st;  
//	int a;
//	double d;
//	char arr[20];
//};
//int main()
//{
//	struct S s = { 'a',{78.5,20},4,3.14,"hello bit" };  //遇见结构体初始化就要用大括号来进行定义
//	printf("%c  %lf %d %d %lf %s", s.c,s.st.weight,s.st.age, s.a, s.d, s.arr);
//	return 0;
//}

//结构体内存对齐
//struct S1
//{
//	char c1;
//	int a;
//	char c2;
//};
//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
//
//int main()
//{
//	struct S1 s1 = { 0 };//      只要第一个结构体内容初始化为0 ，后面的结构体内容也默认初始化为0
//	printf("%d\n", sizeof(s1));   //12     s1 和s2 只是将他们结构体内的内容进行了位置的调换，并没有改变
//	struct S2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));//8
//	return 0;
//}  //vs默认的对齐数是8

//double 占几个字节来着？ 给忘记了 8个字节

//①第一个成员在于结构体变量偏移量为0的地址处
//②其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处
//③结构体总大小为最大对齐数的整数倍
//④如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整数大小就是所有最大对齐数的整数倍

//#pragma  pack()   修改对齐数
//offsetof()括号里面是要求谁的偏移量
//#include<stddef.h>
//#include<stdio.h>
//struct S
//{
//	char c;
//	int i;
//	double d;
//};
//int main()
//{
//	printf("%d\n", offsetof(struct S,c));
//	printf("%d\n", offsetof(struct S, i));
//	printf("%d\n", offsetof(struct S, d));
//	return 0;
//}

//⑤结构体传参
//要传结构体的地址


//⑥位段  的目的就是为了节省空间的


//枚举
//枚举--顾名思议就是 --列举
//枚举的优点
//1.增加代码的可读性和可维护性
//2.和#define定义的标识符比较枚举有类型检查，更加严谨
//3.放置了命名污染
//4.便于调试
//5.使用方便，一次可以定义多个变量


//枚举
//①枚举类型的定义
//②枚举的优点
//③枚举的使用




//联合
//①联合类型的定义
//②联合的特点
//③联合大小的计算

//联合（共用体）
//联合类型的定义：联合也是一种特殊的自定义类型，这种类型定义的变量也包含一系列的成员，☆特征是这些成员公用同一块空间（所以联合也叫共用体）
#include<stdio.h>
//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union Un u;
//	printf("%d\n", sizeof(u));
//	printf("%p\n", &u);
//	printf("%p\n", &u.c);
//	printf("%p\n", &u.i);
//	return 0;
//}

//int check_sys()
//{
//	union Un
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (1 == ret)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//联合体的大小至少是里面最大成员的大小
//当最大成员大小不是最大对齐的整数倍的时候，就要对齐到最大对齐数的整数倍

//union Un
//{
//	int a; //  4  vs(8)  对齐数是4
//	char arr[5];  //5     1   vs（8） 对齐数是1   5不是最大对齐数4的整数倍所以 要对齐 就找到了8
//};
//int main()
//{
//	union Un u;
//	printf("%d\n", sizeof(u));
//	return 0;
//}


#include <stdio.h>
int main()
{
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5] = { 6,7,8,9,10 };
	int i = 0;
	for (i = 0;i < 5;i++)
	{
		int tmp = 0;    //这里根本不需要将tmp也定义为数组形式，因为每次循环一次就只交换一个数
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	for (i = 0;i < 5;i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (i = 0;i < 5;i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}