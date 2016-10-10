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
void InOrderTraversal(BinTree BT)
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

/*后序遍历*/
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


/*层序遍历
    核心:二维结构的线性化
    从结点访问其左右儿子结点
    访问左儿子后，右儿子结点怎么办
        需要一个存储结构保存暂时不访问的结点
        存储结构:堆栈、队列
    层序遍历基本过程：先根节点入队，然后:
    ①从队列中取出一个元素
    ②访问该元素所指结点
    ③若该元素所指结点的左右孩子结点非空
    则将其左右孩子的指针顺序入队
*/
void LevelOrderTraversal(BinTree BT)
{
    Queue Q;BinTree T;
    if(!BT)return;/*若是空树则直接返回*/
    Q = CreateQueue(MaxSize)/*创建并初始化队列Q*/
    AddQ(Q, BT);
    while(!IsEmptyQ(Q)){
        T=DeleteQ(Q);
        printf("%d\n",T->Data);/*访问取出队列的结点*/
        if(T->Left) AddQ(Q, T->Left);
        if(T->Right) AddQ(Q,T->Right);
    }
}

/*输出二叉树的叶子结点
    在二叉树的遍历算法中增加检测结点的"左右子树是否都为空"
*/

void PreOrderPrintLeaves(BinTree BT)
{
    if(BT){
        if(!BT->Left && !BT->Right)
            printf("%d",BT->Data);
        PreOrderPrintLeaves(BT->Left);
        PreOrderPrintLeaves(BT->Right);
    }
}

/*
求二叉树的高度
 */
int PostOrderGetHeight(BinTree BT)
{
    int HL, HR, MaxH;
    if(BT){
        HL=PostOrderGetHeight(BT->Left);/*求左子树的深度*/
        HR=PostOrderGetHeight(BT->Right);/*求右子树的深度*/
        MaxH = (HL>HR)?HL:HR;/*取左右子树较大的深度*/
        return (MaxH + 1);/*返回树的深度*/
    }
    else return 0;/*空树深度为0*/
}
