/*
program to detect if sparse matrix
*/
#include<stdio.h>
int main(){
    printf("Enter dimensions of matrix rows <space> column - ");
    int row,col;
    scanf("%d %d",&row,&col);
    int a[row][col];
    for(int i=0;i<row;i++){
        printf("row %d - ",i+1);
        for(int j=0;j<col;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int counter = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if (a[i][j]==0)counter++;
            else counter--;
        }
    }
    if (counter>=0){
        printf("Sparse matrix");
    }
    else printf("not Sparse matrix");   
}