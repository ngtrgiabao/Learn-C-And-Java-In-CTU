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
	printf("\nMang da nhap: ");
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
}

void xuLyMang(int a[], int n){
	int i, demimax=0, demimin=0, max=a[0], min=a[0], tong=0;
	for (i=0;i<n;i++)
	{
		if (a[i]>max) 
		{
			max=a[i];
			demimax=i;
		}
		if (a[i]<min) 
		{
			min=a[i];
			demimin=i;
		}
		tong+=a[i];
	}
	printf("\nPhan tu lon nhat cua mang: %d\n                   Vi tri: %d", max, demimax);
	printf("\nPhan tu nho nhat cua mang: %d\n                   Vi tri: %d", min, demimin);
	printf("\nTong cac phan tu: %d", tong);
}

int main()
{
	int a[50], n;
	do {
		printf("Nhap so phan tu: n = "); scanf("%d", &n);
	} while (n<=0);
	nhapMang(a,n);
	xuatMang(a,n);
	xuLyMang(a,n);
	getch();
	return 0;
}
