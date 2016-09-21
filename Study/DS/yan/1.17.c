#include <stdio.h>
#define MAX 1000    //定义数列最大项

//递归实现
int Fb1(int k, int m)
{
    if(m<k) return 0;
    else if((m==k)||(m==k+1)) return 1;
    else return 2*Fb1(k,m-1)-Fb1(k,m-k-1);
}

//循环实现
int Fb2(int k, int m)
{
    int Fn[MAX],i;
    for(i = 0; i < MAX; i++){
        if(i < k - 1){
            Fn[i] = 0;//前k-1项为0
            continue;
        }
        if(i == k - 1 || i == k){//k和k+1项为1
            Fn[i] = 1;
            continue;
        }
        Fn[i] = 2 * Fn[i-1] - Fn[i-k-1];
    }

    return Fn[m-1];
}

int main()
{
    int k,m,result,i;
    scanf("%d%d",&k,&m);
    printf("递归实现: %d ",Fb1(k,m));
    printf("循环实现: %d\n",Fb2(k,m));
    return 0;
}
