#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void nhapMang(int *pa, int m, int n){
	int i, j;
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			printf("Phan tu [%d][%d]: ", i, j);
		scanf("%d", pa +n*i +j);
		}
	
	}
}

void xuatMang(int *pa, int m, int n){
	int i, j;
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%-3d ", *(pa+ n*i +j));
		}
		printf("\n");
	}
}

void xuatMangTong(int *pa, int *pb, int *pc, int m, int n){
	int i, j;
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			*(pc+ n*i +j)=*(pa+ n*i +j)+*(pb+ n*i +j);
			printf("%-3d ", *(pc+ n*i +j));
		}
		printf("\n");
	}
}

int main()
{
	int *pa, *pb, *pc, m, n;
	pa=(int*)malloc(200);
	pb=(int*)malloc(200);
	pc=(int*)malloc(200);	do {
		printf("Nhap so dong: m = "); scanf("%d", &m);
		printf("      so cot: n = "); scanf("%d", &n);
	} while (n<0||m<0);
	printf("Nhap ma tran a: \n");
	nhapMang(&pa[0],m, n);
	printf("Nhap ma tran b: \n");
	nhapMang(&pb[0],m, n);
	printf("Ma tran a vua nhap:\n");
	xuatMang(&pa[0],m, n);
	printf("Ma tran b vua nhap:\n");
	xuatMang(&pb[0],m, n);
	printf("Ma tran tong c:\n");
	xuatMangTong(&pa[0],&pb[0],&pc[0],m,n);
	free(pa);
	free(pb);
	free(pc);
	getch();
	return 0;
}
