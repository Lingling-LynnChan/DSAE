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
#define Max 1000
void
clear (char* str) {
	char* s=str;
	int i=0;
	while (*s!='\0') {
		if (*s!=' ') {
			str[i++]=*s;
		}
		s+=1;
	}if (str[i-1]=='=') {
		str[i]='\0';
	}else {
		str[i]='=';
		str[i+1]='\0';
	}
}
int
getNum (int x) {
	int i=1;
	while (x/=10) {
		i++;
	}
	return i;
}
void
import (Stack S) {
	char str[Max],ch;
	scanf("%[^\n]",str);
	clear(str);
	char* s=str;
	int i,h;
	sscanf(s,"%d%c",&i,&ch);
	push(S,i);
	while (ch!='=') {
		s+=getNum(i)+1;
		if (ch=='+') {
			sscanf(s,"%d%c",&i,&ch);
			push(S,i);
		}else
		if (ch=='-') {
			sscanf(s,"%d%c",&i,&ch);
			push(S,-i);
		}else
		if (ch=='*') {
			sscanf(s,"%d%c",&i,&ch);
			h=pop(S);
			i+=h;
			push(S,i);
		}else
		if (ch=='/') {
			sscanf(s,"%d%c",&i,&ch);
			h=pop(S);
			i=h/i;
			push(S,i);
		}else
		if (ch=='%') {
			sscanf(s,"%d%c",&i,&ch);
			h=pop(S);
			i=h%i;
			push(S,i);
		}else {
			if (ch!='=') {
				printf("ERR_WRONG_IMPORT::%c::114514\n",ch);
				exit(1);
			}else {
				push(S,i);
				return;
			}
		}
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
