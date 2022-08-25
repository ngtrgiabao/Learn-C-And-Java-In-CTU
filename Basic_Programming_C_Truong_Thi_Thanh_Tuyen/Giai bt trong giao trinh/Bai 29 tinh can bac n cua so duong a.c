#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
	float a, n, xn, xn1, kt=1; 	
	do {
		printf("Nhap n = "); scanf("%f", &n);
		printf("     a = "); scanf("%f", &a);
	} while (a<0 && n==0);
	xn=a/n;	//xn=x0
	while (kt>=0.001)
	{
		xn1=fabs( ((n-1)*pow(xn,n) + a) / (n*pow(xn,n-1)) );
		kt=fabs(a - pow(xn,n));
		xn=xn1;
	}
	printf("Can bac %f cua %f la %f", n, a, xn1);
	getch();
	return 0;
}
