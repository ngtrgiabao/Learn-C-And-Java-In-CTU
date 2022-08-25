#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void nhapMang(int *pa, int m, int n){
	int i, j;
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			printf("phan tu pa[%d][%d]: ", i, j);
			scanf("%d", pa + n*i + j);
		}
	
	}
}

void xuatMang(int *pa, int m, int n){
	int i, j;
	printf("Ma tran vua nhap:\n");
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%d ", *(pa + n*i + j));
		}
		printf("\n");
	}
}

void xuLyKiTuNhap(int *pa, int m, int n, int nhap){
	int i, j, dem=0;
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			if (*(pa+ n*i + j)==nhap)
			{
				dem+=1;
				printf("\nVi tri thu %d o phan tu: pa[%d][%d]", dem, i, j);
			}
		}
	}
	if (dem==0) printf("\nKhong co su xuat hien cua so %d trong ma tran!", nhap);
		else printf("\nCo %d phan tu trung voi so %d", dem, nhap);
}

int main()
{
	int *pa=NULL, m, n, nhap;
	pa=(int*)malloc(200);
	do {
		printf("Nhap so dong: m = "); scanf("%d", &m);
		printf("      so cot: n = "); scanf("%d", &n);
	} while (n<0||m<0);
	nhapMang(&pa[0],m, n);
	xuatMang(&pa[0],m, n);
	printf("Nhap so: "); scanf("%d", &nhap);
	xuLyKiTuNhap(&pa[0],m,n, nhap);
	free(pa);
	getch();
	return 0;
}
