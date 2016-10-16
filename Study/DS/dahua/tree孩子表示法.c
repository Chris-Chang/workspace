/*
孩子表示法
把每个结点的孩子结点排列起来，以单链表作为存储结构，则n个结点有n个孩子链表，如果是叶子结点则此
单链表为空。然后n个头指针又组成一个线性表，采用顺序存储结构，存放进一个一维数组中
 */
#define MAX_TREE_SIZE 100
typedef struct CTNode	/*孩子链表的孩子结点*/
{
	int child;
	struct CTNode *next;
}*ChildPtr;

typedef struct 		/*表头结构*/
{
	TElemType data;
	ChildPtr firstchild;
}CTBox;

typedef struct 		/*树结构*/
{
	CTBox nodes[MAX_TREE_SIZE];/*结点数组*/
	int r,n;/*根的位置和结点数*/
}CTree;