#include<stdio.h>
#include<conio.h>

void input(int a[50][50], int row, int column){
	int i;
	for (i=0;i<row*column;i++){
		printf("Phan tu a[%d][%d]: ", i/column, i%column);
		scanf("%d", &a[i/column][i%column]);
	}
}
int BCNN(int a, int b){
	//minh tim uoc chung nho nhat truoc
	int i=a, j=b;
	int r, bCNN;
	while (b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	bCNN=j*i/a;
	return (bCNN);
}

void maTranTamGiac(int a[50][50], int row, int column){
	int i=0, j=0, k, temp;
	int bcnn, bca, bcb;
	for (i=0; i<=row-2;i++){
		k=i+1;
		if (a[i][i]==0){
			for (j=0;j<column;j++){
				temp=a[i][j];
				a[i][j]=a[i+1][j];
				a[i+1][j]=temp;
			}
			i--;
		}
		else if (a[i][i]!=0) {
			while (k<=row-1){
				//tinh he so nhan vao tung dong tranh dang thap phan
				bcnn = BCNN(a[i][i], a[k][i]);
				bca = bcnn/a[i][i];
				bcb = bcnn/a[k][i];
				//thay doi gia tri tung phan tu trong hang
				for (j=0;j<column;j++){
					a[k][j]=bcb*a[k][j] - bca*a[i][j];
				} 
				k++;
			}
		}
			
	}
}

void dinhThuc(int a[50][50], int row, int column){
	int i, j, dinhthuc=1;
	for (i=0;i<row;i++){
			dinhthuc*=a[i][i];
	}
	printf("Dinh thuc ma tran vuong A cap %d la: %d", column, dinhthuc);
}

void output(int a[50][50], int row, int column){
	int i;
	for (i=0;i<row*column;i++){
		if (i%column==0) printf("\n");
		printf("%-3d", a[i/column][i%column]);
	}
	printf("\n");
}

int main(){
	int a[50][50], n;
	printf("Nhap n = "); scanf("%d", &n);
	printf("Nhap ma tran A cap %d:\n", n);
	input(a, n, n);
	printf("Ma tran vuong A cap %d:", n);
	output(a, n, n);
	maTranTamGiac(a, n, n);
	printf("Ma tran tam giac A:");
	output(a, n, n);
	dinhThuc(a, n, n);
	return 0;
}










