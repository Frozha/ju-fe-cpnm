#include<stdio.h>
void transpose(int *a,int *b,int n){
	int  i,j;	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			*(b+(j*n)+i)=*(a+(i*n)+j);
		}
	}
}
int printmatx(int *p,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",*(p+(i*n)+j));
		}
	printf("\n");
	}
}

int main(){
	printf("enter size of matrix (n for nxn):");
	int a,i,j;
	scanf("%d",&a);
	int v[a][a],w[a][a];
	printf("Enter values of rows with spaces and then press enter for next row \n");
	for(i=0;i<a;i++){
		printf("row %d - ",i);
		for(j=0;j<a;j++){
			scanf("%d",&v[i][j]);
		}
	}
	int *V=v,*W=w;
	//printmatx(V,a);
	transpose(V,W,a);
	printmatx(W,a);
}
	 

