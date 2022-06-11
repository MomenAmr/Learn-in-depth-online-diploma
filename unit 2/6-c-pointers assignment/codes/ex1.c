#include<stdio.h>

void main ()
{
	int m = 29;
	printf("address of m :0x%p\nvalue of m : %d",&m,m);

	int* ab = &m;
	printf("\n\nNow ab is assigned with the address of m.\nAddress of pointer ab : 0x%p\nContent of pointer ab : %d",ab,*ab);

	m = 34;
	printf("\n\nThe value of m assigned to 34 now.\nAddress of pointer ab : 0x%p\nContent of pointer ab : %d",ab,*ab);

	*ab = 7;
	printf("\n\nThe pointer variable ab is assigned with the value 7 now.\naddress of m :0x%p\nvalue of m : %d",&m,m);

}
