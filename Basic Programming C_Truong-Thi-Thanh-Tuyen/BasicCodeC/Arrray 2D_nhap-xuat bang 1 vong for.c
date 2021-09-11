#include<stdio.h>
#include<malloc.h>

// dung 1 vong lap thi se tien khi sap xep mang 2 chieu
void inputArr(int arr[][50], int lengthRow, int lengthCol){
	int i;
    for (i =0; i<lengthRow*lengthCol; i++){
    	printf("Phan tu arr[%d][%d]: ", i/lengthCol, i%lengthCol);
        scanf("%d", &arr[i/lengthCol][i%lengthCol]);
    }
}

void outputArr(int arr[][50], int lengthRow, int lengthCol){
	int i;
    for (i =0; i<lengthRow*lengthCol; i++){
        printf("%d ", arr[i/lengthCol][i%lengthCol]);
        if ((i+1)%lengthCol == 0) printf("\n");
    }
}

void outputBrr(int **brr, int lengthRow, int lengthCol){
	int i;
    for (i =0; i<lengthRow*lengthCol; i++){
        printf("%d ", brr[i/lengthCol][i%lengthCol]);
        if ((i+1)%lengthCol == 0) printf("\n");
    }
}

int **daoPhanTu(int arr[][50], int lengthRow, int lengthCol){
	int i, j;
	int **brr;
	brr = (int**) malloc(sizeof(int*)*lengthCol);
	for (i=0; i<lengthRow; i++){
		brr[i] = (int*) malloc(sizeof(int)); 
	}
	for (i=0; i<lengthCol; i++){
		for (j=0; j<lengthRow; j++){
			brr[i][j] = arr[i][j];
		}
	}
	return brr;
}

int main(){
	int arr[50][50], r, c;
	int **brr;
	printf("Nhap so dong r = "); scanf("%d", &r);
	printf("Nhap so dong c = "); scanf("%d", &c);
	inputArr(arr, r, c);
	printf("Mang da nhap: \n");
	outputArr(arr, r, c);
	brr = daoPhanTu(arr, r, c);
	printf("Mang sau khi dao: \n");
	outputBrr(brr, c, r);
	int i;
	for (i=0; i<r; i++){
		free(brr[i]);
	}
	free(brr);
	return 0;
}
