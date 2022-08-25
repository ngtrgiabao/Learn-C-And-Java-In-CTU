#include<stdio.h>
#include<conio.h>

float max(float a, float b){
	if (a >= b) return a;
	return b;
}

float min(float a, float b){
	if (a <= b) return a;
	return b;
}

int main()
{
	float a, b, c;
	printf("Nhap a = "); scanf("%f", &a);
	printf("     b = "); scanf("%f", &b);
	printf("     c = "); scanf("%f", &c);
	printf("\nSo lon nhat la: %.2f\n", max(a, max(b, c)));
	printf("\nSo nho nhat la: %.2f\n", min(a, min(b, c)));
	return 0;
}
