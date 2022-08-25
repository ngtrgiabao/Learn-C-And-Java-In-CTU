#include<stdio.h>

typedef struct maTen{
	char Ma[5];
	char Ten[50];
} mt;

void ghiDuLieuVaoFile(mt a[50], FILE *file){
	int count=0, i;
	printf("Luu y: Go chu ENTER vao Ma de ket thuc viec nhap!\n");
	while (!feof(file)){
		printf("Sinh vien thu %d\n", count+1);
		printf("Ma:"); scanf("%s", a[count].Ma);
		if (a[count].Ma=="ENTER") break; //cau len nay sai!
		fflush(stdin);
		printf("Ten: "); gets(a[count].Ten);
		count+=1;
	};
	for (i=0; i<count; i++){
		fprintf(file, "%-5s", a[i].Ma);
		fprintf(file, "%-50s\n", a[i].Ten);
	}; 
	printf("\nNhap du lieu hoan tat!\n");
	fclose(file);
}

int main(){
	FILE *f;
	mt a[50];
	int chon=10, soLuong;
	f=fopen("C:\\DMHH.txt","w");
	while (chon!=2){
		printf("1.Nhap du lieu.\n");
		printf("2.Thoat.\n");
		printf("Ban chon? "); scanf("%d", &chon);
		if (chon==1){
			system("cls");
			if (f!=NULL){
				ghiDuLieuVaoFile(a, f);
			} else printf("Loi khi mo file!");
		}
		break;
	}
	return 0;
}
