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
    t = P;
    P = P->Next;
    free(t);
    return P;
}
void Print( List L ) /* 细节在此不表；空链表将输出NULL */
{
    int flag = 0;
    if(!L){
         printf("NULL");
    }else{
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
List Merge( List *L1, List *L2 )
{
    List L,rear,t;
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    rear = L;
    while(*L1){
        while(*L2){
            if((*L2)->Data > (*L1)->Data ){
                rear->Next = *L1;
                rear = *L1;
                *L1 = (*L1)->Next;
                rear->Next= NULL;
                break;
            }else{
                rear->Next= *L2;
                rear = *L2;
                *L2 = (*L2)->Next;
                rear->Next= NULL;
                break;
            }
        }

    }
    if(*L1){
        rear->Next = *L1;
        while(*L1)
        *L1 = (*L1)->Next;
    }
    if(*L2){
        rear->Next = *L2;
         while(*L2)
         *L2 = (*L2)->Next;

    }
    t = L;
    L = L->Next;
    free(t);
    return L;

}

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(&L1, &L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
