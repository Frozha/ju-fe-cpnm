/* created by hrithvik on 28 april
 * assmt6
 *program to reverse number
*/

#include<stdio.h>
int main(){
	printf("Enter number to reverse it");
	int a=0;
	scanf("%d",&a);
	int rev_a=a%10,i;
	for( i=10;(a/i)!=0;i*=10){
		rev_a = (rev_a*10)+((a/i)%i)%10;
	}
	printf("Reversed number - %d",rev_a);
}
