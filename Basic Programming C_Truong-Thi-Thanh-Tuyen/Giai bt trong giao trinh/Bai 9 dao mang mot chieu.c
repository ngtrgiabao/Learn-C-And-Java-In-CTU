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

void daoPhanTu(int a[], int n){
	int i, tam;
	if (n%2==0)
	{
		for (i=0;i<n/2;i++)
		{
			tam=a[i];
			a[i]=a[n -1 -i];
			a[n -1 -i]=tam;
		}
	}
	if (n%2==1)
	{
		for (i=0;i<(n-1)/2;i++)
		{
			tam=a[i];
			a[i]=a[n -1 -i];
			a[n -1 -i]=tam;
		}
	}
	printf("\nMang sau khi dao: ");
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	
}

int main()
{
	int a[50], n;
	do {
		printf("Nhap so phan tu: n = "); scanf("%d", &n);
	} while (n<=0);
	nhapMang(a,n);
	xuatMang(a,n);
	daoPhanTu(a,n);
	getch();
	return 0;
}
