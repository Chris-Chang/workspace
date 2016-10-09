#include <stdio.h>

/*先序遍历
访问根节点
先序遍历其左子树
先序遍历其右子树
*/

void PreOrderTraversal(BinTree BT)
{
    if(BT){
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}

/*中序遍历
中序遍历左子树
访问根节点
终须遍历又子树
*/
void PreOrderTraversal(BinTree BT)
{
    if(BT){
        PreOrderTraversal(BT->Left);
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Right);
    }
}

/*后序遍历
    后序遍历左子树
    后序遍历右子树
    访问根节点
*/

void PreOrderTraversal(BinTree BT)
{
    if(BT){
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
        printf("%d",BT->Data);
    }
}

/*中序遍历非递归遍历算法
    遇到一个结点，就把它压栈，并去遍历它的左子树
    当左子树遍历结束后，从栈顶弹出这个结点并访问它
    然后按其右指针再去中序遍历该结点的右子树
*/
void InOrderTraversal(BinTree BT)
{
    BinTree T=BT;
    Stack S = CreatStack(MaxSize);/*创建并初始化堆栈S*/
    while(T||!IsEmpty(S)){
        while(T){
            Push(S,T);
            T=T->Left;
        }
        if(!IsEmpty(S)){
            T=Pop(S);/*结点弹出堆栈*/
            printf("%5d",T->Data);/*访问打印结点*/
            T = T->Right;/*转向右子树*/
        }
    }
}

/*先序遍历的非递归遍历算法*/
void InOrderTraversal(BinTree BT)
{
    BinTree T=BT;
    Stack S=CreatStack(MaxSize);/*创建并初始化堆栈s*/
    while(T||!IsEmpty(S)){
        while(T){
            printf("%5d",T->Data);/*(访问打印节点)*/
            Push(S,T);
            T = T->Left;
        }
        if(!IsEmpty(S)){
            T=Pop(S);/*节点弹出堆栈*/
            T=T->Right;
        }
    }
}

void PostOrder(BiTree root){
    BiTNode *p,*q   //q指针是用来判别右孩子是否已经访问过
    Stack S;
    q = NULL;
    p = root;
    InitStack(&S);   //栈初始化
    while(p != NULL || !IsEmpty(S)){   //当p为空且栈中无任何元素时遍历完毕
        while(p != NULL){     将能访问的最左子树包括路径上的结点一起入栈
            Push(&S,p);
            p=p->LChild;
        }
        if(!IsEmpty(S)){  //如果栈不空
            GetTop(&S,&p);  //将p指向栈顶元素
            if((p -> RChild == NULL) || (p -> RChild == q)){  //无右孩子，或左孩子已经遍历过的话
                visit(p -> data);  //访问该结点
                q = p;           //保存到q,作为下一次已处理结点前驱
                Pop(&S,&p);      //栈顶元素出栈
                p = NULL;        //因为到目前为止p是这次子树遍历的最后一个结点，所以要开始遍历下一个子树，设p为NULL是为了跳过第8行的循环。毕竟不能                                                 //                                 倒回去遍历
            }
            else   //若该结点有右孩子且该右孩子还没有被访问的话
                p = p -> RChild;  //同样以LRD顺序遍历右子树
        }
    }
}
