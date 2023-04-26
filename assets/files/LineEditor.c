/***********
在用户输入一行的过程中，允许用户输入出差错，并在发现有误的同时可以及时更正。 
用#代替退格符Backspace，@代表退行符，删除一行。例如，用户输入下面两行：
whli##ilr#e(s#*s)
outcha@putchar(*s=#++);
实际有效的是
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
		//打印出从栈底到栈顶的元素，并置s为空栈 
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
	//t为s中元素的逆序，便于从栈底打印到栈顶
	//让t接受s中的元素，同时也能置s为空栈 
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
