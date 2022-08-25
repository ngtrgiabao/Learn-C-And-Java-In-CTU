#include<stdio.h>
#include<malloc.h>

void nhapMang(int *pa, int n){
	int i;
	for (i=0; i<n; i++){
		printf("Phan Tu pa[%d]: ", i);
		scanf("%d", pa+i);
	}
}

void xuatMang(int *pa, int n){
	int i;
	for (i=0; i<n; i++){
		printf("%d ", *(pa+i));
	}
}

void timPhanTuLe(int *pa, int n){
	int i, dem=0;
	printf("\n		");
	for (i=0; i<n; i++){	
		if (*(pa+i)%2==1){
			printf("%d ", *(pa+i));
			dem++;
		}
	}
	printf("\r1/ Co %d le gom: ", dem); // \r tro ve dau dong
}

void timPhanTuChan(int *pa, int n){
	int i, dem=0;
	printf("\n		  ");
	for (i=0; i<n; i++){	
		if (*(pa+i)%2==0){
			printf("%d ", *(pa+i));
			dem++;
		}
	}
	printf("\r3/ Co %d chan gom: ", dem);
}

int checkPrime(int n){
	if (n<2) return 0;
	else if (n==2 || n==3 || n==5 || n==7 || n==9) return 1;
	else if (n%2==0 || n%3==0 || n%5==0 || n%7==0 ) return 0;
	else if (n>10) {
		int i;
		for (i=3; i*i<n; i+=2){
			if (n%i==0) return 0;
		}
		return 1;
	}
}

void timPhanTuNguyenTo(int *pa, int n){
	int i, j, dem=0, kt=0;
	printf("\n			  ");
	for (i=0; i<n; i++){
		if (checkPrime(*(pa+i))) {
			printf("%d ", *(pa+i));
			dem++;
		}	
	}
	printf("\r3/ Co %d so nguyen to gom: ", dem);
}

void timPhanTuKhongPhaiNguyenTo(int *pa, int n){
	int i, j, dem=0, kt=0;
	printf("\n			    ");
	for (i=0; i<n; i++){
		if (!checkPrime(*(pa+i))) {
			printf("%d ", *(pa+i));
			dem++;
		}	
	}
	printf("\r4/ Co %d khac nguyen to gom: ", dem);
}

int main(){
	int *pa=NULL, n;
	do {
		printf("Nhap so phan tu: n = "); scanf("%d", &n);
	} while (n<=0);
	pa=(int*)malloc(sizeof(int)*200); 
	nhapMang(pa,n);
	printf("\nMang vua nhap: ");
	xuatMang(pa,n);
	timPhanTuLe(pa,n);
	timPhanTuChan(pa,n);
	timPhanTuNguyenTo(pa,n);
	timPhanTuKhongPhaiNguyenTo(pa,n);
	free(pa);
	return 0;
}
