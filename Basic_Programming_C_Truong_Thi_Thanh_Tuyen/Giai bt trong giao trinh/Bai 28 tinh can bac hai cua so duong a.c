#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
	float a, xn, xn1, kt=1; 	
	do {
		printf("Nhap a = "); scanf("%f", &a);
	} while (a<0);
	xn=(a+1)/2;	//xn=x0
	while (kt>=0.001)
	{
		xn1=(xn+ a/xn)/2;
		kt=fabs((xn1-xn)/xn);
		xn=xn1;
	}
	printf("Can bac 2 cua %f la %f", a, xn1);
	getch();
	return 0;
}

