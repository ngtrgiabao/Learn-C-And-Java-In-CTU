#include<stdio.h>
#include<conio.h>

void nhapMang(int a[][50], int m, int n){
	int i, j;
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			printf("	a[%d][%d]: ", i, j);
		scanf("%d", &a[i][j]);
		}
	
	}
}

void xuatMang(int a[][50], int m, int n){
	int i, j;
	printf("Ma tran vua nhap:\n");
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void xuLyKiTuNhap(int a[][50], int m, int n, int nhap){
	int i, j, dem=0;
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			if (a[i][j]==nhap)
			{
				dem+=1;
				printf("\nVi tri thu %d o phan tu: [%d][%d]", dem, i, j);
			}
		}
	}
	if (dem==0) printf("\nKhong co su xuat hien cua so %d trong ma tran!", nhap);
		else printf("\nCo %d phan tu trung voi so %d", dem, nhap);
}

int main()
{
	int a[50][50], m, n, nhap;
	do {
		printf("Nhap so dong: m = "); scanf("%d", &m);
		printf("      so cot: n = "); scanf("%d", &n);
	} while (n<0||m<0);
	nhapMang(a,m, n);
	xuatMang(a,m, n);
	printf("Nhap so: "); scanf("%d", &nhap);
	xuLyKiTuNhap(a,m,n, nhap);
	getch();
	return 0;
}
