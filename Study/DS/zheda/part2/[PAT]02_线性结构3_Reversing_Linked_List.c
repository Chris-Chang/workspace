#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    int address;
    int data;
    int next;
    struct Link *pnext;
}Link, *PLink;

typedef struct LinkStack{
    PLink top;
    int count;
}*PLinkStack;

/*初始化单链表*/
int InitLink(PLink *l)
{
    (*l) = (PLink)malloc(sizeof(struct Link));
    (*l)->address = 0;
    (*l)->data = 0;
    (*l)->next = 0;
    (*l)->pnext = NULL;
    return 0;
}

int CreateLink(PLink *l, int ad, int e, int next)
{
    PLink pl,rear;
    rear = *l;
    pl = (PLink)malloc(sizeof(struct Link));
    pl->address=ad;
    pl->data = e;
    pl->next = next;
    pl->pnext = NULL;
    while(rear->pnext) rear=rear->pnext;
    rear->pnext = pl;
}

int PrintLink(PLink l)
{
    PLink p;
    int next;
    p = l->pnext;
    while(p){
        if(!(p->pnext))
        printf("%05d %d %d\n",p->address,p->data,-1);
        else
        printf("%05d %d %05d\n",p->address,p->data,p->pnext->address);

        p=p->pnext;
    }
    return 0;
}

int InitStack(PLinkStack *s)
{
    (*s) = (PLinkStack)malloc(sizeof(struct LinkStack));
    (*s)->top = NULL;
    (*s)->count = 0;
    return 0;
}

/*栈指针，压入的地址，数据，下一个地址*/
int Push(PLinkStack s,int ad, int e,int next)
{
    PLink p;
    p = (PLink)malloc(sizeof(struct Link));
    p->address = ad;
    p->data = e;
    p->next = next;
    p->pnext = s->top;
    s->top = p;
    s->count++;
    return 0;
}

/*栈指针，返回地址，数据，下一个地址*/
int Pop(PLinkStack s, int *ad, int *e, int *next)
{
    PLink tmp;
    *ad = s->top->address;
    *e = s->top->data;
    *next = s->top->next;
    tmp = s->top;
    s->top = tmp->pnext;
    s->count--;
    free(tmp);
    return 0;
}

/*搜索目标地址元素：单链表头指针，要搜索的地址，返回搜索的地址，数据，下一个地址*/
int Search(PLink *l, int tag, int *ad, int *e, int *next)
{
    PLink p,tmp;
    p = *l;
    while(p->pnext){
        if(p->pnext->address == tag){
             tmp = p->pnext;
            *ad = p->pnext->address;
            *e = p->pnext->data;
            *next = p->pnext->next;

            p->pnext = tmp->pnext;
            free(tmp);
            if(!(p->pnext))break;
        }
            p=p->pnext;
    }
    return 0;
}

int main()
{
    PLink p,ans;
    PLinkStack s,tmp;
    int head,n,m,k,h,address,data,next;
    scanf("%d%d%d",&head,&n,&k);
    m=k;
    h = n;
    InitLink(&p);
    InitLink(&ans);
    while(n--){
        scanf("%d%d%d",&address,&data,&next);
        CreateLink(&p,address,data,next);
    }
    InitStack(&s);
    InitStack(&tmp);
    while(h--){
        while(m--){
             if(head==-1){
                break;
            }
        Search(&p,head,&address,&data,&next);
        Push(s,address,data,next);
        head = next;
        }
        m=k;
        if(s->count==m){
            while(m--){
                Pop(s,&address,&data,&next);
                CreateLink(&ans,address,data,0);
            }
        }
        else{
            m=s->count;
            while(m--){
                Pop(s,&address,&data,&next);
                Push(tmp,address,data,next);
            }
            m=tmp->count;
            while(m--){
                Pop(tmp,&address,&data,&next);
                CreateLink(&ans,address,data,0);
            }
        }
    }
            PrintLink(ans);
    return 0;
}
