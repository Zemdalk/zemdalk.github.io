/***********
���û�����һ�еĹ����У������û������������ڷ��������ͬʱ���Լ�ʱ������ 
��#�����˸��Backspace��@�������з���ɾ��һ�С����磬�û������������У�
whli##ilr#e(s#*s)
outcha@putchar(*s=#++);
ʵ����Ч����
while(*s)
putchar(*s++); 
*********/

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}LinkedStack;

LinkedStack *InitStack(void);
int LineEditor();
void PrintStack(LinkedStack *s);
void ClearStack(LinkedStack *s);
int Push(LinkedStack *s,ElemType e);

int main(){
	if(LineEditor()) printf("Error!");
//	LineEditor();
}

int LineEditor(){
	LinkedStack *s=InitStack();
	ElemType c;
	char ch=getchar();
	while(ch!=EOF){
		while(ch!=EOF && ch!='\n'){
			switch(ch){
				case '#': 
					if(!Pop(s,&c)) return 1;
					break;
				case '@':
					ClearStack(s);
					break;
				default:
//					printf("%c\n",ch);
					if(!Push(s,(ElemType)ch)) return 1;
					break;
			}
			ch=getchar();
		}
		//��ӡ����ջ�׵�ջ����Ԫ�أ�����sΪ��ջ 
		PrintStack(s);
		if(ch!=EOF) ch=getchar();
	}
	return 0;
}

void PrintStack(LinkedStack *s){
	LinkedStack *t,*p;
	ElemType e;
	int i,j;
	i=GetLen(s);
	j=1;
	t=InitStack();
	//tΪs��Ԫ�ص����򣬱��ڴ�ջ�״�ӡ��ջ��
	//��t����s�е�Ԫ�أ�ͬʱҲ����sΪ��ջ 
	while(j<=i){
		Pop(s,&e);
		Push(t,e);
		j++;
	}
	p=t->next;
	while(p!=NULL){
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}

void ClearStack(LinkedStack *s){
	s->next=NULL;
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
	p->next=s->next;//�½����뵽ͷ���֮��
	s->next=p; 
	return 1;
}

int Pop(LinkedStack *s,ElemType *e){
	LinkedStack *p;
	if(!s->next) return 0;
	p=s->next;
	*e=p->data;
	s->next=p->next;//ջ��Ԫ����ͷ�����ָʾ 
	free(p);
	return 1;
}
