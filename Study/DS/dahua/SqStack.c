/*
顺序栈
栈的抽象数据类型
ADT 栈(stack)
Data
    同线性表。元素具有相同的类型，相邻元素具有前驱和后继关系
Operation
    InitStack(*S)：初始化操作，建立一个空栈S
    ClearStack(*S):将栈清空
    StackEmpty(S):若栈为空，返回true,否则返回false
    GetTop(*S,*e):若栈存在且非空，用e返回S的栈顶元素
    Push(*S,e):若栈存在，插入新元素e到栈S中并成为栈顶元素
    Pop(*S,*e):删除栈S中栈顶元素，并用e返回其值
    StackTraverse(*S):遍历栈中所有元素
    StackLength(S):返回栈S的元素个数
endADT
 */


#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW        -1
#define STACK_INIT_SIZE 10
#define STACKINCREMENT   2
#define OK               1
#define ERROR            0
#define TRUE             1
#define FALSE            0

#define MAXSIZE          100    /*设定栈最大值*/

typedef int SElemType;  /*SElemType类型根据实际情况而定，这里假设为int*/
typedef int Status;

/*当栈存在一个元素时，top等于0,因此通常把空栈的条件定位top等于-1*/
/*栈的结构定义*/
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
}SqStack;

/*初始化栈*/
Status InitStack(SqStack *S)
{
    S->top=-1;
    return OK;
}

/*清空栈*/
Status ClearStack(SqStack *S)
{
    S->top=-1;
    return OK;
}

/*判断栈是否为空,-1为空*/
Status StackEmpty(SqStack *S)
{
    if(S->top==-1)
        return TRUE;
    else
        return FALSE;
}

/*若栈非空，返回栈顶元素*/
Status GetTop(SqStack *S, SElemType *e)
{
    if(S->top==-1)return ERROR;
    else *e = S->data[S->top];
    return OK;
}


/*进栈，插入元素e为新的栈顶元素*/
Status Push(SqStack *S, SElemType e)
{
    if(S->top == MAXSIZE - 1)/*栈满*/
    {
        return ERROR;
    }
    S->top++;   /*栈顶指针增加一*/
    S->data[S->top]=e;  /*将新插入元素赋值给栈顶空间*/
    return OK;
}

/*出栈,若栈不为空，则删除s的栈顶元素，用e返回其值，并返回OK,否则返回ERROR*/
Status Pop(SqStack *S, SElemType *e)
{
    if(S->top==-1)
        return ERROR;   /*栈空*/
    *e = S->data[S->top];   /*将要删除的栈顶元素赋值给e*/
    S->top--;   /*栈顶指针减一*/
    return OK;
}

/*遍历栈中所有元素*/
Status StackTraverse(SqStack *S, Status (* visit)(SElemType))
{
   int n,i;
   n=S->top;
   for(i=n;i>=0;i--){
   visit(S->data[i]);
   }
   printf("\n");
   return OK;
}

/*返回栈S的元素个数*/
int StackLength(SqStack *S)
{
    return S->top+1;
}

/*显示元素格式*/
Status visit(SElemType e)
{
    printf("%d ",e);
    return OK;
}

int main()
{
    SqStack s;
    int e;
    printf("InitStack初始化栈并将1--12压入栈\n");
    if(InitStack(&s))
        for(e = 1; e <= 12; e++)
        {
            Push(&s,e);
        }
    printf("StackTraverse栈中元素从栈顶依次为:\n");
    StackTraverse(&s,visit);
    Pop(&s,&e);
    printf("Pop弹出的元素为:%d\n",e);
    Pop(&s,&e);
    printf("Pop又弹出的元素为:%d\n",e);
    printf("Push将刚刚弹出的元素%d再次压入\n",e);
    Push(&s,e);
    printf("StackEmpty判断栈是否为空:%d(1:是 0:不是)\n",StackEmpty(&s));
    GetTop(&s,&e);
    printf("GetTop当前栈顶元素为:%d\n",e);
    printf("StackLength:当前栈长度为%d \n",StackLength(&s));
    ClearStack(&s);
    printf("ClearStack栈清空后，StackEmpty栈是否为空%d(1:是 0:不是)\n",StackEmpty(&s));
    DestroyStack(&s);
    printf("DestroyStack栈销毁");
    return 0;

}
