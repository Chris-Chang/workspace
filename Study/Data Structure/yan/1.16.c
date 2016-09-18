#include <stdio.h>

int main()
{
    int a,b,c,temp;
    scanf("%d%d%d",&a,&b,&c);
    if(a<b){
        temp=b;
        b=a;
        a=temp;
    }
    if(b<c){
        temp=c;
        c=b;
        if(temp<=a)b=temp;
        else{
            b=a;
            a=temp;
        }
    }
        printf("%d %d %d",a,b,c);
        return;
}
