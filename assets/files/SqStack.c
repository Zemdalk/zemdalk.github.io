#include <stdio.h>
#include <stdlib.h>

#define INITSIZE 100
#define INCREMENTSIZE 10

typedef int ElemType;
typedef struct{
	int top;
	ElemType *base;
	int stacksize;
}SqStack;

void visit(ElemType *e);
int InitStack(SqStack *s);
int GetLen(SqStack *s);
int GetTop(SqStack *s,ElemType *e);
int StackTraverse(SqStack *s, void visit(ElemType *e));
int Push(SqStack *s,ElemType e);
int Pop(SqStack *s,ElemType *e);
int IsStackEmpty(SqStack *s);

int main(){
	SqStack *s=(SqStack *)malloc(sizeof(SqStack));
	InitStack(s);
	ElemType e;
	do{
		scanf("%d",&e);
		Push(s,e);
	}while(getchar()!='\n');
	Push(s,12);
	printf("Length of stack s is: %d\n",GetLen(s));
	printf("Elements of stack s are:\n");
	StackTraverse(s, visit);
}

int InitStack(SqStack *s){
	s->base = (ElemType *) malloc(INITSIZE * sizeof(ElemType));
	if(!s) return 0;
	s->top=0;
	s->stacksize=INITSIZE;
}

int GetLen(SqStack *s){
	return (s->top);
}

int GetTop(SqStack *s,ElemType *e){
	if(s->top==0) return 0;
	*e=s->base[s->top-1];
	return 1;
}

int Push(SqStack *s,ElemType e){
	//若栈已满，新增INCREMENTSIZE个存储单元
	if(s->top>=s->stacksize) {
		s->base=(ElemType *)realloc(s->base, 
			(s->stacksize + INCREMENTSIZE)*sizeof(ElemType));
		if(!s->base) return 0;
		s->stacksize+=INCREMENTSIZE;
	}
	//入栈
	s->base[s->top++]=e;
	return 1; 
}

int Pop(SqStack *s,ElemType *e){
	if(s->top==0) return 0;
	*e=s->base[--s->top];//注意，这里是先自减再取元素，上面入栈时是先放元素再入栈 
	return 0; 
}

int IsStackEmpty(SqStack *s){
	if(s->top==0) return 1;
	else return 0;
} 

int StackTraverse(SqStack *s, void visit(ElemType *e)){
	int i;
	if(s->top==0) return 0;
	for(i=s->top-1;i>=0;i--){
		visit(&s->base[i]);
	}
	return 1;
}

void visit(ElemType *e){
	printf("%d\n",*e);
}
