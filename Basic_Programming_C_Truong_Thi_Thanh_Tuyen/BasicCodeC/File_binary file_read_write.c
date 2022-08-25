#include<stdio.h>

int main(){
	int sopt, count;
	FILE *f;
	f = fopen("D:\\nhiphan.dat", "wb");
	printf("Nhap so phan tu: "); scanf("%d", &sopt);
	if (f== NULL){
		printf("Khong the moi file!.");
	}
	else {
		for (count = 1; count<=sopt; count++){
			fwrite(&count, sizeof(int), 1, f);
		}
		fclose(f);
	}
	f= fopen("D:\\nhiphan.dat", "rb");
	// ham fread doc tung phan tu roi luu vao bien dem
	// in tung gia tri cua dem ra
	// doc thanh cong ham fread tra ve 1, that bai tra ve false 0.
	while (fread(&count, sizeof(int), 1, f) == 1){ 
		printf("%-4d", count);
		if (count %10==0) printf("\n");
	}
	fclose(f);
}
