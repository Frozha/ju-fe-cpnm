/*created by hrithvik on 28 april
 * assmt 5 
 * program to return first and last digit
 */

#include<stdio.h>
int main(){
	int a=0;
	printf("Enter number to get its first and last digit - ");
	scanf("%d",&a);
	int i =1;
	printf("last digit = %d",a%10);
	for(i=1;(a/i)!=0;i*=10){
		continue;
	}
	printf("first digit = %d",(10*a/i)%(i/10));
}

