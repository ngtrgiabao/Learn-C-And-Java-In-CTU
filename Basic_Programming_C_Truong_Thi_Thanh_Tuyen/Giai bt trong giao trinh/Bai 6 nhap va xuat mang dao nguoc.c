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

void xuatMangDao(int *pa, int m, int n){
	int i, j;
	printf("Ma tran sau khi dao:\n");
	for (i=0; i<n; i++)
	{
		for (j=0;j<m;j++)
		{
			printf("%d ", *(pa + j*n + i));
		}
		printf("\n");
	}
}

int main()
{
	int *pa=NULL, m, n;
	pa=(int*)malloc(200);
	do {
		printf("Nhap so dong: m = "); scanf("%d", &m);
		printf("      so cot: n = "); scanf("%d", &n);
	} while (n<0||m<0);
	nhapMang(&pa[0],m, n);
	xuatMang(&pa[0],m, n);
	xuatMangDao(&pa[0],m, n);
	free(pa);
	getch();
	return 0;
}
