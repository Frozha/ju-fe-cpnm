/* created by hrithvik on 31-3-23*/
/*finding power of two numbers using power functrion*/
#include<stdio.h>
#include<math.h>
int main(){
	double base, powr;
	//to find base^powr
	printf("Enter base integer - ");
	scanf("%lf",&base);
	printf("Enter power of base - ");
	scanf("%lf",&powr);
	double result = pow(base,powr);
	printf("%lf raised to the power %lf is %lf",base,powr,result);
}
