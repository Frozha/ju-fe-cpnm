#include<stdio.h>
int main(){
	printf("Enter size of array - ");
	int n;
	scanf("%d",&n);
	int arr[n];
	int *ARR[n];
	int i;
	printf("\nEnter numbers :-\n");
	for(i=0;i<n;i++){
		scanf("%d",ARR+i);
	}
	printf("\nprinting array using pointers\n");
	for(i=0;i<n;i++){
		printf("%d ",*(ARR+i));
	}
}
