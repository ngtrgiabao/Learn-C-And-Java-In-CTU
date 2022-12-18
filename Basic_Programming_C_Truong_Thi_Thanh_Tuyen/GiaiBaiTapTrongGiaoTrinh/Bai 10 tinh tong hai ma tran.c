#include<stdio.h>
#include<conio.h>

void nhapMang(int a[][50], int m, int n){
	int i, j;
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			printf("	Phan tu [%d][%d]: ", i, j);
		scanf("%d", &a[i][j]);
		}
	
	}
}

void xuatMang(int a[][50], int m, int n){
	int i, j;
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%-3d ", a[i][j]);
		}
		printf("\n");
	}
}

void xuatMangTong(int a[][50], int b[][50], int c[][50], int m, int n){
	int i, j;
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			printf("%-3d ", c[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int a[50][50], b[50][50], c[50][50], m, n;
	do {
		printf("Nhap so dong: m = "); scanf("%d", &m);
		printf("      so cot: n = "); scanf("%d", &n);
	} while (n<0||m<0);
	printf("Nhap ma tran a: \n");
	nhapMang(a,m, n);
	printf("Nhap ma tran b: \n");
	nhapMang(b,m, n);
	printf("Ma tran a vua nhap:\n");
	xuatMang(a,m, n);
	printf("Ma tran b vua nhap:\n");
	xuatMang(b,m, n);
	printf("Ma tran tong c:\n");
	xuatMangTong(a,b,c,m,n);
	getch();
	return 0;
}
