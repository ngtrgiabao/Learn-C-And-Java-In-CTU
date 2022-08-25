#include<stdio.h>
#include<conio.h>

void nhapMang(int a[][50], int n){
	int i, j;
	for (i=0; i<n; i++)
	{
		for (j=0;j<n;j++)
		{
			printf("	Phan tu [%d][%d]: ", i, j);
		scanf("%d", &a[i][j]);
		}
	
	}
}

void xuatMang(int a[][50], int n){
	int i, j;
	for (i=0; i<n; i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%-3d ", a[i][j]);
		}
		printf("\n");
	}
}

void chuyenMaTranTamGiac(int a[][50], int n){
	int i, k;
	for (i=0;i<=n-2;i++)
	{
		for (k=i+1;j<=n-1;j++)
		{
			if a[k][i]==0 k++;
			else if (a[k][i]!=0)
			{
				a[k][i+1]=-a[k][i+1]+ (-a[k][i+1]/a[k-1][i+1])*a[k-1]i+1];
 
			}
		}
	}
}

int main()
{
	int a[50][50], n;
	do {
		printf("Nhap: n = "); scanf("%d", &n);
	} while (n<0);
	printf("Nhap ma tran vuong A cap %d:\n", n);
	nhapMang(a,n);
	printf("Ma tran A vua nhap:\n");
	xuatMang(a,n);
	getch();
	return 0;
}
