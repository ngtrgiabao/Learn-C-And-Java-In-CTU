#include<stdio.h>

typedef struct hoaDon{
	char mh[5];
	int sl;
	float dg;
	float st;
} hd;

typedef struct maTen{
	char Ma[5];
	char Ten[50];
} mt;

void nhapHoaDon(hd don[50], mt a[50], int soluong, FILE *file){
	int i;
	for (i=0; i<soluong; i++){
		printf("Sinh vien thu %d\n", i+1);
		printf("Ma: "); scanf("%s", a[i].Ma);
		fflush(stdin);
		printf("Ten: "); gets(a[i].Ten);
	}
	printf("\nNhap du lieu hoan tat!\n");
}

void docDuLieuMt(mt a[50], FILE *file){
	int i=0;
	char ss;
	while (!feof(file)){
		ss=fgetc(file);
		fscanf(file, "%s", a[i].Ma);
		fflush(stdin);
		fgets(a[i].Ten, 51, file);
	} 
	fclose(file);
}

int main(){
	FILE *f;
	sv a[50], hd don[50];
	int chon=10, soLuong;
	f=fopen("C:\\DMHH.txt","w");
	while (chon!=2){
		printf("1.Nhap du lieu.\n");
		printf("2.Thoat.\n");
		printf("Ban chon? "); scanf("%d", &chon);
		if (chon==1){
			printf("Nhap so luong sinh vien: "); scanf("%d", &soLuong);
			nhapSinhVien(a, soLuong);
			if (f!=NULL){
				ghiDuLieuVaoFile(a, soLuong, f);
			} else printf("Loi khi mo file!");
			break;
		}
	}
	
	return 0;
}
