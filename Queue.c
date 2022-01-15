#include <stdio.h>
#include <stdlib.h>

typedef struct QNode Node;
typedef Node* Queue;
struct QNode {
	int* Data;
	int First;
	int Last;
	int MaxSize;
};

Queue
newQueue (int maxsize) {
	Queue Q=(Queue)malloc(sizeof(Node));
	Q->Data=(int*)malloc(maxsize*sizeof(int));
	Q->First=Q->Last=0;
	Q->MaxSize=maxsize;
	return Q;
}
void
push (Queue Q,int X) {
	if (Q->Last==Q->First+1) {
		return;
	}
	Q->Data[Q->First]=X;
	if (++Q->First==Q->MaxSize) {
		Q->First=0;
	}
}
#define ERROR 1919810
int
pop (Queue Q) {
	if (Q->First==Q->Last) {
		return ERROR;
	}
	int ret=Q->Data[Q->Last];
	if (++Q->Last==Q->MaxSize) {
		Q->Last=0;
	}
	return ret;
}
void
print (Queue Q) {
	int x=pop(Q);
	while (x!=ERROR) {
		printf("%-3d",x);
		x=pop(Q);
	}
	printf("\n");
}
void
printAll (Queue Q) {
	int i;
	for (i = 0; i < Q->MaxSize; i += 1) {
		printf("%-3d",Q->Data[i]);
	}
	printf("\n");
}
int
main (int argc, char *argv[]) {
	int m,n,x;
	Queue Q=newQueue(10);
	scanf("%d",&m);
	while (m--) {
		scanf("%d",&n);
		while (n--) {
			scanf("%d",&x);
			push(Q,x);
		}
		print(Q);
	}
	return 0;
}
