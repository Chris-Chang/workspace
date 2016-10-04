
//该节为1.2.2内容
#include <stdio.h>

int main()
{
    int hoge = 5;
    int piyo = 10;
    int *hoge_p;

    /*输出每个变量的地址*/
    printf("&hoge..%p\n",&hoge);
    printf("piyo..%p\n",&piyo);
    printf("&hoge_p..%p\n",&hoge_p);

    /*将hoge的地址赋予hoge_p*/
    hoge_p = &hoge;
    printf("hoge_p..%p\n",hoge_p);

    /*通过hoge_p输出hoge的内容*/
    printf("*hoge_p..%d\n", *hoge_p);


    /*通过hoge_p修改hoge的内容*/
    *hoge_p = 10;
    printf("hoge..%d\n", hoge);

    return 0;
}
