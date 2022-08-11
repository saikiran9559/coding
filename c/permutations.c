#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int count=0;
void permutations(int array[],int start, int end){
	int i;
	if(start == end){
		for(i=0; i<=end;i++){
			printf("%d",array[i]);
		}
		printf("\n");
		count++;
		return;
	}
		for(i=start; i<=end; i++){
			swap(&array[i],&array[start]);
			permutations(array, start+1, end);
			swap(&array[i],&array[start]);
		}
	
}

void main(){
	int arr[] = {1,2,3,4};
	permutations(arr,0,3);
	printf("count %d",count);
}
