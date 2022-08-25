#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 10
int main(){
	char mangdoc[max][max], mangghi[max];
	int biendem;
	for (biendem = 0; biendem<max; biendem++){
		printf("phan tu thu %d: ", biendem+1);
		fgets(mangghi[biendem], 11, stdin);
	}
	FILE *f;
	f = fopen("C:\\filemangnhiphan.dat", "wb");
	
	//in du lieu tu mang
	fwrite(mangghi, sizeof(mangghi), 1, f);
	fclose(f);
	f = fopen("C:\\filemangnhiphan.dat", "rb");
	fread(mangdoc, sizeof(mangdoc), 1, f);
	for (biendem = 0; biendem <max; biendem++){
		printf("%s", mangdoc[biendem]);
		
	}
	fclose(f);
	return 0;
}
