#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void nhapMang(int *pa, int n){
	int i;
	for (i=0; i<n; i++)
	{
		printf("pa[%d]: ", i);
		scanf("%d", pa+i);
	}
}

void tongBinhPhuong(int *pa, int n){
	int i, sum=0;
	for (i=0; i<n; i++)
	{
		if (*(pa+i)>=0) continue;
		sum = sum + (*(pa+i))*(*(pa+i));
	}
	printf("\nTong Binh Phuong cac so am: %d", sum);
}

void xuatMang(int *pa, int n){
	int i;

	for (i=0; i<n; i++)
	{
		printf("%d ", *(pa+i));
	}
}
int main(){
	int *pa, i, n;
	pa=(int*)malloc(200);
	printf("Nhap so phan tu: n = "); scanf("%d", &n);
	nhapMang(&pa[0], n);
	printf("\nMang da nhap: ");
	xuatMang(&pa[0], n);
	tongBinhPhuong(&pa[0], n);
	free(pa);
	getch();
	return 0;
}
