#include<stdio.h>

void xuLyFile(FILE *file){
	int i, demTu=1, demDong=1;
	//demDong = 1 do ban dau o dòng 1 mà
	//demTu= 1 do ban dau co 1 tu mà
	char ss;
	while (!feof(file)){
		ss=fgetc(file);
		if (ss==(char)32 ||ss==(char)10) demTu+=1; //mã khoang trang = 32
		if (ss==(char)10) demDong+=1; // mã LF =newline mã ascii = 10
	};
	printf("So tu trong van ban: %d\n", demTu);
	printf("So dong trong van ban: %d\n", demDong);
	fclose(file);
}

int main(){
	FILE *f;
	f=fopen("C:\\Bai 1 van ban.txt","r");
	if (f!=NULL){
		xuLyFile(f);
	} else printf("Loi khi mo file!");
	return 0;
}
