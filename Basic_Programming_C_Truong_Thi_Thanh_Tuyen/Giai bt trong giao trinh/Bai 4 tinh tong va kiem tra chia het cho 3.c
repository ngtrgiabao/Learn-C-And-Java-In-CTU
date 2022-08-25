#include<stdio.h>
#include<conio.h>

int tong(int a)
{
	int count=0;
	while(a>0 || a<0)
	{
		count = count + a%10;
		a/=10;
	}
	return count;
}

int main()
{
	int a;
	printf("Nhap a = "); scanf("%d", &a);
	if (tong(a)%3==0) printf("So %d chia het cho 3", a);
		else if (tong(a)%3!=0) printf("So %d khong chia het cho 3", a);
	getch();
	return 0;
}
