#include<stdio.h>
#include<conio.h>

int ucln(int a, int b)
{
	int r;
	while (b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	int a, b, Ucln;
	printf("Nhap a = "); scanf("%d", &a);
	printf("     b = "); scanf("%d", &b);
	Ucln=ucln(a, b);
	printf("\nUCLN cua (%d, %d) la: %d\n", a, b, Ucln);
	if (Ucln==1) printf("Phan so %d/%d da toi gian.", a, b);
		else if (Ucln>1) 
		{	
			if (b/Ucln==1)
				printf("Phan so %d/%d chua toi gian\nPhan so toi gian la: %d/%d = %d", a, b, a/Ucln, b/Ucln, a/Ucln);
			else if (b/Ucln!=1)
				printf("Phan so %d/%d chua toi gian\nPhan so toi gian la: %d/%d", a, b, a/Ucln, b/Ucln);
		}
	getch();
	return 0;
}
