#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read()/* 细节在此不表 */
{
    int n;
    List  P,rear,t;
    scanf("%d",&n);
    P = (PtrToNode)malloc(sizeof(struct Node));
    P->Next = NULL;
    rear = P;
    while(n--){
        t = (PtrToNode)malloc(sizeof(struct Node));
        scanf("%d",&(t->Data));
        t->Next = NULL;
        rear->Next = t;
        rear = t;
    }
    return P;
}
void Print( List L ) /* 细节在此不表；空链表将输出NULL */
{
    int flag = 0;
    if(!(L->Next)){
         printf("NULL");
    }else{
        L = L->Next;
        while(L){
            if(!flag){
                flag = 1;
            }else{
                printf(" ");
            }
            printf("%d",L->Data);
            L = L->Next;
        }
    }
        printf("\n");

}
List Merge( List L1, List L2 )
{
    List L,rear,t,t1,t2;
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    rear = L;
    t1 = L1->Next;
    t2 = L2->Next;
    while(t1&&t2){
        while(t2&&t1){
            if(t2->Data >= t1->Data ){
                rear->Next = t1;
                rear = t1;
                t1 = t1->Next;
                rear->Next= NULL;
                break;
            }else{
                rear->Next= t2;
                rear = t2;
                t2 = t2->Next;
                rear->Next= NULL;
                break;
            }
        }

    }
    if(t1) rear->Next = t1;
    if(t2) rear->Next = t2;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;

}

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
