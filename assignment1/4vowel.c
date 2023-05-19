/* created by hrithvik on 28th april
 * 4th assignment
 * program to check entered alphabet is vowel or consonant
 */ 
#include<stdio.h>
int main(){
	const char vow[]={'a','e','i','o','u','A','E','I','O','U'};
	char *p = vow;
	char ch;
	printf("Enter alphabet to chech if vowel/consonant - ");
	scanf("%c",&ch);
	int casa = 0,i;
	for(i =0;i<=9;i++){
		if (ch == *p){	
			casa = (ch == *p)?1:0;
			break;
		}	
		p++;
	}
	switch (casa){
		case 1:
			printf("It is a vowel.\n");
			break;
		case 0:
			printf("It is a consonant.\n");
			break;
	}
}		
