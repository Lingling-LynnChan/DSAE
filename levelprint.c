#define N 100
#define ERROR -114514
void
p (int arr[][N],BinTree AVL,int level,int i) {
	if (!AVL) {
		return;
	}
	p(arr,AVL->Left,level+1,i+1);
	arr[level][i++]=AVL->Data;
	p(arr,AVL->Right,level+1,i+1);
}
void
print (BinTree AVL) {
	int arr[N][N],i,j;
	for (i = 0; i < N; i += 1) {
		for (j = 0; j < N; j += 1) {
			arr[i][j]=ERROR;
		}
	}
	p(arr,AVL,0,0);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(arr[i][j]!=ERROR)
				printf("%-4d",arr[i][j]);
	printf("\n");
}
