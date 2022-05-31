#include<stdio.h>

void main()
{
	char x;

	printf("enter an alphabet :");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);

	if(x=='a'||x=='A'||x=='e'||x=='E'||x=='i'||x=='I'||x=='o'||x=='O'||x=='u'||x=='U')
		printf("%c is vowel",x);

	else printf("%c is consonant",x);
}
