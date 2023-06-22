#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"
void initQueue(Queue *q){
	int i;
	q->front = 7;
	q->rear = 6;
	for(i=0;i<MAX;++i){
		q->elems[i] = EMPTY;
	}
}

void enqueue(Queue *q, int item){
	if(!isFull(*q)){
		q->rear = (q->rear+1) % MAX;
		q->elems[q->rear] = item;
	}
}

void dequeue(Queue *q){
	if(!isEmpty(*q)){
		q->elems[q->front] = EMPTY;
		q->front = (q->front+1) % MAX;
	}
}

int front(Queue q){
	if(!isEmpty(q)){
		return q.elems[q.front];
	}
	return EMPTY;
}

bool isEmpty(Queue q){
	return (q.rear + 1) % MAX == q.front;
}

bool isFull(Queue q){
	return (q.rear + 2) % MAX == q.front;
}

void visualize(Queue q){
	int i;
	printf("%5s | %5s | %s\n", "INDEX", "VALUE", "POSITION");
	printf("------------------------\n");

	for(i=0;i<MAX;++i){
		printf("%5d | ", i);
		if(q.elems[i] != EMPTY){
			printf("%5d | ", q.elems[i]);			
		}else{
			printf("%5s | ", " ");
		}
			if(i == q.front){
				printf("Front");
			}if(i==q.rear){
				printf("Rear");
			}
	printf("\n");
	}
	printf("------------------------\n");
}

void display(Queue q){
	int i;
	printf("{ ");

	for(i=q.front;q.elems[i] != EMPTY;i=(i+1)%MAX){
		printf("%d ", q.elems[i]);
	}
	printf("}");
}

bool removeItem(Queue *q, int item){
	int i=front(*q);
	bool del = false;
	while(i!=EMPTY&&i!=q->rear&&i!=item){
		dequeue(q);
		enqueue(q, i);
		i=front(*q);
	}
	if(i==item){
		dequeue(q);
		del = true;
		return del;
	}
	else{
		return false;
	}
}

Queue removeEven(Queue *q){
	Queue newqueue;
	initQueue(&newqueue);
	int i=front(*q);
	int j = i;
	int count=0;

	do{
		if(i%2==0){
			dequeue(q);
			enqueue(&newqueue, i);
		}
		else{
			dequeue(q);
			enqueue(q, i);
		}
		i=front(*q);
	}while(i!=EMPTY && i!=q->rear && i!=j);

	return newqueue;
	
}

int doubleTheValue(Queue *q, int value){
	int i = front(*q);
	int count=0;

	for(i=q->front;q->elems[i]!=EMPTY;i=(i+1)%MAX){
		if(q->elems[i]==value){
			q->elems[i] *= 2;
			count++;
		}
	}
	return count;
}
