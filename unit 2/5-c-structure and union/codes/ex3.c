#include<stdio.h>

struct Scomplex
{
	double m_real;
	double m_imag;
};

struct Scomplex ComSum (struct Scomplex x, struct Scomplex y)
{
	struct Scomplex z;
	z.m_real = x.m_real + y.m_real;
	z.m_imag = x.m_imag + y.m_imag;
	return z;
}

void ComPrint(struct Scomplex x)
{
	printf("sum = %0.1lf + %0.1lfi",x.m_real,x.m_imag);
}

void main ()
{
	struct Scomplex x,y,z;

	printf("fot 1st complex number\nenter real and imaginary respectively:");
	fflush(stdin);fflush(stdout);
	scanf("%lf %lf",&x.m_real,&x.m_imag);

	printf("fot 2nd complex number\nenter real and imaginary respectively:");
	fflush(stdin);fflush(stdout);
	scanf("%lf %lf",&y.m_real,&y.m_imag);

	z = ComSum(x,y);
	ComPrint(z);
}
