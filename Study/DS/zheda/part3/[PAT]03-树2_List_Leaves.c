#include <stdio.h>

#define MAXSIZE 10

struct TreeNode
{
	char left;
	char right;
}T1[MAXSIZE];

 int CreateTree(struct TreeNode T[])
{
	int n,i,check[MAXSIZE],root=-1;
	char cl,cr;
	scanf("%d",&n);
	getchar();
	if(n){
		for(i=0;i<n;i++) check[i]=0;
		for(i=0;i<n;i++){
			scanf("%c %c",&cl,&cr);
			getchar();
			if(cl!='-'){
				T[i].left=cl- '0';
				check[T[i].left]=1;
			}else{
				T[i].left=-1;
			}
			if(cr!='-'){
				T[i].right=cr- '0';
				check[T[i].right]=1;
			}else{
				T[i].right=-1;
			}
		}
		for(i=0;i<n;i++)
			if(check[i]==0)break;
		root=i;
	}
	return root;
}
// void PrePrintLeaves(struct TreeNode T[],int root)
// {
// 	if(root!=-1){
// 		if(T[root].left==-1 && T[root].right==-1){
// 			if(flag==0){
// 				flag=1;
// 			}else{
// 				printf(" ");
// 			}
// 			printf("%d",root);
// 		}
// 		 PrePrintLeaves(T,T[root].left);
// 		 PrePrintLeaves(T,T[root].right);
// 	}
// }


void AddQ(int *Q,int root)
{
	Q[0]++;
	Q[Q[0]]=root;
}

int DeleteQ(int *Q)
{
	int i,data;
	data=Q[1];
	i=Q[0];
	for(i=1;i<=Q[0];i++){
		Q[i]=Q[i+1];
	}
	Q[0]--;
	return data;
}
int flag=0;
void LevelPrintLeaves(struct TreeNode T[],int root)
{
	 int t,Q[MAXSIZE+1],i;
	 Q[0]=0;
	 for(i=1;i<MAXSIZE;i++)Q[i]=-1;
	if(root==-1) return;/*如果是空树则直接返回*/
	AddQ(Q,root);
	while(Q[0]){
		t= DeleteQ(Q);
		if(T[t].left==-1&&T[t].right==-1){
			if(flag==0){
				flag=1;
			}else{
				printf(" ");
			}
			printf("%d",t);
		}
		if(T[t].left!=-1){
			// printf("-%d:left:%d\n",t,T[t].left);
			AddQ(Q,T[t].left);
		}
		if(T[t].right!=-1){
			// printf("-%d:right:%d\n",t,T[t].right);
			AddQ(Q,T[t].right);
		}
	}
}



int main()
{
	int R;
	R = CreateTree(T1);
	LevelPrintLeaves(T1,R);
	printf("\n");
	return 0;
}