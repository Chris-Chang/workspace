//山寨版printf()
//头文件stdarg.h提供了一组方便使用可变长参数的宏

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

void tiny_printf(char *format, ...)
{
    int i;
    va_list ap;

    va_start(ap, format);
    for(i = 0; format[i] != '\0'; i++){
        switch(format[i]){
            case 's':
                printf("%s ", va_arg(ap, char*));
                break;
            case 'd':
                printf("%d ", va_arg(ap, int));
                break;
            default:
                assert(0);
        }
    }

    va_end(ap);
    putchar('\n');
}

int main(void)
{
    tiny_printf("sddd", "result..", 3, 5,8);
    return 0;
}
