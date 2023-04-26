#include <stdio.h>
#define INITSIZE 100
#define INCREMENTSIZE 10

typedef int ElemType;
typedef struct{
	int top;
	ElemType *base;
	int stacksize;
}SqStack;

int main(){
	char str[INITSIZE];
	scanf("%s",str);
	if(MatchingBrackets(str)) printf("Matching brackets successfully!\n");
	else printf("Matching brackets failed!\n");
}

int MatchingBrackets(char *exps){
	int i=0;
	int state=1;
	ElemType e;
	SqStack s;
	InitStack(&s);
	while(state && exps[i]!='\0'){
		switch(exps[i]){
			case '(': case'[': case '{':
				Push(&s,exps[i]);
				break;
			case ')': case']': case '}':
				if(!GetTop(&s,&e)){
					state=0;
					break;
				}
				if((e=='(' && exps[i]==')') || (e=='[' && exps[i]==']') 
					|| (e=='{' && exps[i]=='}'))
				Pop(&s,&e);
				else state = 0;
				break;
		}
		i++;
	}
	if(IsStackEmpty(&s) && state)	return 1;
	else return 0;
}

void Conversion(int n,int d){
	//将十进制数转换成d进制数 
	ElemType e;
	SqStack s;
	if(!InitStack(&s)) return;
	while(n!=0){
		Push(&s,n%d);
		n/=d;
	}
	while(!IsStackEmpty(&s)){
		Pop(&s,&e);
		printf("%d ",e);
	}
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
