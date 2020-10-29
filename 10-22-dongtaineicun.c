#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<errno.h>

//动态内存管理
//为什么存在动态内存分配
//动态内存函数的介绍
//malloc
//free
//calloc
//relloc

//栈区  局部变量， 函数的形式参数    返回数据和返回地址 
//堆区  动态内存分配  
//静态区  全局变量 静态变量（static）

//数组内的数组个数要给定一个常量，不能是变量

//malloc  和free  一定要共同使用
//这个函数向内存申请一块连续可用的空间，并返回指向整块空间的指针
//如果开辟成功，则返回一个指向开辟好空间的指针
//如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查
//返回值的类型是void*，所以malloc函数并不知道开辟空间的类型，具体在使用的时候使用者自己决定

//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int)); // malloc（这里面是字节）  
//	if (p == NULL)
//	{
//		//打印错误信息的一个方式
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0;i < 10;i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0;i < 10;i++)
//		{
//			printf("%d ", *(p + i));
//		}
//		//当动态申请的空间不再使用的时候
//		//就应该还给操作系统
//		free(p);//  我把这个空间还给操作系统但是发现指针还是指向原来开辟的地址位置  万一后续有人用了p那么他就会直接找到这个地址，很危险
//		p = NULL;//可以避免犯错误  他就再也不会再能找到这个空间了
//	}
//	return 0;
//}


//与函数malloc的区别只是在于calloc会在返回地址之前把申请的空间的每个字节初始化为0

//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int)); // malloc（这里面是字节）  
//	if (p == NULL)
//	{
//		//打印错误信息的一个方式
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		/*for (i = 0;i < 10;i++)
//		{
//			*(p + i) = i;
//		}*/
//		for (i = 0;i < 10;i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//释放空间
//	//free函数是用来释放动态开辟的空间的
//	free(p);
//	p = NULL;
//	return 0;
//}

//realloc 可以调整开辟的动态内存的大小  如果开辟大了就可以使用它来减少，少了就可以减少

//
//int main()
//{
//	int* p = (int*)malloc(20); // malloc（这里面是字节）  
//	if (p == NULL)
//	{
//		//打印错误信息的一个方式
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0;i < 5;i++)
//		{
//			*(p + i) = i;
//		}
//	}
	//就是在使用malloc开辟的20个字节空间
	//假设这里，20个字节不能满足我们的使用了
	//希望我们能够有40个字节的空间
	//这里可以使用realloc来调整动态开辟的内存

//realloc的注意事项
//1.如果p指向的空间之后有足够的内存空间可以追加，则直接追加，后返回p
//2.如果p指向的空间之后没有足够的内存空间可以追加，则realloc函数会重新找一个新的内存区域
//开辟一块满足需求的空间，并且把原来内存中的数据拷贝回来，释放旧的内存空间，最后返回新开辟的内存空间地址
////3.得用一个新的变量来接收realloc函数的返回值
//	int* ptr = realloc(p, INT_MAX);
//	if (ptr != NULL)
//	{
//		p = ptr;
//		int i = 0;
//		//这里是p2追加弥补的数字
//		for (i = 5;i < 10;i++)
//		{
//			*(ptr + i) = i;
//		}
//		//这里的for循环只是单纯的在进行循环打印
//		for (i = 0;i < 10;i++)
//		{
//			printf("%d ", *(ptr + i));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;	


//1.malloc可以返回的指针是NULL  不能对其进行解引用
//2.不能进行越界访问  你开辟的空间40个字节  你却访问了超过40个字节的空间内容
//3.这里你定义的整形变量在栈区，但是free释放的是堆区的内容  所以这也是一种常见的错误
	/*int a = 10;
	int* p = &a;
	*p = 20;
	free(p);
	p = NULL;*/
//4.使用free释放动态内存的一部分  *p++ = i ；对于这个指针p已经指向了你说开辟空间的最后面，你在去free他，但是他后面的内容是没有的
// 5.同一个空间多次释放  两次free
// 6. 开辟了空间却忘记释放（内存泄漏的情况）  
//}
//
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);   //这里的p是形式参数（局部参数），出了GetMemory p指针所开辟的空间消失  ，str依旧还是NULL，
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}

//请问test函数会输出什么？
//随机值
//返回栈空间地址 容易出现问题
//非法访问栈空间  
//char* GetMemory(void)
//{
//	char p[] = "hello world";   //这个p数组是一个局部数组，除了这个空间 ，就自动销毁了
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;

//对于这个函数  static 会使局部变量a的生命周期变长，除了这个局部变量依旧 具备着记忆功能

//int* test()
//{
//	static int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	*p = 20;
//	return 0;
//}

//对于malloc所开辟的空间在堆区  ，不对malloc进行free 他就具备着记忆功能
//int* test()
//{
//	int* ptr = malloc(100);
//	return ptr;
//}
//int main()
//{
//	int* p = test();
//	return 0;
//}

//忘记释放动态内存空间，导致内存泄漏
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	/*free(str);
//	str = NULL;*/
//}
//int main()
//{
//	Test();
//	return 0;
//}


//free（str） 对其进行释放，但是并不代表他为NULL
// 



//柔性数组
//对于结构体中，最后一个元素可以是未知大小的内容--称为柔性数组;
//对于柔性数组的开辟创建应该是用malloc来进行

//柔性数组的好处1.可以做到一次性完全释放所开辟的空间
//2.提高了访问的速度

//柔性数组的特点
//1.结构中的柔性数组成员前面必须至少一个其他成员
//2.sizeof返回的这种结构体大小不包括柔性数组的内存
//3.包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小
//
//struct S
//{
//	int a;
//	int arr[];  //  这里的arr数组是不知道大小的，所以他为柔性数组
//};
////这里需要来测试一下这个结构体占了多少个字节
//int main()
//{
//	printf("%d", sizeof(struct S));
//	return 0;
//}

//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));//这里就是一次性将所有都开辟，这样指针就可以一次性都能访问到
//	ps->a = 100;
//	int i = 0;
//	for (i = 0;i < 5;i++)
//	{
//		ps->arr[i] = i;
//	}
//	struct S* ptr = realloc(ps,44);
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	for (i = 0;i < 10;i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	return 0;
//}

//struct S
//{
//	int n;
//	int* arr;  
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));  //相当于我开辟了一个struct S 结构体大小的空间
//	ps->arr = malloc(5 * sizeof(int));
//	int i = 0;
//	for (i = 0;i < 5;i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0;i < 5;i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	return 0;
//}



