#include <stdio.h>
#include <stdlib.h>

typedef struct TNode Node;
typedef Node* BinTree;

struct TNode {
	int Data;
	BinTree Left;
	BinTree Right;
};

void
printLevelTools (BinTree AVL,int level) {
	int i;
	if (!AVL) {
		for (i = 0; i < level; i += 1) {
			printf("  ");
		}
		printf("NULL\n");
		return;
	}
	printLevelTools(AVL->Right,level+1);
	for (i = 0; i < level; i += 1) {
		printf("  ");
	}
	printf("%04d\n",AVL->Data);
	printLevelTools(AVL->Left,level+1);
}
void
printLevel (BinTree AVL) {
	printLevelTools(AVL,0);
}
int
max (int x,int y) {
	return x>y?x:y;
}
int
getHeight (BinTree AVL) {
	if (!AVL) {
		return -1;
	}
	return max(getHeight(AVL->Left),getHeight(AVL->Right))+1;
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
newTree (void) {
	return NULL;
}
BinTree
newNode (int X) {
	BinTree AVL=(BinTree)malloc(sizeof(Node));
	AVL->Data=X;
	AVL->Left=AVL->Right=NULL;
	return AVL;
}
BinTree
LL (BinTree AVL) {
	if (AVL) {
		BinTree P=AVL->Left;
		AVL->Left=P->Right;
		P->Right=AVL;
		AVL=P;
	}
	return AVL;
}
BinTree
RR (BinTree AVL) {
	if (AVL) {
		BinTree P=AVL->Right;
		AVL->Right=P->Left;
		P->Left=AVL;
		AVL=P;
	}
	return AVL;
}
BinTree
LR (BinTree AVL) {
	if (AVL) {
		AVL->Left=RR(AVL->Left);
		AVL=LL(AVL);
	}
	return AVL;
}
BinTree
RL (BinTree AVL) {
	if (AVL) {
		AVL->Right=LL(AVL->Right);
		AVL=RR(AVL);
	}
	return AVL;
}
/*Upside is Tools*/
BinTree
addTree (BinTree AVL,int X) {
	if (!AVL) {
		return newNode(X);
	}
	if (AVL->Data>X) {
		AVL->Left=addTree(AVL->Left,X);
		if (getHeight(AVL->Left)-getHeight(AVL->Right)>1) {
			if (AVL->Left->Data>X) {
				AVL=LL(AVL);
			}else {
				AVL=LR(AVL);
			}
		}
	}else
		if (AVL->Data<X) {
			AVL->Right=addTree(AVL->Right,X);
			if (getHeight(AVL->Right)-getHeight(AVL->Left)>1) {
				if (AVL->Right->Data<X) {
					AVL=RR(AVL);
				}else {
					AVL=RL(AVL);
				}
			}
		}
	/*Adjust the balance*/
	return AVL;
}
BinTree
delTree (BinTree AVL,int X) {
	if (!AVL) {
		return NULL;
	}
	if (AVL->Data>X) {
		AVL->Left=delTree(AVL->Left,X);
		if (getHeight(AVL->Right)-getHeight(AVL->Left)>1) {
			if (getHeight(AVL->Right->Right)>getHeight(AVL->Right->Left)) {
				AVL=RR(AVL);
			}else {
				AVL=RL(AVL);
			}
		}
	}else
		if (AVL->Data<X) {
			AVL->Right=delTree(AVL->Right,X);
			if (getHeight(AVL->Left)-getHeight(AVL->Right)>1) {
				if (getHeight(AVL->Left->Left)>getHeight(AVL->Left->Right)) {
					AVL=LL(AVL);
				}else {
					AVL=LR(AVL);
				}
			}
		}else {
			if (AVL->Left&&AVL->Right) {
				BinTree Del=minTree(AVL->Right);
				AVL->Data=Del->Data;
				AVL->Right=delTree(AVL->Right,Del->Data);
				if (getHeight(AVL->Left)-getHeight(AVL->Right)>1) {
					if (getHeight(AVL->Left->Left)>getHeight(AVL->Left->Right)) {
						AVL=LL(AVL);
					}else {
						AVL=LR(AVL);
					}
				}
			}else {
				BinTree Del=AVL;
				if (!AVL->Left) {
					AVL=AVL->Right;
				}else {
					AVL=AVL->Left;
				}
				free (Del);
			}
		}
	return AVL;
}
BinTree
delAllTree (BinTree AVL) {
	if (AVL) {
		delAllTree(AVL->Left);
		delAllTree(AVL->Right);
		free(AVL);
	}
	return NULL;
}

int
main (int argc, char *argv[]) {
	int n,x;
	BinTree AVL=newTree();
	scanf("%d",&n);
	while (n--) {
		scanf("%d",&x);
		AVL=addTree(AVL,x);
	}
	printLevel(AVL);
	scanf("%d",&n);
	while (n--) {
		scanf("%d",&x);
		AVL=delTree(AVL,x);
	}
	printLevel(AVL);
	AVL=delAllTree(AVL);
	printLevel(AVL);
	return 0;
}
