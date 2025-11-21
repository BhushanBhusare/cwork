#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int deque[SIZE];
int front = -1;
int rear = -1;

void enqueue_front(int data);
void enqueue_rear(int data);
void dequeue_front();
void dequeue_rear();
void display();

int main(void){
	enqueue_front(20);
	enqueue_front(40);
	display();
	enqueue_rear(60);
	dequeue_front();
	display();
}

void enqueue_front(int data){
	if((front==0 && rear==SIZE-1) || front==rear+1){
		printf("Stack was full!\n");exit(1);
	}else if(front==0){
		front=SIZE-1;
		deque[front]=data;
	}else if(front == -1 && rear==-1){
		front=rear=0;
		deque[front]=data;
	}else{
		deque[--front]=data;
	}
}

void enqueue_rear(int data){
	if((front==0 && rear==SIZE-1)||front==rear+1){
		printf("Stack was full!\n0");exit(1);
	}else if(front==-1 && rear == -1){
		front=rear=0;
		deque[rear]=data;
	}else if(rear==SIZE-1){
		rear=0;
		deque[rear]=data;
	}else{
		deque[++rear]=data;
	}
}

void dequeue_front(){
	if(front== -1 || rear==-1){
		printf("Stack was empty! \n");exit(1);
	}else if(front==rear){
		front=rear=-1;
	}else if(front==SIZE-1){
		front=0;
	}else{
		front++;
	}
}

void dequeue_rear(){
	if(front==-1 || rear==-1){
		printf("Stack was empty! \n");exit(1);
	}else if(front==rear){
		front=rear=-1;
	}else if(rear==0){
		rear=SIZE-1;
	}else{
		rear--;
	}
}

void display(){
	if(front==-1 || rear == -1){
		printf("No element to print\n");exit(1);
	}
	int i=front;
	do{
		printf("%d ",deque[i]);
		i=(i+1)%SIZE;
		if(i==rear)break;
	}while(1);
	printf("%d\n",deque[rear]);
}
