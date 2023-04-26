#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUESIZE 100
#define ERROR 0
#define OK 1

typedef int Status;
typedef int ElemType;
typedef struct queue{
	ElemType *base;
	int front;
	int rear;
}CircularQueue; 

int main(){
	CircularQueue *cq=(CircularQueue *)malloc(sizeof(CircularQueue));
	InitQueue(cq);
	printf("Length of queue cq: %d\n", GetLen(cq));
	int i;
	for(i=0;i<10;i++){
		Enqueue(cq,i);
	}
	ElemType *e=(ElemType *)malloc(sizeof(ElemType));
	printf("Length of queue cq: %d\n", GetLen(cq));
	for(i=0;i<10;i++){
		Dequeue(cq,e);
		printf("No.%d: %d\n",i,*e);
	}
	printf("Length of queue cq: %d\n", GetLen(cq));
}

Status InitQueue(CircularQueue *cq){
	cq->base=(ElemType *)malloc(sizeof(ElemType) * MAXQUEUESIZE);
	if(!cq->base) return ERROR;
	cq->front=cq->rear=0;
	return OK;
}

int GetLen(CircularQueue *cq){
	return ((cq->rear - cq->front + MAXQUEUESIZE) % MAXQUEUESIZE);
}

Status Enqueue(CircularQueue *cq, ElemType e){
	if((cq->rear+1) % MAXQUEUESIZE == cq->front) return ERROR;
	cq->base[cq->rear] = e;
	cq->rear = (cq->rear+1) % MAXQUEUESIZE;
	return OK;
} 

Status Dequeue(CircularQueue *cq, ElemType *e){
	if(cq->front == cq->rear) return ERROR;
	*e=cq->base[cq->front];
	cq->front=(cq->front + 1) % MAXQUEUESIZE;
	return OK;
}
