#include<stdio.h>

void triangle(int n){
    int prev_row[n+2];
    prev_row[0]=0;
    prev_row[1]=1;
    prev_row[2]=0;
    printarr(prev_row,1,n);
    int i;
    for(i=2;i<=n;i++){
        int row[i+2];
        row[0]=0;
        row[i+1]=0;
        int j;
        for(j=1;j<=i;j++){
                row[j]=(prev_row[j-1])+(prev_row[j]);
            }
            printarr(row,i,n);
        int k;
        for(k=0;k<i+2;k++){
                prev_row[k]=row[k];
            }
       
    }
}

void printarr(int *p, int current_row, int total_rows){
    	int i;
	for (i =0;i<total_rows-current_row;i++){
        printf(" ");
    }
    p++;
    for(i=0;i<current_row;i++){
        printf("%d ",*p);
        p++;
    }
    printf("\n");
}

int main(){
    printf("Enter number of rows for pascal triangle - ");
    int n=1;
    scanf("%d",&n);
    triangle(n);
}
       
