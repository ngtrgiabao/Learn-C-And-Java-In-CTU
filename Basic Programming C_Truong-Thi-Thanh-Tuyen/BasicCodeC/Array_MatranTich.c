#include<stdio.h>

void inputArray(int a[][50], int m, int n){
	int i, j;
	for (i=0; i<m; i++){
		for (j=0;j<n;j++){
			printf("Phan tu [%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void outputArray(int a[][50], int m, int n){
	int i, j;
	for (i=0; i<m; i++){
		for (j=0;j<n;j++){
			printf("%-3d ", a[i][j]);
		}
		printf("\n");
	}
}

void ArrayAfterMultiplyTwoArrayInput(int a[][50], int b[][50], int c[][50], int m, int k, int n){
	int i, j, z, T;
	for (i=0; i<m; i++){
		for (j=0;j<n;j++){
			c[i][j]=0;
			for (z=0;z<k;z++){
				c[i][j]+=a[i][z]*b[z][j];
			}
			printf("%-3d ", c[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int a[50][50], b[50][50], c[50][50], m, n, k;
	do {
		printf("Nhap: m = "); scanf("%d", &m);
		printf("      k = "); scanf("%d", &k);
		printf("      n = "); scanf("%d", &n);
	} while ((n<0||m<0) || (k<0));
	printf("Nhap ma tran A cap (%d,%d):\n", m, k);
	inputArray(a,m,k);
	printf("Nhap ma tran B cap (%d,%d):\n", k, n);
	inputArray(b,k,n);
	printf("Ma tran A vua nhap:\n");
	outputArray(a,m,k);
	printf("Ma tran B vua nhap:\n");
	outputArray(b,k,n);
	printf("Ma tran tich C cap (%d,%d):\n", m, n);
	ArrayAfterMultiplyTwoArrayInput(a,b,c,m,k,n);
	return 0;
}
