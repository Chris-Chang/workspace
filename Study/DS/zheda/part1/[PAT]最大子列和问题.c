#include <stdio.h>

int MaxSum(int *a, int n)
{
    int sum,i,max;
    sum = max= 0 ;
    for(i=0;i<n;i++){
    sum+=a[i];
    if(sum>max){
        max = sum;
    }else if(sum<0){
        sum = 0;
    }
    }
    return max;
}

int main()
{
    int n,i,max;
    int a[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    max = MaxSum(a,n);
    printf("%d\n",max);
    return 0;
}
