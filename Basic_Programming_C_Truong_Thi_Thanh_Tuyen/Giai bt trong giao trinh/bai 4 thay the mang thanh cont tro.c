#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int main(){
	int *pa=NULL, i, n;
	pa=(int *)malloc(100);
	printf("Nhap so phan tu: n = "); scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		printf("pa[%d]: ", i);
		scanf("%d", pa+i);
	}
	int max=*pa, min=*pa, sum=0;
	printf("\nMang da nhap:\n");
	for (i=0; i<n; i++)
	{
		printf("Phan tu pa[%d]: %d\n", i, *(pa+i));
	}
	for (i=0; i<n; i++)
	{
		if (*(pa+i)>max) max=*(pa+i);
		if (*(pa+i)<min) min=*(pa+i);
		sum+=*(pa+i);
	}
	printf("Phan tu max: %d\n", max);
	printf("Phan tu min: %d\n", min);
	printf("Tong phan tu: %d\n", sum);
	free(pa);
	getch();
	return 0;
}
