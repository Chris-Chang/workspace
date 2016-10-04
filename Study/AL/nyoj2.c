#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
    char data;
    struct StackNode *next;
}StackNode, *LinkP;

typedef struct LinkStack{
    LinkP top;
    int count;
}LinkStack;

/*压栈*/
int push(LinkStack *S, char e){
    LinkP p = (LinkP)malloc(sizeof(struct StackNode));
    p->data  = e;
    p->next = S->top;
    S->top = p;
    S->count++;
    return 0;
}

/*出栈*/
char pop(LinkStack *S){
    LinkP p; ;
    char e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return e;
}

/*清空栈*/
int ClearStack(LinkStack *S){
    LinkP p;
    while(S->top){
        p = S->top;
        S->top = S->top->next;
        S->count--;
        free(p);
    }
    return 0;
}

int main()
{
    int n;
    char ru,chu,tmp;
    LinkStack s;
    scanf("%d",&n);
    getchar();
    s.top = NULL;
    s.count = 0;
    while(n--){
        ClearStack(&s);
        while((ru = getchar())!='\n'){
            if(!s.top){
                push(&s,ru);
            }else{
                if(ru=='(' || ru=='[')push(&s,ru);
                else{
                    if(ru==']'){
                        if(s.top->data=='[')pop(&s);
                        else push(&s,ru);
                    }
                    if(ru==')'){
                        if(s.top->data=='(')pop(&s);
                        else push(&s,ru);
                    }
                }
            }
        }
        if(!s.top){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
