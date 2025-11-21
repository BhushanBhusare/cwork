#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value){
	if(top>=SIZE-1){
		printf("stack overflow !\n");
		exit(1);
	}
	stack[++top]=value;
	printf("%d pushed to stack\n");
}

void pop(){
	if(top<0){
		printf("Stack UnderFlow");
		exit(1);
	}
	printf("%d poped from stack\n",stack[top--]);
}

int pick(){
	if(top<0){
		printf("Stack was empty!\n");
		exit(1);
	}
	return stack[top];
}

void display(){
	if(top < 0){
		printf("There is Zero Element in stack to print !\n");
		exit(1);
	}
	for(int i=0; i<=top; i++){
		printf("%d ",stack[i]);
	}
	printf("\n");
}

int main(void){
	push(10);
	push(20);
	push(30);
	push(40);
	display();
	pop();
	pop();
	display();
}
