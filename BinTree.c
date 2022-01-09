#include <stdio.h>
#include <stdlib.h>

typedef struct TNode Node;
typedef Node* PtrToNode;
typedef PtrToNode BinTree;

struct TNode {
	int Data;
	PtrToNode Left;
	PtrToNode Right;
};

BinTree
newTree() {
	return NULL;
}
BinTree
setTree(int X) {
	BinTree BST=(BinTree)malloc(sizeof(Node));
	BST->Data=X;
	BST->Left=BST->Right=NULL;
	return BST;
}
PtrToNode
findMin(BinTree BST) {
	if (!BST->Left) {
		return BST;
	}else {
		return findMin(BST->Left);
	}
}
PtrToNode
findMax(BinTree BST) {
	if (!BST->Right) {
		return BST;
	}else {
		return findMax(BST->Right);
	}
}
BinTree
addTree(BinTree BST,int X) {
	if (!BST) {
		BST=setTree(X);
	}else 
		if (BST->Data>X) {
			BST->Left=addTree(BST->Left,X);
		}else 
			if(BST->Data<X) {
			BST->Right=addTree(BST->Right,X);
			}
	return BST;
}

BinTree
deleteTree(BinTree BST,int X) {
	if (!BST) {
		return NULL;
	}else 
		if (BST->Data>X) {
			BST->Left=deleteTree(BST->Left,X);
		}else 
			if (BST->Data<X) {
				BST->Right=deleteTree(BST->Right,X);
			}else {
				if (BST->Left&&BST->Right) {
					BinTree Del=findMin(BST->Right);
					BST->Data=Del->Data;
					BST->Right=deleteTree(BST->Right,Del->Data);
				}else {
					BinTree Del=BST;
					if (!BST->Right) {
						BST=BST->Left;
					}else 
						if (!BST->Left) {
							BST->Right;
						}
				free(Del);
				}
			}
	return BST;
}
void
DLR(BinTree BST) {
	if (!BST) {
		return;
	}else {
		printf("%d ",BST->Data);
		DLR(BST->Left);
		DLR(BST->Right);
	}
}
void
LDR(BinTree BST) {
	if (!BST) {
		return;
	}else {
		LDR(BST->Left);
		printf("%d ",BST->Data);
		LDR(BST->Right);
	}
}
void
LRD(BinTree BST) {
	if (!BST) {
		return;
	}else {
		LRD(BST->Left);
		LRD(BST->Right);
		printf("%d ",BST->Data);
	}
}


int
main (int argc, char *argv[]) {
	BinTree BST=newTree();
	int n,x;
	scanf("%d",&n);
	while (n--) {
		scanf("%d",&x);
		BST=addTree(BST,x);
	}
	printf("删除前：\n");
	DLR(BST);
	printf("\n");
	LDR(BST);
	printf("\n");
	LRD(BST);
	printf("\n");
	scanf("%d",&x);
	BST=deleteTree(BST,x);
	printf("删除后：\n");
	DLR(BST);
	printf("\n");
	LDR(BST);
	printf("\n");
	LRD(BST);
	printf("\n");
	return 0;
}
