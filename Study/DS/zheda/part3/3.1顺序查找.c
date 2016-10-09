#include <stdio.h>

typedef struct LNode *List;
struct LNode{
    ElementType Element[MAXSIZE];
    int Length;
};
typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode{ /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
};
/*顺序查找*/
int SequentialSearch(List Tbl, ElementType K)
{/*在Element[1]~Element[n]中查找关键字为k的数据元素*/
    int i;
    Tbl->Element[0] = K;/*建立哨兵*/
    for(i=Tbl->Length;Tbl->Element[i]!=K;i--);
    return i;
    /*查找成功返回所在单元下标，不成功返回0时间复杂度为O(n)*/
}

/*二分查找*/
int BinarySearch(List Tbl, ElementType K)
{   /*在表Tbl中查找关键字为K的数据元素*/
    int left,right,mid,NotFound = -1;

    left=1; /*初始左边界*/
    right=Tbl->Length;/*初始右边界*/
    while(left<=right)
    {
        mid = (left+right)/2;/*计算中间元素坐标*/
        if(K<Tbl->Element[mid])     right = mid-1;/*调整右边界*/
        else if(K>Tbl->Element[mid]) left = mid+1;/*调整左边界*/
        else return mid;/*查找成功返回数据元素的下标*/
    }
    return NotFound;
}
