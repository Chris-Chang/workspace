/*尾递归，一般都可以用循环实现*/
Position Find(ElementType X,BinTree BST)
{
	if(!BST)return NULL;/*查找失败*/
	if(X>BST->Data)
		return Find(X,BST->Right);/*在右子树中继续查找*/
	Else if(X<BST->Data)
		return Find(X,BST->Left);/*在左子树中继续查找*/
	else
		return BST;/*查找成功，返回结点的找到结点的地址*/
}

/*由于非递归函数的执行效率高，可将"尾递归"函数改为迭代函数*/
Position IterFind(ElementType X, BinTree BST)
{
	while(BST){
		if(X>BST->Data)
			BST=BST->Right;/*向右子树中移动，继续查找*/
		else if(X<BST->Data)
			BST=BST->Left;
	}
}

/*查找最小元素的递归实现*/
Position FindMin(BinTree BST)
{
	if(!BST)return NULL;/*空的二叉搜索树，返回NULL*/
	else if(!BST->Left)
		return BST;/*找到最左叶节点并返回*/
	else
		return FindMin(BST->Left);/*沿左分支继续查找*/
}


/*查找最大元素的迭代函数*/
Position FindMax(BinTree BST)
{
	if(BST)
		while(BST->Right)BST=BST->Right;

	return BST;
}