#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};

struct node* head=NULL;

struct node* mknode(int data);
struct node* push(int data);
struct node* pop();
void display();

int main(void){
	push(20);
	push(40);
	push(60);
	display();
	pop();
	pop();
	display();
	push(80);
	display();



}

struct node* mknode(int data){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->link=NULL;
}

struct node* push(int data){
	struct node* newnode=mknode(data);
	if(head == NULL){
		head = newnode;return head;
	}
	newnode->link=head;
	head=newnode;
	
	return head;
}

struct node* pop(){
	if(head==NULL){
		printf("Stack was empty!\n");exit(1);
	}
	struct node* temp=head;
	head=head->link;
	free(temp);
	return head;
}

void display(){
	if(head==NULL){
		printf("Stack was empty!\n");
	}
	struct node* temp=head;
	do{
		printf("%d ",temp->data);
		temp=temp->link;
	}while(temp!=NULL);
	printf("\n");
}

