#include <stdio.h>
#include <stdlib.h>
 
#define ERROR 0
#define OK 1
typedef int Status;
typedef int ElemType;
typedef struct QNode{
	ElemType data;
	struct QNode *next;
}QNode;
typedef struct{
	QNode *front;
	QNode *rear;
}LinkedQueue;

int main(){
	LinkedQueue *lq=(LinkedQueue *)malloc(sizeof(LinkedQueue));
	InitQueue(lq);
	if(IsQueueEmpty(lq)) printf("The queue is empty.\n");
	else printf("The queue is not empty.\n");
	ElemType *e=(ElemType *)malloc(sizeof(ElemType));
	int i;
	for(i=0;i<10;i++){
		Enqueue(lq,i);
	}
	if(IsQueueEmpty(lq)) printf("The queue is empty.\n");
	else printf("The queue is not empty.\n");
	for(i=0;i<10;i++){
		GetFront(lq,e);
		printf("No.%d: %d\n",i,*e);
		Dequeue(lq,e);
		if(IsQueueEmpty(lq)) printf("The queue is empty.\n");
		else printf("The queue is not empty.\n");
	}
}

Status InitQueue(LinkedQueue *lq){
	lq->front=lq->rear=(QNode *)malloc(sizeof(QNode));
	if(!lq->front) return ERROR;
	lq->front->next=NULL;
	return OK;
}

int IsQueueEmpty(LinkedQueue *lq){
	if(lq->front==lq->rear) return 1;
	else return 0;
}

Status GetFront(LinkedQueue *lq, ElemType *e){
	if(lq->front==lq->rear) return ERROR;
	*e=lq->front->next->data;
	return OK;
}

Status Enqueue(LinkedQueue *lq, ElemType e){
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	if(!p) return ERROR;
	p->data=e;
	p->next=NULL;
	lq->rear->next=p;
	lq->rear=p;
	return OK;
}

Status Dequeue(LinkedQueue *lq, ElemType *e){
	QNode *p;
	if(lq->front==lq->rear) return ERROR;
	p=lq->front->next;
	*e=p->data;
	lq->front->next=p->next;
	if(lq->rear==p) lq->rear=lq->front;
	free(p);
	return OK;
} 

