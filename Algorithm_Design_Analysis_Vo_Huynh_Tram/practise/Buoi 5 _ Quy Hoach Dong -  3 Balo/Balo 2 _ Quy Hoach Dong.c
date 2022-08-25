// Bai toan cai ba lo 1
// Moi do vat co so luong khong han che
// Du lieu cho trong file QHD_CaiBalo.INP
// Giai bai toan bang thuat toan QUY HOACH DONG

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char TenDV[20];
	int TL, GT, PA, SL; // Khai bao them truong so luong
} DoVat;

typedef int bang[50][100];// Ba lo co trong luong toi da 99 va co toi da 50 do vat

DoVat *ReadFromFile(int *W, int *n){
	FILE *f;
	f = fopen("QHD_CaiBalo2.INP", "r");
	fscanf(f, "%d",W); // Xac dinh trong luong Ba lo
	DoVat *dsdv = (DoVat*) malloc(sizeof(DoVat));
	int i = 0;
	while (!feof(f)){
		fscanf(f, "%d%d%d%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL, &dsdv[i].TenDV);
		dsdv[i].PA=0;
		i++;
		dsdv= (DoVat*) realloc(dsdv, sizeof(DoVat)*(i+1));  
	}
	*n=i;
	fclose(f);
	return dsdv;
}

int W;

void InDSDV(DoVat *dsdv , int n){ // Them in cot so luong
	int i, TongTL=0, TongGT=0;
	printf("\nPhuong an Cai Ba lo 1 dung thuat toan QUY HOACH DONG nhu sau:\n");
	printf("|---|------------------|----------|---------|-----------|-----------|\n");
	printf("|STT|     Ten Do Vat   | T Luong  | Gia Tri | So Luong  | Phuong an |\n");
	printf("|---|------------------|----------|---------|-----------|-----------|\n");
	for(i=0;i<n;i++){
		printf("|%2d |%-18s|%5d     |%5d    |%6d     |%6d     |\n",
		i+1, dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].SL, dsdv[i].PA);
		TongTL += dsdv[i].PA * dsdv[i].TL;
		TongGT += dsdv[i].PA * dsdv[i].GT;
	}	
	printf("|---|------------------|----------|---------|-----------|-----------|\n");	
	printf("Trong luong cua ba lo = %-9d\n", W);
	printf("Tong trong luong = %-9d\n", TongTL);
	printf("Tong gia tri = %-9d\n", TongGT);
}

int min(int a, int b){
	return (a<=b) ? a : b;
}

void TaoBang(DoVat *dsdv, int n, bang F, bang X){
 	int xk, yk, k;
 	int FMax, XMax, V;
	// Dien dong dau tien cua hai bang
 	for(V= 0; V<=W; V++) {
 		X[0][V] = min(V/dsdv[0].TL, dsdv[0].SL); // change
 		F[0][V] = X[0][V] * dsdv[0].GT;
 	}
	for(k= 1; k<n; k++){ // Dien cac dong con lai cua hai bang
		 for(V=0; V<=W; V++) {
			 FMax = F[k-1][V] ;
			 XMax = 0;
			 yk = min(V/dsdv[k].TL, dsdv[k].SL); // change
			 for(xk = 1; xk<=yk; xk++)
			 	if(F[k-1][V-xk*dsdv[k].TL] + xk*dsdv[k].GT > FMax){ // Cong thuc tinh can
			 		FMax = F[k-1][V-xk*dsdv[k].TL] + xk*dsdv[k].GT;
			 		XMax = xk;
			 	}
			 F[k][V] = FMax;
			 X[k][V] = XMax;
	 	}
	}
}

void InBang(int n, bang F, bang X){
	printf("Bang Ket qua chay tay:\n");
	int V, k;
	for(k = 0; k<n; k++){
		for(V=0; V<=W; V++)
		 	printf("|%3d%2d ", F[k][V], X[k][V]);
		printf("|\n");
	}
}

void TraBang(DoVat *dsdv, int n, bang X) {
	int k, V = W;
	for(k= n-1; k>=0; k--) {
	 	dsdv[k].PA = X[k][V];
	 	V -= X[k][V] * dsdv[k].TL;
	}
}

int main(){
	int n;
	bang X, F;
	DoVat *dsdv;
	dsdv = ReadFromFile(&W, &n);
	TaoBang(dsdv, n, F, X);
	InBang(n, F,X);
	TraBang(dsdv, n, X);
	InDSDV(dsdv, n);
	free(dsdv);
	return 0;
}
