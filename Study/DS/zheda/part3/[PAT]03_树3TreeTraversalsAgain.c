#include <stdio.h>
#include <stdlib.h>

typedef struct BiTreeNode *PBiTree;
typedef struct BiTreeNode
{
	int data;
	PBiTree left;
	PBiTree right;
}BiTreeNode;

/*入栈*/
void Push(int *s,int e)
{
	s[0]++;
	s[s[0]]=e;
}

/*出栈*/
void Pop(int *s,int *order)
{
	order[0]++;/*数据个数加1*/
	order[order[0]]=s[s[0]];
	s[0]--;
}

/*生成中序访问序列*/
void CreateInorder(int n,int *stack,int *order)
{
	int i,e;
	char s[7];
	for(i=0;i<7;i++)s[i]='0';
	for(i=0;i<n*2;i++){
		scanf("%s",&s);
		if(s[2]=='s'){
			scanf("%d",&e);
			Push(stack,e);
		}else{
			Pop(stack,order);
		}
	}
}
int flag=0;

/*通过前序序列和中序序列创建树并打印出后序序列*/
void CreateTree(int *inorder, int *preorder, int length)
{
	if(length==0)
	{
		return;
	}
	PBiTree node = (PBiTree)malloc(sizeof(BiTreeNode));
	node->data=*preorder;
	int rootIndex=0;/*根节点在中序序列中的位置*/
	for(;rootIndex<length;rootIndex++)
	{
		if(inorder[rootIndex]==*preorder)
			break;
	}
	//左子树
	CreateTree(inorder,preorder+1,rootIndex);
	//右子树
	CreateTree(inorder+rootIndex+1,preorder+rootIndex+1,length-(rootIndex+1));
	if(flag==0)
		flag=1;
	else
		printf(" ");

	printf("%d",node->data);
	return;
}

int main()
{
int stack[31],inorder[31],n,i,preorder[31];
scanf("%d",&n);
stack[0]=0;
inorder[0]=0;
CreateInorder(n,stack,inorder);
for(i=0;i<n;i++)
{
	preorder[i]=i+1;
}
/*由于inorder[0]存放为元素个数，所以传递参数的时候+1，则形参数组第一个元素为inorder[1]*/
CreateTree(inorder+1,preorder,n);
printf("\n");
return 0;
}