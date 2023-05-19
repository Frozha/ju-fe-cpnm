/* created by hrithvik on 31-3-23
 * program to find roots of quardratic equation of the form 
 * ax^2+bx+c=0
 * where a, b , c are coefficients which will be reflected 
 * as variable names in this file*/

#include<stdio.h>
#include "math.h"
int main(){
	float a=0,b=0,c=0;
	printf("For the Equation of form \n\tAx^2+Bx+C = 0\nEnter value of A - ");
	scanf("%f",&a);
	printf("Enter value of B - ");
	scanf("%f",&b);
	printf("Enter value of C - ");
	scanf("%f",&c);
	//D = b^2-4ac the descriminant of sridharacharaya formula
	float D=((b*b)-(4*a*c));
	//splitting program into 2 cases of real and imaginary roots
	float Dd = sqrt(D);
	float r1,r2;
	//declaration of roots of quardratic quation
	int casa = (D>=0)?1:0;	
	switch(casa){
		case 1:	
			printf("Roots are real and equal to ");
			r1 = (-1*b/(2*a))+(Dd/(2*a));
			r2 = (-1*b/(2*a))-(Dd/(2*a));
			printf("%f and %f\n", r1,r2);
			break;
		case 0:
			printf("Roots are imaginary\n");
	}
}

