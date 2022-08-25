#include<stdio.h>
#include<malloc.h>

typedef struct sv{
	int stt;
	char ten[50];
	int tuoi;
} sv;
//vay co hai cach tao doi tuong 
//xem ra kieu xu ly doi tuong ngoai se hop ly hon
sv** nhapTen(){
	sv **a;
	int i, n;
	printf("Nhap so luong: n = "); scanf("%d", &n);
	a = (sv**)malloc(sizeof(sv*) *n);
	for (i = 0; i < n; i++){
		a[i] = (sv*)malloc(sizeof(sv));
		printf("Sinh vien thu %d\n", i +1);
		printf("Nhap stt: "); scanf("%d", &a[i]->stt);
		printf("Nhap ten: "); fflush(stdin);  gets(a[i]->ten);
		printf("Nhap tuoi: "); scanf("%d", &a[i]->tuoi);
	}
	//luu y con tro a se khong bi mat di ma duoc p tro den
	return a;
}
void xuatTen(sv **a, int n){
	int i; 
	for (i =0 ; i< n; i++){
		printf("sinh vien thu %d\n", i+1);
		printf("stt: %d\nTen: %s\ntuoi: %d\n\n", a[i]->stt, a[i]->ten, a[i]->tuoi);
	}
}

int main(){
	sv **p;
	int i;
	p = nhapTen(n); // cach kia tong quat hon nhapTen(sv **a, int n);
	xuatTen(p, n);
	for (i = 0; i< n; i++){
		free(p[i]);
	}
	free(p);
	
}
