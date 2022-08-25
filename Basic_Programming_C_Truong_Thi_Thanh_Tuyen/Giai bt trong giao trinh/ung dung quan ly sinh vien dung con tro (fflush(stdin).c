#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct SinhVien{
	char mSSV[5];
	char hoTen[50];
	int ngaySinh;
	char queQuan[50];
	float diemTBTL;
	int diemRL;
} sv;

void nhapSV(sv **a, int n){
	int i;
	for (i= 0; i< n; i++){
		printf("Nhap tt sinh vien thu %d\n", i+1);
		printf("MSSV: "); fflush(stdin); gets(a[i]->mSSV);
		printf("Ho va Ten: "); fflush(stdin); gets(a[i]->hoTen);
		printf("Ngay sinh: "); scanf("%d", &a[i]->ngaySinh);
		printf("Que quan: "); fflush(stdin); gets(a[i]->queQuan);
		printf("Diem TBTL: "); scanf("%f", &a[i]->diemTBTL);
		printf("Diem ren luyen: "); scanf("%d", &a[i]->diemRL);
	}
}

void xuatSV(sv **a, int n){
	int i;
	printf("_________________________________________________________________________\n");
	printf("|%-6s|%-30s|%-3s|%-20s|%-4s|%-3s|\n", "MSSV", "Ho va Ten", "Dat", "Que Quan", "DTBC", "DTB");
	for (i =0; i<n; i++){
		printf("|%-6s|%-30s|%-3d|%-20s|%-4.2f|%-3d|\n", a[i]->mSSV, a[i]->hoTen, a[i]->ngaySinh, a[i]->queQuan, a[i]->diemTBTL, a[i]->diemRL);
	}
	printf("-------------------------------------------------------------------------\n");
}

void xuat1SV(sv **a, int i){
	printf("\n_________________________________________________________________________\n");
	printf("|%-6s|%-30s|%-3s|%-20s|%-4s|%-3s|\n", "MSSV", "Ho va Ten", "Dat", "Que Quan", "DTBC", "DTB");
	printf("|%-6s|%-30s|%-3d|%-20s|%-4.2f|%-3d|\n", a[i]->mSSV, a[i]->hoTen, a[i]->ngaySinh, a[i]->queQuan, a[i]->diemTBTL, a[i]->diemRL);
	printf("-------------------------------------------------------------------------\n");
}
void sapXep(sv **a, int n){
    sv tmp;
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(a[i]->diemTBTL > a[j]->diemTBTL){
                tmp = *a[i];
                *a[i] = *a[j];
                *a[j] = tmp;
            }
        }
    }
}
 
void timSV(sv **a, int n, char timMSSV[30]){
    int i;
    for(i=0; i<n; i++){
       if(strcmp(a[i]->mSSV, timMSSV)==0){
           xuat1SV(a, i);
       }
    }
}

int main(){
	sv **a;
	int n, chonMeNu, flag=0, chonN, count, indexMax, i;
	float max;
	char timMSSV[10];
	while (1){
		printf("CHUONG TRINH QUAN LY SINH VIEN\n");
		printf("1. Nhap Thong Tin SV.\n");
		printf("2. In Thong Tin SV.\n");
		printf("3. In Thong Tin SV Thu N.\n");
		printf("4. Tim Thong Tin Theo MSSV.\n");
		printf("5. SV Co Diem TBTL Max.\n");
		printf("6. SV Co Diem RL Max.\n");
		printf("7. Xep Hang SV Theo Diem TBTL.\n");
		printf("8. Thoat Khoi Chuong Trinh.\n");
		printf("Ban Chon: "); scanf("%d", &chonMeNu);
		switch (chonMeNu){
			case (1):{
				do {
					printf("Nhap So Luong SV: n = "); scanf("%d", &n);
				} while (n<=0);
				a  = (sv**)malloc(sizeof(sv*) *n);
				for (i =0; i<n; i++){
					a[i] = (sv*)malloc(sizeof(sv));
				}
				flag = 1;
				nhapSV(a, n);
				break;
			}
			case (2):{
				if (flag == 0) {
					printf("Nhap Thong Tin SV truoc!\n\nGo Back de quay lai MeNu.");
					getch();
				}	else {
						xuatSV(a, n);
					}
				break;
			}
			case (3):{
				if (flag == 0) {
					printf("Nhap Thong Tin SV truoc!\n\nGo Back de quay lai MeNu.");
					getch();
				}	else {
					do {
						printf("Nhap So Thu Tu SV: n = "); scanf("%d", &chonN);
					} while (chonN<=0 || n<chonN);
					printf("Thong Tin Sinh Vien Thu %d.\n", chonN);
					xuat1SV(a, chonN -1);
				}
				
				break;
			}
			case (4):{
				if (flag == 0) {
					printf("Nhap Thong Tin SV truoc!\n\nGo Back de quay lai MeNu.");
					getch();
				}	else {
						printf("Nhap MSSV can tim: "); 
						fflush(stdin); gets(timMSSV);
						timSV(a, n, timMSSV);
					}
				break;
			}
			case (5):{
				if (flag == 0) {
					printf("Nhap Thong Tin SV truoc!\n\nGo Back de quay lai MeNu.");
					getch();
				}	else {
						printf("Sinh Vien Co Diem TB Tich Luy Cao Nhat.\n");
						max = a[0]->diemTBTL;
						indexMax = 0;
						for (count = 1; count <n; count++){
							if (max<a[count]->diemTBTL) {
								indexMax = count;
								max = a[count]->diemTBTL;
							}
						}
						xuat1SV(a, indexMax);
					}
			
				break;
			}
			case (6):{
				if (flag == 0) {
					printf("Nhap Thong Tin SV truoc!\n\nGo Back de quay lai MeNu.");
					getch();
				}	else {
						printf("Sinh Vien Co Diem Ren Luyen Cao Nhat.\n");
						max = a[0]->diemRL;
						indexMax = 0;
						for (count = 1; count <n; count++){
							if (max<a[count]->diemRL) {
								indexMax = count;
								max = a[count]->diemRL;
							}
						}
						xuat1SV(a, indexMax);
					}
				
				break;
			}
			case (7):{
				if (flag == 0) {
					printf("Nhap Thong Tin SV truoc!\n\nGo Back de quay lai MeNu.");
					getch();
				}	else {
						printf("Danh Sach Xep Theo Chieu Tang Dan:\n");
						sapXep(a, n);
						xuatSV(a, n);
					}
				break;
			}
			case (8):{
				for (i = 0; i< n; i++){
					free(a[i]);
				}
				free(a);
				return;
			}
		}
	}
	nhapSV(a, n);
	xuatSV(a, n);
	return 0;
		
}
