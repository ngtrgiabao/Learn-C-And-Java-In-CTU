#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void nhapMang(int *pa, int n){
	int i;
	for (i=0; i<n; i++)
	{
		printf("Phan Tu pa[%d]: ", i);
		scanf("%d", pa+i);
	}
}

void xuatMang(int *pa, int n){
	int i;
	for (i=0; i<n; i++)
	{
		printf("%d ", *(pa+i));
	}
}

void timPhanTuLe(int *pa, int n){
	int i, dem=0;
	printf("\n		");
	for (i=0; i<n; i++)
	{	
		if (*(pa+i)%2==1)
		{
			printf("%d ", *(pa+i));
			dem+=1;
		}
	}
	printf("\r1/ Co %d le gom: ", dem);
}

void timPhanTuChan(int *pa, int n){
	int i, dem=0;
	printf("\n		  ");
	for (i=0; i<n; i++)
	{	
		if (*(pa+i)%2==0)
		{
			printf("%d ", *(pa+i));
			dem+=1;
		}
	}
	printf("\r3/ Co %d chan gom: ", dem);
}

void timPhanTuNguyenTo(int *pa, int n){
	int i, j, dem=0, kt=0;
	printf("\n			  ");
	for (i=0; i<n; i++)
	{	
		if (*(pa+i)<=1) continue;
		if (*(pa+i)==2) 
		{
			printf("%d ", 2);
			dem+=1;
		}
		if (*(pa+i)>2)
		{
			for (j=2;j<*(pa+i);j++)
			{
				if (*(pa+i)%j==0) kt+=1;
			}
			if (kt==0) 
			{
				printf("%d ", *(pa+i));
				dem+=1;
			}
			kt=0;
		}	
	}
	printf("\r3/ Co %d so nguyen to gom: ", dem);
}

void timPhanTuKhongPhaiNguyenTo(int *pa, int n){
	int i, j, dem=0, kt=0;
	printf("\n			    ");
	for (i=0; i<n; i++)
	{	
		if (*(pa+i)==1) printf("%d ", 1);
		if (*(pa+i)<=2) continue;
		if (*(pa+i)>2)
		{
			for (j=2;j<*(pa+i);j++)
			{
				if (*(pa+i)%j==0) kt+=1;
			}
			if (kt!=0) 
			{
				printf("%d ", *(pa+i));
				dem+=1;
			}
			kt=0;
		}	
	}
	printf("\r4/ Co %d khac nguyen to gom: ", dem);
}

int main()
{
	int *pa=NULL, n;
	do {
		printf("Nhap so phan tu: n = "); scanf("%d", &n);
	} while (n<=0);
	pa=(int*)malloc(200);
	nhapMang(&pa[0],n);
	printf("\nMang vua nhap: ");
	xuatMang(&pa[0],n);
	timPhanTuLe(&pa[0],n);
	timPhanTuChan(&pa[0],n);
	timPhanTuNguyenTo(&pa[0],n);
	timPhanTuKhongPhaiNguyenTo(&pa[0],n);
	free(pa);
	getch();
	return 0;
}
