/*
树的抽象数据类型
ADT 树(tree)
Data
	树是由一个根节点和若干棵子树构成，树中结点具有相同数据类型及层次关系
Operation
	InitTree(*T):构造空树
	DestroyTree(*T):销毁树T
	CreateTree(*T, definition):按definition中给出树的定义来构造树
	ClearTree(*T):若树存在，则将树T清为空树
	TreeEmpty(T):若为空树，返回true,否则返回false
	TreeDepth(T):返回树的深度
	Root(T):返回T的根节点
	Value(T,cur_e):cur_e是树T中的一个结点，返回此结点的值
	Assign(T,cur_e,value):给树T的结点cur_e赋值为value
	Parent(T,cur_e):若cur_e是树T的非根结点，则返回它的双亲，否则返回空
	LeftChild(T,cur_e):若cur_e是树T的非叶结点，则返回它的最左孩子，否则返回空
	RightSibling(T,cur_e):若cur_e有右兄弟，则返回它的右兄弟，否则返回空
	InsertChild(*T,*p,i,c):其中p指向树T的某个结点，i为所指结点p的度上加1，非空树c与T不相交，
	操作结果为插入c	为树T中p指结点的第i棵子树
	DeleteChild(*T,*p,i):其中p指向树T的某个结点，i为所指结点p的度，操作结果为删除T中p所指结点的第i棵子树
endADT
 */

/*树的双亲表示法结点结构定义*/
#define MAX_TREE_SIZE 100
typedef int TElemType;	/*树结点的数据类型，目前暂定为整型*/
typedef struct PTNode/*结点结构*/
{
	TElemType data;/*结点数据*/
	int parent;/*双亲位置*/
}PTNode;
typedef struct /*树结构*/
{
	PTnode nodes[MAX_TREE_SIZE];/*结点数组*/
	int r,n;	/*根的位置和结点数根节点双亲位置域为-1*/
}PTree;
