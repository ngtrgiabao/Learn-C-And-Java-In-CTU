#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void nhapMang(int *pa, int n){
	int i;
	for (i=0; i<n; i++)
	{
		printf("Phan tu pa[%d]: ", i);
		scanf("%d", pa+i);
	}
}

void xuatMang(int *pa, int n){
	int i;
	printf("\nMang da nhap: ");
	for (i=0; i<n; i++)
	{
		printf("%d ", *(pa+i));
	}
}

void daoPhanTu(int *pa, int n){
	int i, tam;
	if (n%2==0)
	{
		for (i=0;i<n/2;i++)
		{
			tam=*(pa+i);
			*(pa+i)=*(pa +n -i -1);
			*(pa +n -i -1)=tam;
		}
	}
	if (n%2==1)
	{
		for (i=0;i<(n-1)/2;i++)
		{
			tam=*(pa+i);
			*(pa+i)=*(pa +n -i -1);
			*(pa +n  -i -1)=tam;
		}
	}
	printf("\nMang sau khi dao: ");
	for (i=0; i<n; i++)
	{
		printf("%d ", *(pa+i));
	}
	
}

int main()
{
	int *pa, n;
	pa=(int*)malloc(200);
	do {
		printf("Nhap so phan tu: n = "); scanf("%d", &n);
	} while (n<=0);
	nhapMang(&pa[0],n);
	xuatMang(&pa[0],n);
	daoPhanTu(&pa[0],n);
	getch();
	return 0;
}
