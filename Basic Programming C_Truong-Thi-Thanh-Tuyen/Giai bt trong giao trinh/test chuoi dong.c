#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct SV{
	char *hoTen;
	char *diaChi;
	int diem;
}sv;

void nhapSV(sv **ds, int n){
	int i;
	for (i =0; i <n; i++){
		char temp[100];
		printf("Nhap sv thu %d: ", i +1);
		fflush(stdin); gets(temp); //dung fflush truoc lenh nhap chuoi
		ds[i]->hoTen = strdup(temp); //co the ghi ds[i]->hoTen
		printf("Nhap dia chi: ");
		fflush(stdin); gets(temp);
		ds[i]->diaChi = strdup(temp);
		printf("Nhap diem: "); scanf("%d", &ds[i][0].diem); 
	}
}

void xuatSV(sv **ds, int n){
	int i;
	for (i =0; i<n; i++){
		printf("Sinh vien thu %d: %s\n", i+1, ds[i][0].hoTen);
		printf("Dia chi: %s\n", ds[i][0].diaChi);
		printf("Diem: %d\n", ds[i][0].diem);
	}
}

int main(){
	int n, i;
	printf("Nhap so luong phan tu: n = "); scanf("%d", &n);
	sv **ds = NULL;
	ds =(sv**)malloc(sizeof(sv*) *n);
	for (i = 0; i< n; i++){
		ds[i]=(sv*)malloc(sizeof(sv)); //cap phat cho no
	}
	nhapSV(ds, n);
	xuatSV(ds, n);
	for (i = 0; i < n; i++){
   		free(ds[i]); //phai xoa tung hang roi moi xoa ds
	}
	free(ds);
	return 0;
}
/*

int main(){
	char **dsSV; //day coi nhu mang dong 2 chieu
	int soSV, i;
	printf("Nhap so sinh vien: "); scanf("%d", &soSV);
	fflush(stdin);
	dsSV = (char**)malloc(sizeof(char*) *soSV); //tuy y khai bao so luong, tuong duong voi cot
	for (i =0; i< soSV; i++){
		char temp[100];
		printf("Nhap SV thu %d: ", i+1);
		gets(temp);
		dsSV[i]=strdup(temp); //khoi tao va gan gia tri, tuong duong voi ham
		//cau lenh tuong duong:
		//(*sv).hoten = (char*)malloc(strlen(temp) + 1); //them phan tu ket thu chuoi \0
        //strcpy((*sv).hoten, temp);
	}
	for (i =0; i< soSV; i++){
		printf("Sinh vien thu %d: %s\n", i+1, dsSV[i]);
	}
	free(dsSV);
	return 0;
}

*/
