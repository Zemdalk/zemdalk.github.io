#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}LinkedStack;

LinkedStack *InitStack(void);

int main(){
	LinkedStack *s;
	s=InitStack();
	ElemType e;
	if(IsStackEmpty(s)) printf("Stack is Empty!\n");
	printf("Please enter each element of your stack:\n");
	do{
		scanf("%d",&e);
		Push(s,e);
	}while(getchar()!='\n');
	if(IsStackEmpty(s)) printf("Stack is Empty!");
	printf("The length of stack s is: %d\n",GetLen(s));
	while(Pop(s,&e)) printf("%d ",e);
}

LinkedStack *InitStack(void){
	LinkedStack *s;
	s=(LinkedStack *)malloc(sizeof(LinkedStack));
	s->next=NULL;
	return s;
}

int GetLen(LinkedStack *s){
	int i=0;
	LinkedStack *p;
	p=s->next;
	while(p){
		i++;
		p=p->next;
	}
	return i;
}

int Push(LinkedStack *s,ElemType e){
	LinkedStack *p=(LinkedStack *)malloc(sizeof(LinkedStack));
	if(!p) return 0;
	p->data=e;
	p->next=s->next;//新结点插入到头结点之后
	s->next=p; 
	return 1;
}

int Pop(LinkedStack *s,ElemType *e){
	LinkedStack *p;
	if(!s->next) return 0;
	p=s->next;
	*e=p->data;
	s->next=p->next;//栈顶元素由头结点来指示 
	free(p);
	return 1;
}

int IsStackEmpty(LinkedStack *s){
	if(!s->next) return 1;
	else return 0;
} 
