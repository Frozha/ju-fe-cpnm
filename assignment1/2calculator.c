/* created by hrithvik on 31-3-23*/

#include<stdio.h>
//function to find sum of teo numbers
float sum(float a, float b){
	return a+b;
}
//function to find difference of two numbers
float diff(float a, float b){
	return a-b;
}
//function to find product of two numbers
float mul(float a, float b){
	return a*b;
}
//function to find quotient of two numbers
float div(float a, float b){
	return a/b;
}

int main(){
	char menuindex;
	printf("Enter the arithmetic operator \n1. Addition {+}\n2.Subtraction {-}\n3.multiplication {*}\n4.division {/}\nYour choice - ");
	scanf("%c",&menuindex);
	float a,b;
	printf("Enter first number - ");	
	scanf("%f",&a);
	printf("Enter second number - ");
	scanf("%f",&b);

	switch(menuindex){
		case '+':
			printf("%f\n",sum(a,b));
			break;
		case '-':
			printf("%f\n",diff(a,b));
			break;
		case '*':
			printf("%f\n",mul(a,b));
			break;
		case '/':
			printf("%f\n",div(a,b));
			break;
	}
}
