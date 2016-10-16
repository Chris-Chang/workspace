/*
任意一棵树，它的结点的第一个孩子如果存在就是唯一的，它的右兄弟如果存在也是唯一的。因此，我们
设置两个指针，分别指向该结点的第一个孩子和此结点的右兄弟
 */

/*树的孩子兄弟表示法结构定义*/
typedef struct CSNode
{
	TElemType data;
	struct CSNode *firstchild, *rightsib;
}CSNode,*CSTree;