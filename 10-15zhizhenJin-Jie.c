
//��ά����
//int a[3][4] = { 0 };
//printf("%d\n", sizeof(a)); 
//printf("%d\n", sizeof(a[0][0]));
//printf("%d\n", sizeof(a[0]));   a[0]�൱�ڵ�һ����Ϊһά�����������
//printf("%d\n", sizeof(a[0] + 1));  ��һ�еڶ���Ԫ��   ����ǳ���Ҫ
//printf("%d\n", sizeof(*(a[0] + 1)));
//printf("%d\n", sizeof(a + 1));  a�Ƕ�ά�������������û��sizeof(������)��Ҳû��&����������������a����Ԫ�ص�ַ
                                        //���Ѷ�ά���鿴��һά����ʱ����ά�������Ԫ�������ĵ�һ�У�a���ǵ�һ�еģ���Ԫ�أ���ַ
//printf("%d\n", sizeof(*(a + 1)));
//printf("%d\n", sizeof(&a[0] + 1));
//printf("%d\n", sizeof(*(&a[0] + 1)));
//printf("%d\n", sizeof(*a));
//printf("%d\n", sizeof(a[3]));  sizeof�ڲ��ǲ��������ģ�Ҳ����sizeof�������ȥ���ʵ����У���ֻ�ǹ�ע��������   ����16
#include<stdio.h>
//int main()
//{
//    int a[5] = { 1,2,3,4,5 };
//    int* ptr = (int*)(&a + 1);
//    printf("%d,%d\n", *(a + 1), *(ptr - 1));
//    return 0;    //2   ? ����5
//}


//struct Test
//{
//    int Num;
//    char* pcName;
//    short sDate;
//    char cha[2];
//    short sBa[4];
//}* p;
////����p��ֵΪ 0x100000.  ���±��ʽ�Ƕ��٣�
////�ṹ����ֽڴ�С��20�ֽ�
//
//int main()
//{
//    printf("%p\n", p + 0x1);
//    printf("%p\n", (unsigned long)p + 0x1);
//    printf("%p\n", (unsigned int*)p + 0x1);
//    return 0;
//}
//
//int main()
//{
//    int a[4] = { 1,2,3,4 }; // ����Ĵ洢�ڼ��������С��ģʽ  01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00
//    int* ptr1 = (int*)(&a + 1);
//    int* ptr2 = (int*)((int)a + 1);  //a����Ԫ�ص�ַ �����ַΪ0x00000005 ǿ��ת��Ϊ������5 + 1  ��6  ��ת��Ϊ����ָ������ 0x00000006 ���Ǳȿ�ʼ����תһ���ֽ�
//    printf("%x,%x", ptr1[-1], *ptr2);  // 4  02000000  ��ʮ��������ǰ���0����ʡ��   %x �д������ʲô  ��ʮ�����Ƶķ�ʽ���д�ӡ
//    return 0;
//}
////ptr1[-1]  �ȼ��� *��ptr1 - 1��
//
//
//int main()
//{
//    int a[3][2] = { (0,1),(2,3),(4,5) };//������˵Ӧ����{}������Ԫ�صĳ�ʼ�������ǿɵ�С���������õ��Ƕ��ŵı��ʽ ����δ��ʼ���� Ĭ��Ϊ0
//    int* p;
//    p = a[0];
//    printf("%d", p[0]);
//    return 0;
//}
//
//int main()
//{
//    int a[5][5];
//    int(*p)[4];  //��������ָ����˵ÿ��+1������������������ô����ֽڴ�С�ռ�
//    p = a;
//    printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//}

////
//int main()
//{
//    int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//    int* ptr1 = (int*)(&aa + 1);
//    int* ptr2 = (int*)(*(aa + 1));
//    printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//    return 0;
//}

//int main()
//{
//    char* a[] = { "work","at","alibaba" };  //a��һ�������ַ�ָ������  char* p = "abcdef";�ǰ���Ԫ�صĵ�ַ������ַ�ָ��
//    char** pa = a;
//    pa++;
//    printf("%s\n", *pa);
//    return 0;
//}
//


int main()
{
    char* c[] = { "ENTER","NEW","POINT","FIRST" };
    char** cp[] = { c + 3,c + 2,c + 1,c };
    char*** cpp = cp;

    printf("%s\n",**++cpp);//POINT
    printf("%s\n",*--*++cpp +3);//ER
    printf("%s\n",*cpp[-2] + 3);//ST
    printf("%s\n",cpp[-1][-1] + 1);   //  EW      //�������cpp��ô�з����仯ָ��Ļ��Ǻ������Ǹ�һ����
    return 0;
}