#include<stdio.h>
#include<malloc.h>
#include<string.h>

void xoa(char a[], int pos){
	int i, n = strlen(a);
	for (i=pos; i<n; i++){
		a[i]=a[i+1];
	}
}

void chuanHoa(char a[]){
	int i, n=strlen(a);
	// xoa giua
	for (i=0; i< n; i++){
		if (a[i]==' ' && a[i+1]==' '){
			xoa(a, i);
			i--;
		}
	}
	//xoa dau
	if (a[0]==' ') xoa(a, 0);
	//xoa cuoi
	if (a[strlen(a)-1]==' ') xoa(a, strlen(a)-1);
}

void them1KT(char *a, int pos, char s){
	int i, n=strlen(a);
	for (i=n; i>pos; i--){
		a[i]=a[i-1];
	}
	a[pos]=s;
}

void themChuoi(char *a){
	char s[50];
	printf("Nhap chuoi can chen: ");
		if (fgets(s, 51, stdin) != NULL);
		fgets(s, 51, stdin);
		strtok(s, "\n");
	int chon, i, j, chon1, m = strlen(s), n = strlen(a) +m;
	realloc(a, n);
	printf("Chon kieu chen:\n1.Chen sau Chu\n2.Chen vao vi Tri\nBan chon: ");
		scanf("%d", &chon);
	if (chon == 1){
		char z[50];
		printf("Them sau chuoi: ");
			if (fgets(z, 51, stdin) != NULL);
			fgets(z, 51, stdin);
			strtok(z, "\n");
		int y=strlen(z);
		for (i=0; i<n-m; i++){
			if ((a[i]==z[0]) && (a[i+ y -1]==z[y -1])){
				for (j=y-1; j>=0; j--){
					them1KT(a, i+y, s[j]);
				}
				a[n]='\0';
				break;
			}
		}
	}	
	else if (chon == 2){
		printf("Nhap vi tri chen: ");	scanf("%d", &chon1);
		// dich tu vi tri chon1 sang m phan tu
		for (i=m-1; i>=0; i--){
			them1KT(a, chon1, s[i]);
		}
		a[n]='\0';
	}
}


void xoaChuoi(char *a){
	char xoa[50];
	if (fgets(xoa, 51 , stdin) != NULL);
		printf("Nhap chuoi can xoa: ");
		fgets(xoa, 51 , stdin);
		strtok(xoa, "\n");
	int i, j, lenx = strlen(xoa), lena = strlen(a);
	if (strstr(a, xoa)){
		// neu con tu trong chuoi thi xoa tiep
		while (strstr(a, xoa)){
			for(i= 0; i<lena; i++){
				// kiem tra dau va cuoi co giong nhau khong
				if ((a[i]==xoa[0]) && (a[i+ lenx -1]==xoa[lenx -1])){
					// lena - lenx +1 de dich ki tu \0 cuoi chuoi
					for (j = i; j<=lena - lenx +1; j++){
						//	+1 de bo qua khoang trang sau tu
						a[j]=a[j+ lenx +1]; 
					}
				}
			}
			lena = strlen(a); // giam so lan lap for i
		}
	}	
	else {
		printf("Khong tim thay \"%s\" trong chuoi ban dau!\n", xoa);
	}
	realloc(a, sizeof(char)*lena); // cap phat lai vung nho cho mang dong
}

int symmetry(char s[]){ // kiem tra doi xung
	int i, dem=0, a, len = strlen(s);
	a=(len&1) ? (len/2) : ((len-1)/2);
	for (i=0; i<a; i++) {
		if (s[i]==s[len-i-1]) dem++;
	}
	if (dem==a) return 1;
	return 0;
}

int main(){
	char *a, chuoiChen[50], viTriChenChu[10];
	int viTriChenKiTu, menuChon = 10;
	/* 	
		Cap phat 10 o nho co kich thuoc kieu Char
		Truy cap vung nho theo chi so (0 --> 9) 
	*/
	a = (char*)malloc(sizeof(char)*100);
	printf("Nhap chuoi: ");
		fgets(a, 101, stdin);
		strtok(a, "\n"); // xoa \n sau chuoi
		chuanHoa(a); //xoa khoang trang thua
		realloc(a, strlen(a)+1);
	while (menuChon != 3){
		printf("\nLua chon thao tac:\n1.Them Chuoi\n2.Xoa Chuoi\n3.Thoat\nBan chon: ");
		scanf("%d", &menuChon);
		switch (menuChon){
			case (1): {
				themChuoi(a);
				printf("Chuoi sau khi them: %s\n", a);
				break;
			}
			case (2): {
				xoaChuoi(a);
				printf("Chuoi sau khi xoa: %s\n", a);
				break;
			}
		}
	}
	free(a);
}
