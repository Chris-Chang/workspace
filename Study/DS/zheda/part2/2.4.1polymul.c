//  设计函数分别求两个一元多项式的乘积与和
//  ### 输入样例:
//  4 3 4 -5 2 6 1 -2 0 //3x4-5x2+6x-2
//  3 5 20 -7 4 3 1 //5x20-7x4+3x
//  ### 输出样例:
//  15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1


#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode{
    int coef;
    int expon;
    Polynomial link;
};

/*由于c语言函数参数赋值是值传递的形式，所以pRear为指针的指针*/
void Attach(int c, int e, Polynomial *pRear)
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;/*对新节点赋值*/
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;/*修改pRear的值*/
}

Polynomial ReadPoly()
{
    Polynomial P,Rear,t;
    int c,e,N;
    scanf("%d",&N);
    P=(Polynomial)malloc(sizeof(struct PolyNode));//链表头空结点
    P->link=NULL;
    Rear=P;
    while(N--){
        scanf("%d%d",&c,&e);
        Attach(c,e,&Rear);//将当前项插入多项式尾部
    }
    t=P;P=P->link;free(t);/*删除临时生成的头结点*/
    return P;
}


/*多项式相乘*/
Polynomial Mult(Polynomial P1, Polynomial P2)
{
    Polynomial P,Rear,t1,t2,t;
    int c,e;
    if(!P1||!P2)return NULL;
    t1 = P1;t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while(t2){
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2 = t2->link;
    }
    t1=t1->link;
    while(t1){
        t2=P2;Rear = P;
        while(t2){
            e = t1->expon + t2->expon;
            c = t1->coef*t2->coef;
            while(Rear->link && Rear->link->expon>e)
                Rear=Rear->link;
            if(Rear->link && Rear->link->expon==e){
                if(Rear->link->coef+c)
                    Rear->link->coef+=c;
                else{
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            }
            else{
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = P;
    P = P->link;
    free(t2);
    return P;
}

/*将多项式输出*/
void PrintPoly(Polynomial P)
{
    /*输出多项式*/
    int flag = 0;   /*辅助调整输出格式用*/
    if(!P)
    {
        printf("0 0\n");
        return;
    }
    while(P){
        if(!flag)
            flag=1;
        else
        printf(" ");
        printf("%d %d",P->coef,P->expon);
        P = P->link;
    }
    printf("\n");
}

int main()
{
    Polynomial P,P1,P2;
    P1 =  ReadPoly();
    P2 =  ReadPoly();
    P = Mult(P1,P2);
    PrintPoly(P);
    return 0;
}
