//��һ�½����нṹ��Ľ���
//�ṹ��һЩֵ�ļ��ϣ���Щֵ��Ϊ��Ա�������ṹ��ÿ����Ա�����ǲ�ͬ���͵ı���
//����һ��ѧ��
//���֣����䣬�绰���Ա�
//struct �ṹ��ؼ���   Stu  �ṹ���ǩ   struct Stu - �ṹ������
//struct Stu
//{
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//};
//
//���ݽṹ--�������ݽṹ
//����˳���ջ���Ƚ��ĺ����������ȳ���������


//1��ʵ�ֺ���init��ʼ������Ϊ0��2.ʵ��print����������ӡ�����ÿ��Ԫ�أ�ʵ��reverse���������������Ԫ�ص���ת
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
//2.������A�е����ݺ�����B�е����ݽ��н���������һ����
//ֻ��Ҫ����һ����ʳ�����Ϳ�����
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


//������

////ȫ�ֱ�������ʼ��-Ĭ����0
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a;// a=6,c=6
//	b = ++c, c++,++a, a++;  //c=8 b =7; a= 8                    ����һ�����ű��ʽ�����������õ������һ�����ʽ������ҲҪ����˳�����
//	b += a++ + c;
//	printf("a = %d b = %d c = %d\n", a, b, c);
//	return 0;
//}