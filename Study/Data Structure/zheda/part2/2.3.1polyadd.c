//2.3.1 多项式加法运算
struct PolyNode{
    int coef;//系数
    int expon;//指数
    struct PolyNode *link;//指向下一个节点的指针
};
typedef struct PolyNode *Polynomial;

Polynomial P1,P2;

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
    Polynomial front,rear,temp;
    int sum;
    rear = (Polynomial)malloc(sizeof(struct PolyNode));
    front = rear;//由front记录结果多项式链表头结点
    while(P1&&P2)//当两个多项式都有非零项等待处理时
        switch(Compare(P1->expon, P2->expon)){
            case 1:
                Attach(P1->coef, P1->expon, &rear);
                P1 = P1->link;
                break;
            case -1:
                Attach(P2->coef,P2->expon, &rear);
                P2=P2->link;
                break;
            case 0:
                sum=P1->coef+P2->coef;
                if(sum)Attach(sum,P1->expon,&rear);
                P1=P1->link;
                P2=P2->link;
                break;
        }
    //将未处理完的另一个多项式的所有节点一次复制到结果多项式中去
    for(;P1;P1=P1->link)Attach(P1->coef,P1->expon,&rear);
    for(;P2;P2=P2->link)Attach(P2->coef,P2->expon,&rear);
    rear->link=NULL;
    temp=front;
    front=front->link;//令front指向结果多项式第一个非零项
    free(temp);//释放临时空表头节点
}

void Attach(int c, int e, Polynomial *pRear)
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef=c;//对新节点赋值
    p->expon=e;
    P->link=NULL;
    (*pRear)->link=P;
    *pRear=P;//修改pRear的值
}
