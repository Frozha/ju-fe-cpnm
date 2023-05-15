//editied
#include<stdio.h>
int main(){
    printf("Enter range to find prime numbers \n from - ");
    int lower;
    scanf("%d",&lower);
    printf("to - ");
    int upper;
    scanf("%d",&upper);
    int composite_bool;
    for(int i=lower;i<=upper;i++){
        composite_bool =0;
        for(int k = 2;k<i/1.414;k++){
            if (i%k==0){
                composite_bool=1;
                break;
            }
        }
        if(composite_bool ==0){
            printf("%d ",i);
        }
    }
}