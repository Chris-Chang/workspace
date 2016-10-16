#include <stdio.h>

/*二叉树的二叉链表结点结构定义*/
typedef struct BiTNode	/*结点结构*/
{
	TElemType data;	/*结点数据*/
	struct BiTNode *lchild, *rchild;	/*左右孩子指针*/
}BiTNode, *BiTree;


/*二叉树的前序遍历递归算法*/
void PreOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	printf("%c",T->data);/*显示结点数据，可以更改为其他对结点操作*/
	PreOrderTraverse(T->lchild);/*再先序遍历左子树*/
	PreOrderTraverse(T->rchild);/*最后先序遍历右子树*/
}

/*二叉树的中序遍历算法*/
void InOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild);/*先中序遍历左子树*/
	printf("%c",T->data);/*显示结点数据，可以更改为其他对结点操作*/
	InOrderTraverse(T->rchild);/*最后遍历右子树*/
}

/*二叉树的后序遍历算法*/
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild);/*先后序遍历左子树*/
	PostOrderTraverse(T->rchild);/*最后遍历右子树*/
	printf("%c",T->data);/*显示结点数据，可以更改为其他对结点操作*/
}


/*按前序输入二叉树中结点的值(一个字符)*/
/*#表示空树，构造二叉链表表示二叉树T*/
void CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c",ch);
	if(ch=="#")
		*T=NULL;
	else{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=ch;/*将值赋予该结点*/
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}