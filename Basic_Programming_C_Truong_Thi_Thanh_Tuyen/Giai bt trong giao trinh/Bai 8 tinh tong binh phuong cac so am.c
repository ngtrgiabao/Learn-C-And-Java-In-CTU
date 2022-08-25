#include<stdio.h>
#include<conio.h>

void nhapMang(int a[], int n){
	int i;
	for (i=0; i<n; i++)
	{
		printf("	a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}

void xuatMang(int a[], int n){
	int i;
	printf("Mang da nhap: ");
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
}

int tongBinhPhuongSoAm(int a[], int n){
	int i, tong=0;
	printf("\nCac so am gom: ");
	for (i=0;i<n;i++)
	{
		if (a[i]<0)
		{
			printf("%d ", a[i]);
			tong=tong + a[i]*a[i];
		}
	}
	printf("\nTong binh phuong cac so am la: %d", tong);
}

int main()
{
	int a[50], n;
	do {
		printf("Nhap so phan tu: n = "); scanf("%d", &n);
	} while (n<=0);
	nhapMang(a,n);
	xuatMang(a,n);
	tongBinhPhuongSoAm(a,n);
	getch();
	return 0;
}
