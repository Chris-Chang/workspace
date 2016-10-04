//从英文的文本文件中将单词一个一个取出来
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//如果试图将数组作为函数参数进行传递，那就传递指向初始元素的指针
int get_word(char *buf, int buf_size, FILE *fp)
{
    int len;
    int ch;

    /*跳过读取空白符*/
    while((ch=getc(fp)) != EOF && !isalnum(ch));
    if(ch==EOF)
        return EOF;

    /*此时,ch中保存了单词的初始字符*/
    len = 0;
    do{
        buf[len] = ch;
        len++;
        if(len >= buf_size){
            /*由于单词太长，提示错误*/
            fprintf(stderr,"word too long.\n");
            exit(1);
        }
    }while((ch=getc(fp)) != EOF && isalnum(ch));
    buf[len] = '\0';

    return len;

}

int main(void)
{
    char buf[256];

while(get_word(buf,256, stdin) != EOF){
        printf("<<%s>>\n", buf);
    }

    return 0;
}
