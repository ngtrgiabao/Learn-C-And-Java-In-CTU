#include<stdio.h>
#include<conio.h>

float max(float a, float b)
{
	if (a>=b) return a;
		else return b;
}

int main()
{
	float a, b, c;
	printf("Nhap a = "); scanf("%f", &a);
	printf("     b = "); scanf("%f", &b);
	printf("     c = "); scanf("%f", &c);
	printf("\nSo lon nhat trong (%.2f, %.2f, %.2f) la: %.2f", a, b, c, max(a, max(b, c)));
	getch();
	return 0;
}
