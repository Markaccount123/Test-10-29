#define _CRT_SECURE_NO_WARNINGS 1
//本章重点
//strlen
//对于strlen的定义  前面的返回值是 size_t  这个是通过typdef 重新定义了  代表的 意思是unsigned int
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;    //我们都会在这里认为这里返回的和haha  但是确实hehe  因为strlen返回的是无符号整形  -3的补码是一个很大的数字且大于0所以>0
//}
//在使用strcpy的时候拷贝数组内容 源字符串必须要自己带有\0


//strncpy 拷贝num个字符从源字符串到目标空间
//如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后面追加0，直到num个




//字符分割
//#include<stdio.h>     //当ret等于NULL的时候就会停止
//#include<string.h>
//int main()
//{
//	char arr[] = "zpw@bitedu.tech";
//	char* p = "@.";
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	char* ret = NULL;
//	for (ret = strtok(arr, p);ret != NULL;ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	/*ret = strtok(arr, p);
//	printf("%s\n", ret);
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);*/
//	return 0;
//}

//strerror  可以把相应的errno数字码转换为 用户可读的信息让用户更加清楚明白的了解错误的地方原因

//islower()  isdight()  字符分类函数
#include<stdio.h>
#include<ctype.h>
//int main()
//{
	//char ch = 'q';
	//int ret = islower(ch);  // 如果是小写那就会返回一个大于0的数字，当不是小写的时候就会返回0
	//char ch = '@';
	//int ret = isdigit(ch);
	//printf("%d\n", ret);

	//char ch = tolower('Y');
	//char ch = toupper('b');
	//putchar(ch); //打印一个字符


	//字符转换函数
//	char arr[] = "I AM Student";
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	return 0;
//}


//	内存函数讲解
//  strcpy是有一定限制的  因为他叫字符串拷贝， 
//	void* 是通用类型指针 --  空指针  
//  void* memcpy(void* destination,const void* source,size_t num);
//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
	/*int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	strcpy(arr2, arr1);*///   对于这个你会发现拷贝不过来只会显示一个1，因为strcpy是字符串拷贝一次只能拷贝一个字节，而你的数组形式是整形
	//在内存中的存储是小端模式，所以01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 一次拷贝一个字节 到第二个发现00 是\0退出

	//所以这里需要memcpy，无论什么模式的都可以进行拷贝。
	/*struct S arr3[] = { {"张三",20},{"李四",30} };
	struct S arr4[] = { 0 };
	memcpy(arr4, arr3,sizeof(arr3));
	return 0;
}*/


//自己实现一个my_memcpy 的函数
//#include<stdio.h>
//#include<assert.h>
//struct S
//{
//	char name[20];
//	int age;
//};
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	void* ret = dest;
//	while (num--)
//	{                   //  这里的void* 是空指针 你不能对他解引用或者++  --进行操作运算
//		*(char*)dest = * (char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}
//
//int mian()
//{
//	struct S arr3[] = { {"张三",20},{"李四",30} };
//	struct S arr4[] = { 0 };
//	my_memcpy(arr4, arr3, sizeof(arr3));
//	return 0;
//}


//memmove  处理重叠内存拷贝
//int arr[] = {1,2,3,4,5,6,7,8,9,10}  我想要把1,2,3,4,5 的内容放到  4,5，6,7,8上面  就需要调用 memmove函数了

//当dest落在了src的左边，应该是从前往后去拷贝
//当dest落在了src和src+count内的时候，应该从后向前拷贝
//当dest落在了src+count以外  既可以从前向后拷贝，也可以从后向前拷贝

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[10] = { 0 };
//	memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}
//
//void* my_memmove(void* dest, void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	if (dest<src)
//	{
//		//从前向后
//		while(num--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	//从后向前
//	else
//	{
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };  //适用与同一个数组内把1-5的内容 转移到  3-7的位置上面
//	my_memmove(arr1+2, arr1, 5);
//	return 0;
//}

//或者把1和3组合  把2单独作为一种判断方式
  //(dest<src || dest>(char*)src + num)  src是空指针不能直接加num来表示越过多少个字节

//memcmp  这里比较的是内存

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,4,3 };
//	int ret = memcmp(arr1, arr2, 9);  //  这里的9代表和memcpy等是一样的  都是字节的个数
//	printf("%d\n", ret);   //  如果arr1>arr2 那么就会 输出一个大于0的数  相等为0  小于是<0的数字
//	return 0;             //  但是在vs编译器下面输出大于0的数是1  小于0的数是-1
//}

//memset  内存设置

int main()
{
	//char arr[10] = "";
	//memset(arr, '#', 10);
	//int i = 0;
	//for (i = 0;i < 10;i++)
	//{
	//	printf("%c", arr[i]);
	//}
	return 0;
}