/*线索二叉树，线索化的实质就是将二叉链表中的空指针改为指向前驱或后继的线索
线索化的过程就是在遍历的过程中修改空指针的过程
*/

#include <stdio.h>

/*二叉树的二叉线索存储结构定义*/
typedef enum {Link,Thread} PointerTag;/*Link==0表示指向左右孩子指针*/
										/*Thread==1表示指向前驱或后继的线索*/
typedef struct BiThrNode	/*二叉线索存储结点结构*/
{
	TElemType data;	/*结点数据*/
	struct BiThrNode *lchild, *rchild;/*左右孩子结点指针*/
	PointerTag LTag;
	PointerTag RTag;	/*左右标记*/
}BiThrNode,*BiThrTree;

/*中序遍历线索化的递归函数*/
BiThrTree pre;/*全局变量，始终指向刚刚访问过的结点*/
				/*中序遍历进行中序线索化*/
void InThreading(BiThrTree p)
{
	if(p)
	{
		InThreading(p->lchild);/*递归左子树线索化*/

		if(!p->lchild)		/*没有左孩子*/
		{
			p->LTag=Thread;/*前驱线索*/
			p->lchild=pre;/*左孩子指针指向前驱*/
		}
		if(!pre->rchild)	/*前驱没有右孩子*/
		{
			pre->RTag=Thread;/*后继线索*/
			pre->rchild=p;/*前驱右孩子指针指向后继(当前结点p)*/
		}
		pre=p;/*保持pre指向p的前驱*/

		InThreading(p->rchild);/*递归右子树线索化*/
	}
}

/*遍历线索二叉树*/
/*T指向头结点，头结点左键lchild指向根结点，头结点右键rchild指向中序遍历的最后一个结点。
中序遍历二叉线索链表表示的二叉树T*/
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;/*p指向根结点*/
	while(p!=T)/*空树或遍历结束时，p==T*/
	{
		while(p->LTag==Link)/*当LTag==0时循环到中序序列第一个结点*/
			p=p->lchild;
		printf("%c",p->data);/*显示结点数据，可以更改为其他对结点操作*/
		while(p->RTag==Thread && p->rchild!=T)
		{
			p=p->rchild;
			printf("%c",p->data);
		}
		p=p->rchild;	/*p进至其右子树根*/
	}
	return OK;
}