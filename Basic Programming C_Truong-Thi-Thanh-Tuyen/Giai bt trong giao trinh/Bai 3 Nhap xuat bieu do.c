#include<stdio.h>
#include<conio.h>

void inhang(int a, int b, int c, int d, int e)
{
	int i;
	printf("\nCua hang 1:	");
	for (i=1;i<=a;i++)
	{
		printf("%-2c", (char) 176);
	}
	printf("\n\n");
	printf("Cua hang 2:	");
	for (i=1;i<=b;i++)
	{
		printf("%-2c", (char) 177);
	}
	printf("\n\n");
	printf("Cua hang 3:	");
	for (i=1;i<=c;i++)
	{
		printf("%-2c", (char) 178);
	}
	printf("\n\n");
	printf("Cua hang 4:	");
	for (i=1;i<=d;i++)
	{
		printf("%-2c", (char) 254);
	}
	printf("\n\n");
	printf("Cua hang 5:	");
	for (i=1;i<=e;i++)
	{
		printf("%-2c", (char) 240);
	}
}

int main()
{
	int a, b, c, d, e, f, i;
	//printf("Cac dang ki tu cua bieu do:\n%c = 176\n%c = 177\n%c = 178\n%c = 254\n%c = 240\n", (char) 176, (char) 177, (char) 178, (char) 254, (char) 240);
	printf("Cua hang 1: "); scanf("%d", &a);
	printf("Cua hang 2: "); scanf("%d", &b);
	printf("Cua hang 3: "); scanf("%d", &c);
	printf("Cua hang 4: "); scanf("%d", &d);
	printf("Cua hang 5: "); scanf("%d", &e);
	printf("\n\nBIEU DO BAN MAT HANG A O 5 CUA HANG");
	inhang(a, b, c, d, e);
	getch();
	return 0;
}
