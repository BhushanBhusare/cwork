#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 100

char stack[SIZE];
int top=-1;

void push(char c){
	if(top>=SIZE-1){
		printf("Overflow\n");exit(1);
	}stack[++top]=c;
}

char pop(){
	if(top<0){
		printf("Underflow\n");exit(1);
	}return stack[top--];
}

int precedence(char c){
	switch(c){
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '^':return 3;
		default:return 0;
	}
}

void infix_to_postfix(char *infix, char *postfix){
	int i,j=-1;
	for(i=0; infix[i]!='\0';i++){
		char c = infix[i];
		if(isalnum(c)){
			postfix[++j]=c;
		}else if(c == '('){
			push(c);
		}else if(c == ')'){
			while(top != -1 && stack[top] != '('){
				postfix[++j]=pop();
			}
			pop();
		}else{
			while(top!=-1 && precedence(stack[top])>=precedence(c)){
				postfix[++j]=pop();
			}
			push(c);
		}
	}
	while(top!=-1){
		postfix[++j]=pop();
	}
	postfix[++j]='\0';
}

int main(void){
	char infix[]="(A+B)*(C-D)", postfix[SIZE];
	infix_to_postfix(infix,postfix);
	printf("Postfix expression : %s",postfix);
}
