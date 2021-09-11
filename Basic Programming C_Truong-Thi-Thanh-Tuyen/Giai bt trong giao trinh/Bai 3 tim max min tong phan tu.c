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

void xuLyMang(int *pa, int n){
	int i, sum=0, max=*pa, min=*pa;
	for (i=0; i<n; i++)
	{
		if (*(pa+i)>max) max=*(pa+i);
		if (*(pa+i)<min) min=*(pa+i);
		sum+=*(pa+i);
	}
	printf("\nPhan tu lon nhat: %d", max);
	printf("\nPhan tu nho nhat: %d", min);
	printf("\nTong cac phan tu: %d", sum);
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
	pa=(int*)malloc(4);
	printf("Nhap so phan tu: n = "); scanf("%d", &n);
	nhapMang(&pa[0], n);
	printf("\nMang da nhap: ");
	xuatMang(&pa[0], n);
	xuLyMang(&pa[0], n);
	free(pa);
	getch();
	return 0;
}
