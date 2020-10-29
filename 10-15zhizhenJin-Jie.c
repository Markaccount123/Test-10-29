
//二维数组
//int a[3][4] = { 0 };
//printf("%d\n", sizeof(a)); 
//printf("%d\n", sizeof(a[0][0]));
//printf("%d\n", sizeof(a[0]));   a[0]相当于第一行作为一维数组的数组名
//printf("%d\n", sizeof(a[0] + 1));  第一行第二个元素   ☆☆☆非常重要
//printf("%d\n", sizeof(*(a[0] + 1)));
//printf("%d\n", sizeof(a + 1));  a是二维数组的数组名，没有sizeof(数组名)，也没有&（数组名），所以a是首元素地址
                                        //而把二维数组看成一维数组时，二维数组的首元素是他的第一行，a就是第一行的（首元素）地址
//printf("%d\n", sizeof(*(a + 1)));
//printf("%d\n", sizeof(&a[0] + 1));
//printf("%d\n", sizeof(*(&a[0] + 1)));
//printf("%d\n", sizeof(*a));
//printf("%d\n", sizeof(a[3]));  sizeof内部是不参与计算的，也就是sizeof不会真的去访问第四行，他只是关注他的类型   答案是16
#include<stdio.h>
//int main()
//{
//    int a[5] = { 1,2,3,4,5 };
//    int* ptr = (int*)(&a + 1);
//    printf("%d,%d\n", *(a + 1), *(ptr - 1));
//    return 0;    //2   ? 答案是5
//}


//struct Test
//{
//    int Num;
//    char* pcName;
//    short sDate;
//    char cha[2];
//    short sBa[4];
//}* p;
////假设p的值为 0x100000.  如下表达式是多少？
////结构体的字节大小是20字节
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
//    int a[4] = { 1,2,3,4 }; // 数组的存储在计算机中是小端模式  01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00
//    int* ptr1 = (int*)(&a + 1);
//    int* ptr2 = (int*)((int)a + 1);  //a是首元素地址 假设地址为0x00000005 强制转化为整型是5 + 1  是6  在转换为整型指针类型 0x00000006 就是比开始多跳转一个字节
//    printf("%x,%x", ptr1[-1], *ptr2);  // 4  02000000  在十六进制中前面的0可以省略   %x 有代表的是什么  以十六进制的方式进行打印
//    return 0;
//}
////ptr1[-1]  等价于 *（ptr1 - 1）
//
//
//int main()
//{
//    int a[3][2] = { (0,1),(2,3),(4,5) };//按理来说应该用{}来进行元素的初始化，但是可得小心这里面用的是逗号的表达式 其他未初始化的 默认为0
//    int* p;
//    p = a[0];
//    printf("%d", p[0]);
//    return 0;
//}
//
//int main()
//{
//    int a[5][5];
//    int(*p)[4];  //对于数组指针来说每次+1就是跳过整个数组那么多的字节大小空间
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
//    char* a[] = { "work","at","alibaba" };  //a是一个常量字符指针数组  char* p = "abcdef";是把首元素的地址给这个字符指针
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
    printf("%s\n",cpp[-1][-1] + 1);   //  EW      //对于这个cpp并么有发生变化指向的还是和上面那个一样的
    return 0;
}