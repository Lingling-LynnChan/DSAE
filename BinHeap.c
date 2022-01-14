#include <stdio.h>
#include <stdlib.h>

typedef struct HNode Node;
typedef Node* Heap;
/*MinTop Heap*/
struct HNode {
	int* Data;
	int Top;
	int MaxSize;
};

int
parent (int i) {
	return (i-1)/2;
}
int
left (int i) {
	return 2*i+1;
}
int
right(int i) {
	return left(i)+1;
}
void
swap (int* x,int* y) {
	int t=*x;
	*x=*y;
	*y=t;
}
Heap
newHeap (int maxsize) {
	Heap H=(Heap)malloc(sizeof(Node));
	H->Data=(int*)malloc(maxsize*sizeof(int));
	H->MaxSize=maxsize;
	H->Top=-1;
	return H;
}
void
shiftUp (Heap H,int i) {
	if (parent(i)==-1) {
		return;
	}
	if (H->Data[parent(i)]>H->Data[i]) {
		swap(&H->Data[parent(i)],&H->Data[i]);
		shiftUp(H,parent(i));
	}
}
void
shiftDown (Heap H,int i) {
	if (left(i)<H->Top) {
		return;
	}
	if (right(i)<H->Top) {
		if (H->Data[i]>H->Data[left(i)]) {
			swap(&H->Data[i],&H->Data[left(i)]);
			shiftDown(H,left(i));
			return;
		}
	}
	int kind=H->Data[left(i)]<H->Data[right(i)]?left(i):right(i);
	if (H->Data[i]>H->Data[kind]) {
		swap(&H->Data[i],&H->Data[kind]);
		shiftDown(H,kind);
	}
}
void
insert (Heap H,int X) {
	if (H->Top+1==H->MaxSize) {
		return;
	}
	H->Data[++H->Top]=X;
	shiftUp(H,H->Top);
}
void
print (Heap H) {
	int i;
	for (i = 0; i < H->Top+1; i += 1) {
		printf("%4d",H->Data[i]);
	}
	printf("\n");
}

int
main (int argc, char *argv[]) {
	int n,x;
	scanf("%d",&n);
	Heap H=newHeap(n);
	while (n--) {
		scanf("%d",&x);
		insert(H,x);
	}
	print(H);
	return 0;
}
