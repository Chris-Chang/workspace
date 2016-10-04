//1.3.1关于数组-运用数组

#include <stdio.h>

int main(void)
{
    int array[5];
    int i;

    /*为数组array的各元素设值*/
    for(i=0;i<5;i++){
        printf("%d\n",array[i]);
    }

    /*输出数组各元素值*/
    for(i=0;i<5;i++){
        printf("%d\n",array[i]);
    }

    /*输出数组各元素的地址*/
    for(i=0;i<5;i++){
        printf("&array[%d]..%p\n",i,&array[i]);
    }

    return 0;
}
