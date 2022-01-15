#include <stdio.h>
#include <stdlib.h>

typedef struct SNode Node;
typedef Node* Stack;
struct SNode {
	int* Data;
	int Top;
	int MaxSize;
};

Stack
newStack (int maxsize) {
	Stack S=(Stack)malloc(sizeof(Node));
	S->Data=(int*)malloc(maxsize*sizeof(int));
	S->MaxSize=maxsize;
	S->Top=-1;
	return S;
}
void
push (Stack S,int X) {
	if (S->Top+1==S->MaxSize) {
		return;
	}
	S->Data[++S->Top]=X;
}
#define ERROR 1919810
int
pop (Stack S) {
	if (S->Top==-1) {
		return ERROR;
	}
	return S->Data[S->Top--];
}
void
print (Stack S) {
	int x=pop(S);
	while (x!=ERROR) {
		printf("%-3d",x);
		x=pop(S);
	}
	printf("\n");
}

int
main (int argc, char *argv[]) {
	int n,x;
	scanf("%d",&n);
	Stack S=newStack(n);
	while (n--) {
		scanf("%d",&x);
		push(S,x);
	}
	print(S);
	return 0;
}
