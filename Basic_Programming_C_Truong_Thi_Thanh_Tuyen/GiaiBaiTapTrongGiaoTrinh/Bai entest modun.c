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

void xapXepMang(int *pa, int n){
	int i, j, temp;
	for (i=0; i<n-1; i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (*(pa+i)>*(pa+j))
			{
				temp=*(pa+i);
				*(pa+i)=*(pa+j);
				*(pa+j)=temp;
			}
		}
	}
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
	xapXepMang(&pa[0], n);
	printf("\nMang da sap xep: ");
	xuatMang(&pa[0], n);
	free(pa);
	getch();
	return 0;
}
