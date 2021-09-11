#include<stdio.h>

int main(){
	FILE *f;
	char chuoi[80];
	
	printf("Cau a_Nhap chuoi de ghi vao file van ban:\n");
	f=fopen("C:\\Bai 1 van ban.txt", "w");
	if (f!=NULL) {
		fflush(stdin);
		printf("Nhap noi dung: ");
		gets(chuoi);
		fprintf(f,"%s", chuoi);
	}
	fclose(f);
	
	printf("\nCau b_Doc tu file van ban va in ra man hinh:\n");
	f=fopen("C:\\Bai 1 van ban.txt", "r");
	while (!feof(f)){
		fgets(chuoi, 81, f);
		printf("%s", chuoi);
	}
	fclose(f);
	
	printf("\n\nCau c_Doc tu file van ban, in ra man hinh va nhap them vao cuoi file:\n");
	f=fopen("C:\\Bai 1 van ban.txt", "a");
	fflush(stdin);
	printf("Nhap noi dung them vao cuoi van ban: ");
	gets(chuoi);
	fprintf(f,"%s", chuoi);
	fclose(f);
	return 0;
}
