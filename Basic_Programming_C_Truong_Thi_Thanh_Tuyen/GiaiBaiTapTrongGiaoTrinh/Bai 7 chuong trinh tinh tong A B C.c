#include<stdio.h>
#include<conio.h>
#include<math.h>

float hamXuLyCauA(int n, float x)
{
	if (n==0) return 1;
		else if (n>=1) return (pow(x,n) + hamXuLyCauA(n-1, x));
}

float hamXuLyCauB(int n, float x)
{
	if (n==0) return 1;
		else if (n>=1) return (pow(-1,n)*pow(x,n) + hamXuLyCauB(n-1, x));
}

int giaiThua(int n)
{
	if (n==0) return 1;
		else if (n>=1) return (n*giaiThua(n-1));
}

float hamXuLyCauC(int n, float x)
{
	if (n==0) return 1;
		else if (n>=1) return (pow(x,n)/giaiThua(n) + hamXuLyCauC(n-1, x));
}

int main()
{
	int n;
	float x;
	do 	{printf("Nhap n = "); scanf("%d", &n);} while (n<0);
	printf("     x = "); scanf("%f", &x);
	printf("\nCau a: S = %.2f", hamXuLyCauA(n, x));
	printf("\nCau b: S = %.2f", hamXuLyCauB(n, x));
	printf("\nCau c: S = %.2f", hamXuLyCauC(n, x));	
	getch();
	return 0;
}
