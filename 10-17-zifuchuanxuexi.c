#define _CRT_SECURE_NO_WARNINGS 1
//�����ص�
//strlen
//����strlen�Ķ���  ǰ��ķ���ֵ�� size_t  �����ͨ��typdef ���¶�����  ����� ��˼��unsigned int
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
//	return 0;    //���Ƕ�����������Ϊ���ﷵ�صĺ�haha  ����ȷʵhehe  ��Ϊstrlen���ص����޷�������  -3�Ĳ�����һ���ܴ�������Ҵ���0����>0
//}
//��ʹ��strcpy��ʱ�򿽱��������� Դ�ַ�������Ҫ�Լ�����\0


//strncpy ����num���ַ���Դ�ַ�����Ŀ��ռ�
//���Դ�ַ����ĳ���С��num���򿽱���Դ�ַ���֮����Ŀ��ĺ���׷��0��ֱ��num��




//�ַ��ָ�
//#include<stdio.h>     //��ret����NULL��ʱ��ͻ�ֹͣ
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

//strerror  ���԰���Ӧ��errno������ת��Ϊ �û��ɶ�����Ϣ���û�����������׵��˽����ĵط�ԭ��

//islower()  isdight()  �ַ����ຯ��
#include<stdio.h>
#include<ctype.h>
//int main()
//{
	//char ch = 'q';
	//int ret = islower(ch);  // �����Сд�Ǿͻ᷵��һ������0�����֣�������Сд��ʱ��ͻ᷵��0
	//char ch = '@';
	//int ret = isdigit(ch);
	//printf("%d\n", ret);

	//char ch = tolower('Y');
	//char ch = toupper('b');
	//putchar(ch); //��ӡһ���ַ�


	//�ַ�ת������
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


//	�ڴ溯������
//  strcpy����һ�����Ƶ�  ��Ϊ�����ַ��������� 
//	void* ��ͨ������ָ�� --  ��ָ��  
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
	strcpy(arr2, arr1);*///   ���������ᷢ�ֿ���������ֻ����ʾһ��1����Ϊstrcpy���ַ�������һ��ֻ�ܿ���һ���ֽڣ������������ʽ������
	//���ڴ��еĴ洢��С��ģʽ������01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 һ�ο���һ���ֽ� ���ڶ�������00 ��\0�˳�

	//����������Ҫmemcpy������ʲôģʽ�Ķ����Խ��п�����
	/*struct S arr3[] = { {"����",20},{"����",30} };
	struct S arr4[] = { 0 };
	memcpy(arr4, arr3,sizeof(arr3));
	return 0;
}*/


//�Լ�ʵ��һ��my_memcpy �ĺ���
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
//	{                   //  �����void* �ǿ�ָ�� �㲻�ܶ��������û���++  --���в�������
//		*(char*)dest = * (char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}
//
//int mian()
//{
//	struct S arr3[] = { {"����",20},{"����",30} };
//	struct S arr4[] = { 0 };
//	my_memcpy(arr4, arr3, sizeof(arr3));
//	return 0;
//}


//memmove  �����ص��ڴ濽��
//int arr[] = {1,2,3,4,5,6,7,8,9,10}  ����Ҫ��1,2,3,4,5 �����ݷŵ�  4,5��6,7,8����  ����Ҫ���� memmove������

//��dest������src����ߣ�Ӧ���Ǵ�ǰ����ȥ����
//��dest������src��src+count�ڵ�ʱ��Ӧ�ôӺ���ǰ����
//��dest������src+count����  �ȿ��Դ�ǰ��󿽱���Ҳ���ԴӺ���ǰ����

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
//		//��ǰ���
//		while(num--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	//�Ӻ���ǰ
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
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };  //������ͬһ�������ڰ�1-5������ ת�Ƶ�  3-7��λ������
//	my_memmove(arr1+2, arr1, 5);
//	return 0;
//}

//���߰�1��3���  ��2������Ϊһ���жϷ�ʽ
  //(dest<src || dest>(char*)src + num)  src�ǿ�ָ�벻��ֱ�Ӽ�num����ʾԽ�����ٸ��ֽ�

//memcmp  ����Ƚϵ����ڴ�

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,4,3 };
//	int ret = memcmp(arr1, arr2, 9);  //  �����9�����memcpy����һ����  �����ֽڵĸ���
//	printf("%d\n", ret);   //  ���arr1>arr2 ��ô�ͻ� ���һ������0����  ���Ϊ0  С����<0������
//	return 0;             //  ������vs�����������������0������1  С��0������-1
//}

//memset  �ڴ�����

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