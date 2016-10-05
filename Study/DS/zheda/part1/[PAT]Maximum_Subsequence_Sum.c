#include <stdio.h>

int MaxSum(int *a, int n,int *front, int *rear)
{
    int max, sum, i, t ;
    max = sum = 0;
    t = *front = 0;
    *rear = n-1;
    for(i=0;i<n;i++){
        sum+=a[i];
        if(sum<0){
            sum = 0;
            t = i+1;
        if(max==0&&a[t]==0&&t<n-1){
            *rear = t;
            *front = t;
        }
        }else if(sum>max&& *front<=t){
            *front = t;
            max = sum;
            *rear = i;
        }
     }
    return max;
}

int main()
{
    int max, i,n,a[10000], front, rear;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    max = MaxSum(a, n,&front, &rear);
    printf("%d %d %d", max, a[front], a[rear]);
    return 0;
}
