//数组和指针的微妙关系

#include <stdio.h>

int main(void)
{
    int array[5];
    int *p;
    int i;

    /*给数组array的各元素设定值*/
    for(i=0; i<5; i++){
        array[i] = i;
    }

    /*输出数组各元素的值(指针版)*/
    for(p = &array[0]; p != &array[5]; p++){
        printf("%d\n", *p);
    }

    /*利用指针输出数组各元素的值--改写版*/
    p = &array[0];
    for(i=0; i < 5; i++){
        printf("%d\n", *(p+i));
    }
    return 0;
}
