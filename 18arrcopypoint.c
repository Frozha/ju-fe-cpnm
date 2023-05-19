#include<stdio.h>
int main(){
        printf("Enter size of array - ");
        int n;
        scanf("%d",&n);
        int arr[n];
	int *ARR = arr;
        int i;
        printf("\nEnter numbers :-\n");
        for(i=0;i<n;i++){
                scanf("%d",ARR+i);
        }
        printf("\nprinting new array\n");
        int newarr[n];
	int *NEWARR=newarr;
	for(i=0;i<n;i++){
               *(NEWARR+i) =*(ARR+i);
        }
	for(i=0;i<n;i++){
		printf("%d ",newarr[i]);
	}
}

