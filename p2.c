#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 100

int stack[SIZE];
int top=-1;

void push(int n);
int pop();
int isoperator(char ele);
int perform_op(int op1, int op2, char ope);
int evaluate(char *infix);

int main(void){
	char infix[]="3 2 +";
	evaluate(infix);
}

void push(int n){
	if(top>=SIZE-1){
		printf("Overflow\n");
		exit(1);
	}stack[++top]=n;
}

int pop(){
	if(top<0){
		printf("Underflow\n");
		exit(1);
	}return stack[top--];
}

int isoperator(char ele){
	return(ele=='+' || ele=='-' || ele=='*' || ele=='/');
}

int perform_op(int op1, int op2, char ope){
	switch(ope){
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': if(op2==0){
			  	printf("Division by zero Found !\n"); exit(1);
			  }
			  return op1 / op2;
		default: return 0;
	}
}

int evaluate(char *infix){
	for(int i=0; infix[i]!='\0'; i++){
		char c = infix[i];
		if(isdigit(c)){
			push(c-'0');
		}else if(isoperator(c)){
			int op2=pop();
			int op1=pop();
			int result = perform_op(op1,op2,c);
			push(result);
		}else if(c == ' '){
			continue;
		}else{
			printf("Invalid Character Found : %c",c);exit(1);
		}
	}
	if(top==0){
		int result=pop();
		printf("Result = %d",result);
		return result;
	}

	printf("Invalid Expression Found !\n");
	return -1;
	
}
