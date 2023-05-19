#include<stdio.h>

int factorial(int n){
    unsigned int fact = 1;
    int i;
    for( i=1;i<=n;i++){
        fact *= i;
    }
    return fact;
}

int digit(int num,int dig){
    int k,i, l=1;
    for( i=1;i<=dig;i++){
        l*=10;
    }
    k=((num%l)*10/l);
    return k;
}

int strongnum(int s){
    int i,dig=0;
    for( i=1;(s/i)!=0;i*=10){
        dig+=1;
    }
    int sum = 0;
    for(;dig!=0;dig--){
        sum+=factorial(digit(s,dig));
    }
    if (sum == s)return 1;
    else return 0;
}

int main(){
    printf("Enter range to find strong numbers \nfrom - ");
    int lower;
    scanf("%d",&lower);
    printf("to - ");
    int upper;
    scanf("%d",&upper);
    for(;lower!=upper;lower++){
        if(strongnum(lower))printf("%d ",lower);
    }
}
