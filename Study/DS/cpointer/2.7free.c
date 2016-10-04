//调用free()后，对应的内存区域是不会立刻返回给操作系统的,但不能保证，因此free()之后，
//是不能引用对应的内存区域的

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *int_p;
    int_p = malloc(sizeof(int));

    *int_p = 12345;

    free(int_p);

    printf("*int_p..%d\n", *int_p);

    return 0;
}
