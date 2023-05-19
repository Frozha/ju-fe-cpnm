#include<stdio.h>

int switchmatx(int* p,int n){
    int r,hold;
    for( r=0;r<n;r++){
        hold = *((p+r*n)+n-1-r);
        *((p+r*n)+n-1-r) = *((p+r*n)+r);
        *((p+r*n)+r) = hold;
    }
    printmatx(p,n);
}

int printmatx(int*p,int n){
    int i,j;
    for(i = 0;i<n;i++){
	for( j=0;j<n;j++){
            printf("%d ",*(p+i*n+j));
        }
        printf("\n");
    }
}

int main(){
    printf("enter size of matrix \nn for nXn matrix - ");
    int n=0;
    scanf("%d",&n);
    int matx[n][n];
    int *temp=matx;
    int r,c;
    for( r=0;r<n;r++){
        for (c=0;c<n;c++){
            printf("a%d%d - ",r+1,c+1);
            scanf("%d",(temp+r*n+c));
        }
        printf("\n");
    }
    printmatx(matx,n);
    printf("  |\n  !\n");
    switchmatx(matx,n);
}
