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
	S->Top=-1;
	S->MaxSize=maxsize;
	return S;
}
void
push (Stack S,int X) {
	if (S->Top+1==S->MaxSize) {
		printf("ERR_FULL::1919810\n");
		exit(1);
	}
	S->Top++;
	S->Data[S->Top]=X;
}
#define ERR_EMPTY -114514
int
pop (Stack S) {
	if (S->Top==-1) {
		return ERR_EMPTY;
	}
	int ret=S->Data[S->Top];
	S->Top--;
	return ret;
}
void
importIntime (Stack S) {
	int i,h;char ch;
	scanf("%d%c",&i,&ch);
	push(S,i);
	while (ch!='='&&ch!='\n') {
		if (ch=='+'||ch=='-') {
			scanf("%d",&i);
			if (ch=='-') {
				i=-i;
			}
			push(S,i);
		}else
			if (ch=='*') {
				scanf("%d",&i);
				h=pop(S);
				i*=h;
				push(S,i);
			}else {
				printf("ERR_WRONG_IMPORT::114514\n");
				exit(1);
			}
		scanf("%c",&ch);
	}
}
int
math (Stack S) {
	int i=pop(S),sum=0;
	while (i!=ERR_EMPTY) {
		sum+=i;
		i=pop(S);
	}
	return sum;
}
int
main (int argc, char *argv[]) {
	Stack S=newStack(10);
	importIntime(S);
	int sum=math(S);
	printf("%d\n",sum);
	return 0;
}
