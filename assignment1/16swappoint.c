#include<stdio.h>
int main(){
	int a,b;
	printf("Enter a = ");
	scanf("%d",&a);
	printf("Enter b = ");
	scanf("%d",&b);
	int *A=&a,*B=&b;
	int *swap = A;
	A=B;
	B=swap;
	printf("a = %d\n",*A);
	printf("b = %d\n",*B);
}
	
