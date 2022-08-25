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
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
}

void timPhanTuLe(int a[], int n){
	int i, dem=0;
	printf("\n1. Cac so le: ");
	for (i=0; i<n; i++)
	{	
		if (a[i]%2==1)
		{
			printf("%d ", a[i]);
			dem+=1;
		}
	}
	printf(".Co %d (so)", dem);
}

void timPhanTuChan(int a[], int n){
	int i, dem=0;
	printf("\n2. Cac so chan: ");
	for (i=0; i<n; i++)
	{	
		if (a[i]%2==0)
		{
			printf("%d ", a[i]);
			dem+=1;
		}
	}
	printf(".Co %d (so)", dem);
}

void timPhanTuNguyenTo(int a[], int n){
	int i, j, dem=0, kt=0;
	printf("\n3. Cac so nguyen to: ");
	for (i=0; i<n; i++)
	{	
		if (a[i]<=1) continue;
		if (a[i]==2) 
		{
			printf("%d ", a[i]);
			dem+=1;
		}
		if (a[i]>2)
		{
			for (j=2;j<a[i];j++)
			{
				if (a[i]%j==0) kt+=1;
			}
			if (kt==0) 
			{
				printf("%d ", a[i]);
				dem+=1;
			}
		kt=0;
		}	
	}
	printf(".Co %d (so)", dem);
}

void timPhanTuKhongPhaiNguyenTo(int a[], int n){
	int i, j, dem=0, kt=0;
	printf("\n4. Cac so khac nguyen to: ");
	for (i=0; i<n; i++)
	{	
		if (a[i]<=2) continue;
		if (a[i]>2)
		{
			for (j=2;j<a[i];j++)
			{
				if (a[i]%j==0) kt+=1;
			}
			if (kt!=0) 
			{
				printf("%d ", a[i]);
				dem+=1;
			}
		kt=0;
		}	
	}
	printf(".Co %d (so)", dem);
}

int main()
{
	int a[50], n;
	do {
		printf("Nhap so phan tu: n = "); scanf("%d", &n);
	} while (n<=0);
	nhapMang(a,n);
	printf("\nMang vua nhap: ");
	xuatMang(a,n);
	timPhanTuLe(a,n);
	timPhanTuChan(a,n);
	timPhanTuNguyenTo(a,n);
	timPhanTuKhongPhaiNguyenTo(a,n);
	getch();
	return 0;
}
