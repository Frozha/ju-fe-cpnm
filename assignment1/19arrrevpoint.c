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
        printf("\nprinting rev array\n");
        int revarr[n];
        int *REVARR=revarr;
        for(i=0;i<n;i++){
               *(REVARR+i) =*(ARR+n-1-i);
        }
        for(i=0;i<n;i++){
                printf("%d ",revarr[i]);
        }
}

