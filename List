#include<stdio.h>
#include<stdlib.h>

typedef struct LNode Node;
typedef Node* List;

struct LNode {
	int Data;
	List Next;
};

List
newList() {
	return NULL;
}
List
setList(int X,List Next) {
	List L=(List)malloc(sizeof(Node));
	L->Data=X;
	L->Next=Next;
	return L;
}
List
addList(List L,int X) {
	List P;
	if (!L) {
		P=setList(X,NULL);
		return P;		
	}else 
		if (!L->Next) {
			P=setList(X,NULL);
			L->Next=P;
			return L;
		}else {
			addList(L->Next,X);
			return L;
		}
}
List
deleteList(List L,int X) {
	List P;
	if (!L) {
		return L;
	}else 
		if (L->Data==X) {
			P=L->Next;
			free(L);
			L=P;
		}
	P=L;
	List Del=P->Next;
	while(Del){
		if (Del->Data==X) {
			P->Next=Del->Next;
			free(Del);
			Del=P->Next;
		}else {
			P=Del;
			Del=Del->Next;
		}
		
	}
	return L;
}
List
deleteAll(List L) {
	if (!L) {
		return NULL;
	}
	deleteAll(L->Next);
	free(L);
	return NULL;
}
void
printList(List L) {
	if (!L) {
		printf("\n");
		return;
	}
	printf("%d ",L->Data);
	printList(L->Next);
}

int
main (int argc, char *argv[]) {
	List L=newList();
	int n,x,N;
	scanf("%d",&n);
	N=n;
	while (n--) {
		scanf("%d",&x);
		L=addList(L,x);
	}
	printList(L);
	scanf("%d",&x);
	L=deleteList(L,x);
	printList(L);
	L=deleteAll(L);
	printList(L);
	return 0;
}
