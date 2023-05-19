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
//function to obtain user input of 2 numbers
void uip(float H,float G){
	printf("Enter first number - ");
	scanf("%lf",&H);
	printf("Enter second number - ");
	scanf("%lf",&G);
}

int main(){
	int menuindex;
	printf("Enter the arithmetic operation that you want to perform \n1. Addition\n2.Subtraction\n3.multiplication\n4.division\nYour choice - ");
	scanf("%d",&menuindex);
	//menuindex is the choice entered by user to select what operation needs to take place
	float a,b;
	printf("Enter first number - ");	
	scanf("%f",&a);
	printf("Enter second number - ");
	scanf("%f",&b);
	//uip(a,b);
	//UIP FUNCTION GIVES UNKOWN ERROR 
	//BETTER PRACTICE TO NOT USE PRINTF AND SCANF IN FUNCTIONS
	switch(menuindex){
		case 1:
			printf("%f\n",sum(a,b));
			break;
		case 2:
			printf("%f\n",diff(a,b));
			break;
		case 3:
			printf("%f\n",mul(a,b));
			break;
		case 4:
			printf("%f\n",div(a,b));
			break;
	}
}
