#include<stdio.h>
#include<conio.h>

int fibonacci(int n)
{
	if (n==1) return 1;
	if (n==2) return 2;
	if (n>2) return (fibonacci(n-1) + fibonacci(n-2));
}

int main()
{
	int i, n;
	printf("Nhap so chu so n = "); scanf("%d", &n);
	printf("So fibonacci thu %d la: %d\n", n, fibonacci(n));
	printf("Day fibonacci tu dau den so thu %d gom: ", n);
	for (i=1; i<=n; i++)
	{
		printf("%d ", fibonacci(i));
	}	
	getch();
	return 0;
}
