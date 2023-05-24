#include<stdio.h>
void printer(int **a){
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("l[%d][%d] - %d \n",i,j,*(*(a+i)+j));
        }
    }
}
int main(){
    int m[2][3]={{1,2,3},{4,5,6}};
    int *p[2]= {m[0],m[1]};
    int **q = &p;
    printer(q);

}