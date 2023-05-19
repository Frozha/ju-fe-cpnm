#include<stdio.h>
int n;
int printmatx(int *p){
        int i,j;
        for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                        printf("%d ",*(p+(i*n)+j));
                }
        printf("\n");
        }
}
void matxmul(int *a,int *b,int *c){
	int i,j,k;
	int x=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				x+=*(a+(i*n)+k)*(*(b+j*n+k)); 
			}
			*(c+j*n+i)=x;
			x=0;
		}
	}
}
int main(){
	printf("enter size of matrix (n for nxn):");
        int i,j;
        scanf("%d",&n);
        int v[n][n],w[n][n],x[n][n];
        printf("Enter values of rows with spaces and then press enter for next row \n");
        printf("First matx \n");
	for(i=0;i<n;i++){
                printf("row %d - ",i);
                for(j=0;j<n;j++){
                        scanf("%d",&v[i][j]);
                }
        }
	printf("second matx \n");
	for(i=0;i<n;i++){
                printf("row %d - ",i);
                for(j=0;j<n;j++){
                        scanf("%d",&w[i][j]);
                }
        }
	int *X= x;
	matxmul(v,w,X);
	printmatx(X);
}
