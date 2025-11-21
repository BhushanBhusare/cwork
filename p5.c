#include<stdio.h>
#include<stdlib.h>
#define n 7
void display(int arr[]){
	if(n < -1){
		printf("list was empty !");exit(1);
	}
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void insertion_sort(int arr[]){
	for(int i=1; i<n; i++){
		int j=i-1;
		int key = arr[i];
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int main(void){
	int arr[n] = {9,8,1,17,7,6,5};
	printf("Befor sort : ");
	display(arr);
	printf("After insertion sort : ");
	insertion_sort(arr);
	display(arr);
}
