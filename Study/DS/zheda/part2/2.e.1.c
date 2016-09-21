//线性结构2，一元多项式的乘法与加法运算
#include <stdio.h>
#include <stdlib.h>

typedef struct node *PolyNode;
struct node{
	int coef;
	int expo;
	PolyNode pnode; 
};

PolyNode readPoly()
{
	PolyNode p,tmp,rear;
	int n,c,e;
	scanf("%d",&n);
	p = (PolyNode)malloc(sizeof(struct node));
	p->coef=p->expo=0;
	p->pnode=NULL;
	rear = p;
	while(n--){
		scanf("%d %d",&c,&e);
		tmp = (PolyNode)malloc(sizeof(struct node));	
		tmp->coef=c;
		tmp->expo=e;
		rear->pnode=tmp;
		tmp->pnode=NULL;
		rear=tmp;
	}
	return p;
}

int printPoly(PolyNode p)
{
	int flag=0;
	if(!(p->pnode)){
		printf("0 0\n");	
		return 0;
	}else{
		p=p->pnode;	
	}
	while(p){
	if(!flag){
		flag+=1;	
	}else{
		printf(" ");	
	}	
	printf("%d %d",p->coef,p->expo);
	p=p->pnode;
	}
	printf("\n");
	return 0;
}

void attach(int coef, int expo, PolyNode *pRear)
{
	PolyNode tmp;
	tmp = (PolyNode)malloc(sizeof(struct node));
	tmp->coef=coef;
	tmp->expo=expo;
	tmp->pnode=NULL;
	(*pRear)->pnode=tmp;
	*pRear = tmp;
}

PolyNode mult(PolyNode p1, PolyNode p2)
{
	PolyNode p,Rear,t1,t2,t;
	int c, e;
	if(!p1||!p2)return NULL;
	t1 = p1;
	t2 = p2;
	t1 = p1->pnode;
	t2 = p2->pnode;
	p = (PolyNode)malloc(sizeof(struct node));
	p->coef = p->expo = 0;
	p->pnode = NULL;
	Rear = p;
	while(t2){
		c = t1->coef*t2->coef;
		e = t1->expo+t2->expo;
		attach(c,e,&Rear);
		t2 = t2->pnode;
	}
	t1=t1->pnode;
	while(t1){
		t2=p2->pnode;Rear=p;
		while(t2){
			c = t1->coef*t2->coef;
			e = t1->expo+t2->expo;
			while(Rear->pnode&&Rear->pnode->expo>e){
				Rear = Rear->pnode;	
			}
			if(Rear->pnode&&Rear->pnode->expo==e){
				if(Rear->pnode->coef+c){
					Rear->pnode->coef+=c;	
				}else{
					t = Rear->pnode;
					Rear->pnode = t->pnode;
					free(t);
				}	
			}else{
				t = (PolyNode)malloc(sizeof(struct node));	
				t->coef = c;
				t->expo = e;
				t->pnode = Rear->pnode;
				Rear->pnode = t;
				Rear=Rear->pnode;
			}
			t2=t2->pnode;
		}	
		t1=t1->pnode;
	}
	return p;
}

int compare(int a,int b)
{
	if(a>b)return 1;
	if(a==b)return 0;
	return -1;
}

PolyNode plus(PolyNode p1, PolyNode p2)
{
	PolyNode p,rear,tmp;
	int sum;
	p = (PolyNode)malloc(sizeof(struct node));
	p->pnode=NULL;
	rear=p;
	p1=p1->pnode;
	p2=p2->pnode;
	while(p1&&p2)
		switch(compare(p1->expo,p2->expo)){
			case 1:
				attach(p1->coef,p1->expo,&rear);
				p1=p1->pnode;
				break;
			case -1:
				attach(p2->coef,p2->expo,&rear);
				p2=p2->pnode;
				break;
			case 0:
				sum = p1->coef+p2->coef;
				if(sum)attach(sum,p1->expo,&rear);
				p1=p1->pnode;
				p2=p2->pnode;
				break;
				
		}

	for(;p1;p1=p1->pnode)attach(p1->coef,p1->expo,&rear);
	for(;p2;p2=p2->pnode)attach(p2->coef,p2->expo,&rear);
	rear->pnode=NULL;
	return p;
}

int main()
{
	PolyNode mul,plu,p1,p2;
	p1 = readPoly();
	p2 = readPoly();
	mul = mult(p1,p2);
	plu = plus(p1,p2);
	printPoly(mul);
	printPoly(plu);
	return 0;
}
