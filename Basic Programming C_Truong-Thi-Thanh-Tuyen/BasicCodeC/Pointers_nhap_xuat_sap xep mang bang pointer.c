#include<stdio.h>
#include<malloc.h>

void nhapMang(int *pa, int n){
	int i;
	for (i=0; i<n; i++)
	{
		printf("pa[%d]: ", i);
		scanf("%d", pa+i); // do pa mang dia chi nen pa + i se la dia chi o nho tiep theo
		//scanf("%d", &pa[i]); hoac ghi theo mang => &pa[i] = pa +i
	}
}

void interchangeSort(int *pa, int n){
	int i, j;
	for (i=0; i<n-1; i++){
		for (j=i+1;j<n;j++){
			if (*(pa+i)>*(pa+j)){
				*(pa+i) = *(pa+i) + *(pa+j) - (*(pa+j) = *(pa+i));
			}
		}
	}
}

void xuatMang(int *pa, int n){
	int i;
	for (i=0; i<n; i++){
		printf("%d ", *(pa+i));
		//printf("%d ", *(pa+i)); hoac ghi theo mang pa[i]
	}
}
int main(){
	int *pa=NULL; //luon gan pa = NULL tranh o nho mang rac
	int i, j, n;
	printf("Nhap so phan tu: n = "); scanf("%d", &n);
	pa = (int*)malloc(sizeof(int)*n); // cap phat vung nho cho n phan tu
		nhapMang(pa, n);
	printf("Mang da nhap: ");
		xuatMang(pa, n);
	printf("\nMang da sap xep: ");
		interchangeSort(pa, n);
		xuatMang(pa, n);
	free(pa); // giai phong vung nho
	return 0;
}

