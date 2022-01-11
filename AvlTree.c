#include <stdio.h>
#include <stdlib.h>

typedef struct TNode Node;
typedef Node* BinTree;

struct TNode {
	int Data;
	int Height;
	BinTree Left;
	BinTree Right;
};

int
max (int x,int y) {
	return x>y?x:y;
}
int
height (BinTree AVL) {
	if (!AVL) {
		return -1;
	}else {
		return AVL->Height;
	}
}
BinTree
singleLeft (BinTree AVL) {
	BinTree P=AVL->Left;
	AVL->Left=P->Right;
	P->Right=AVL;
	AVL->Height=max(height(AVL->Left),height(AVL->Right))+1;
	P->Height=AVL->Height;
	return P;
}
BinTree
singleRight (BinTree AVL) {
	BinTree P=AVL->Right;
	AVL->Right=P->Left;
	P->Left=AVL;
	AVL->Height=max(height(AVL->Left),height(AVL->Right))+1;
	P->Height=AVL->Height;
	return P;
}
BinTree
doubleLeft (BinTree AVL) {
	AVL->Left=singleRight(AVL->Left);
	return singleLeft(AVL);
}
BinTree
doubleRight (BinTree AVL) {
	AVL->Right=singleLeft(AVL->Right);
	return singleRight(AVL);
}
BinTree
insert (BinTree AVL,int X) {
	if (!AVL) {
		AVL=(BinTree)malloc(sizeof(Node));
		AVL->Height=0;
		AVL->Data=X;
		AVL->Left=AVL->Right=NULL;
		return AVL;
	}
	if (AVL->Data>X) {
		AVL->Left=insert(AVL->Left,X);
		if (height(AVL->Left)-height(AVL->Right)>1) {
			if (AVL->Left->Data>X) {
				AVL=singleLeft(AVL);
			}else {
				AVL=doubleLeft(AVL);
			}
		}
	}else
		if (AVL->Data<X) {
			AVL->Right=insert(AVL->Right,X);
			if (height(AVL->Right)-height(AVL->Left)>1) {
				if (AVL->Right->Data<X) {
					AVL=singleRight(AVL);
				}else {
					AVL=doubleRight(AVL);
				}
			}
		}
	AVL->Height=max(height(AVL->Left),height(AVL->Right));
	return AVL;
}
BinTree
minTree (BinTree AVL) {
	if (AVL->Left) {
		return minTree(AVL->Left);
	}
	return AVL;
}
BinTree
maxTree (BinTree AVL) {
	if (AVL->Right) {
		return maxTree(AVL->Right);
	}
	return AVL;
}
BinTree
delete (BinTree AVL,int X) {
	if (!AVL) {
		return NULL;
	}
	BinTree Del;
	if (AVL->Data>X) {
		AVL->Left=delete(AVL->Left,X);
		}
	}else
		if (AVL->Data<X) {
			AVL->Right=delete(AVL->Right,X);
		}else {
			if (AVL->Left&&AVL->Right) {
				Del=minTree(AVL->Right);
				AVL->Data=Del->Data;
				AVL->Right=delete(AVL->Right,Del->Data);
			}else {
				Del=AVL;
				if (!AVL->Left) {
					AVL=AVL->Right;
				}else {
					AVL=AVL->Left;
				}
				free(Del);
			}
		}
	return AVL;
}
void
print(BinTree AVL) {
	if (!AVL) {
		return;
	}
	print(AVL->Left);
	printf("%d ",AVL->Data);
	print(AVL->Right);
}

int
main (int argc, char *argv[]) {
	int n,x;
	BinTree AVL=NULL;
	scanf("%d",&n);
	while (n--) {
		scanf("%d",&x);
		AVL=insert(AVL,x);
	}
	print(AVL);
	printf("\n");
	scanf("%d",&x);
	AVL=delete(AVL,x);
	print(AVL);
	printf("\n");
	return 0;
}
