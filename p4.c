#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int circular_queue[SIZE];
int front= -1;
int rear = -1;

void enqueue(int data);
void dequeue();
void display();

int main(void){
	enqueue(10);
	enqueue(20);
	enqueue(30);
	display();
	dequeue();
	dequeue();
	display();
}

void enqueue(int data){
	if((front==0 && rear==SIZE-1) || (rear+1)%SIZE == front){
		printf("Circular Queue Full !\n");exit(1);
	}else if(front== -1 && rear==-1){
		front=rear=0;
		circular_queue[rear]=data;
		printf("%d was enqueue to Circular Queue \n",data);
	}else{
		rear = (rear+1)%SIZE;
		circular_queue[rear]=data;
		printf("%d was enqueue to Circular Queue \n",data);
	}
}

void dequeue(){
	int n;
	if(front == -1){
		printf("Circular Queue was empty!\n");exit(1);
	}else if(front == rear){
		n=circular_queue[front];
		front = rear = -1;
		printf("%d was dequeue \n",n);	
	}else{
		n=circular_queue[front];
		front=(front+1)%SIZE;
		printf("%d was dequeue \n",n);
	}
}

void display(){
	if(front==-1){
		printf("Circular Queue was empty!\n");exit(1);
	}
	int i = front;
	printf("\nQueue : ");
	while(1){
		printf("%d ",circular_queue[i]);
		if(i==rear)break;
		i=(i+1)%SIZE;
	}
	printf("\n");
}
