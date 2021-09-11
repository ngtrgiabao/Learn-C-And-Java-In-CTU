#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	char TenDV[20];
	float TL, GT, DG;
	int PA;
} DoVat;

DoVat* ReadFromFile(float *w, int *n){
	FILE *f = fopen("D:\\Buoi 3\\CaiBalo3.txt", "r");
	fscanf(f, "%f", w); 
	DoVat *dsdv;
	dsdv= (DoVat*) malloc(sizeof(DoVat));
	int i = 0;
	while (!feof(f)){
		fscanf(f, "%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].TenDV);
		dsdv[i].DG=dsdv[i].GT/dsdv[i].TL;
		dsdv[i].PA=0;
		i++;
		dsdv=(DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
	}
	*n=i;
	fclose(f);
	return dsdv;
}

void swap(DoVat *x, DoVat *y){
	DoVat Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
}

void BubbleSort(DoVat *dsdv, int n){
	int i,j;
	for(i=0; i<=n-2; i++){
		for (j=n-1; j>=i+1; j--){
		if (dsdv[j].DG>dsdv[j-1].DG)
			swap(&dsdv[j],&dsdv[j-1]);
		}
	}
}

void InDSDV(DoVat *dsdv, int n, float W){
	int i;
	float TongTL=0.0, TongGT=0.0;
	printf("\nPhuong an Cai Ba lo 1 dung thuat toan THAM AN nhu sau:\n");
	printf("|---|------------------|---------|---------|---------|----------|\n");
	printf("|STT| Ten Do Vat       | T Luong | Gia Tri | Don Gia | Phuong an|\n");
	printf("|---|------------------|---------|---------|---------|----------|\n");
	for(i=0;i<n;i++){
		printf("|%2d |%-18s|%9.2f|%9.2f|%9.2f|%10d|\n",
		i+1,dsdv[i].TenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG,dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}
	printf("|---|------------------|---------|---------|---------|----------|\n");
	printf("Trong luong cua ba lo = %-9.2f\n",W);
	printf("Tong trong luong = %-9.2f\n",TongTL);
	printf("Tong gia tri = %-9.2f\n",TongGT);
}

// Balo 3: so luong do vat deu = 1
void Greedy1(DoVat *dsdv, int n, float W){
	int i;
	for (i=0; i<n; i++){
		if (W >= dsdv[i].TL){
			dsdv[i].PA = 1;
			W -= dsdv[i].TL;
		}
		else {
			dsdv[i].PA = 0;
		}
	}
}


int main(){
	int n;
	float W;
	DoVat *dsdv = ReadFromFile(&W, &n);
	BubbleSort(dsdv,n);
	Greedy1(dsdv, n, W);
	InDSDV(dsdv, n, W);
	free(dsdv);
	return 0;
}
