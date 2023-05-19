#include<stdio.h>

int sumofdivisors(int n){
    int sum=0;
    int i;
    for( i=1;i<n;i++){
        if(n%i==0){
            sum+=i;
        }
    }
    if(sum==n)return 1;
    else return 0;
}

int main(){
    printf("Enter n to find perfect numbers from 1 to n ");
    int i,n;
    scanf("%d",&n);
    for( i =1;i<=n;i++){
        if(sumofdivisors(i))printf("%d ",i);
    }
}

