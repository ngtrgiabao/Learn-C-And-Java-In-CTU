#include<stdio.h>
#include<string.h>
#include<malloc.h>

/* 	Thay doi chi so o Hang MAX va FLIP de giai cac bai toan khac
	Vi du: Sap day 8 ly, moi lan lat 4 ly
		   Sap day 10 ly, moi lan lat 5 ly
*/

#define MAX 8  // so ly can lat de den Goal
#define FLIP 4 // so ly Lat/lan

int checkGoal(char arr[]){ 
	// kiem tra chuoi truyen vao co the di den trang thai Goal hay khong
	// return 1: Co the; return 0: Khong the
	int i, j;
	for (i=0; i< MAX -FLIP +1; i++){
 		if (arr[i]=='0'){ 
 			// Neu arr[i] = '0' thi chuyen doi trang thai cua arr[i] va FLIP -1 o tiep theo
 			// '0' -> '1' hoac '1' -> '0'
			arr[i] = '1';
			for (j=1; j <=FLIP -1; j++){
				if (arr[i+j]=='0') arr[i+j] = '1';
					else arr[i+j] = '0';
			}
		} 
	}
	// sau khi xu ly chuoi ban dau
	for (i=0; i< MAX; i++){
		// neu trong chuoi con ki tu '0' thi khong the di den trang thai Goal
		if (arr[i]=='0') return 0; 
	}
	return 1;
}

int checkInvalid(char arr[]){ 
	// kiem tra tinh hop le cua chuoi truyen vao
	int i;
	if (strlen(arr)==MAX){ // do dai chuoi nhap vao phai bang MAX
		for (i = 0; i<MAX; i++){
			if (arr[i]=='0' || arr[i]=='1'){
				continue;
			} else return 0; // neu phat hien ki tu != '0' hoac != '1' -> Chuoi khong hop le!
		}
		return 1;
	} else{
		return 0;
	}
}
/*
	Gia su ban dau May Lat Ly co the o Ben Trai hoac Ben Phai,
	Neu tim thay vi tri arr[i] = '0' thi May se lat vi tri arr[i] va FLIP -1 vi tri ke tiep.
	- Chung ta se lat cac ly tu [Phai ->Trai] va tu [Trai -> Phai]
	- So sanh chi phi gom: 
			+ 1: Moi lan di chuyen qua khoang cach 1 ly
			+ 1: Moi lan Lat FLIP ly
		-> De tim ra giai phap Lat ly tot hon (chi phi lat ly nho nhat!)
*/

int solution1(char arr[]){ // lat tu trai sang phai
	int i, j;
	int index = 0, countFlip = 0;
	for (i=0; i< MAX -FLIP +1; i++){
		if (arr[i]=='0'){
			int k;
			printf("Lat ly o vi tri ");
			for(k =1; k <= FLIP; k++){
				printf("%d ", i+k); // In ra vi tri cac ly se duoc lat
			}
			printf(": ");
			
			arr[i] = '1';
			for (j=1; j<=FLIP -1; j++){
				if (arr[i+j]=='0') arr[i+j] = '1';
					else arr[i+j] = '0';
			}
			puts(arr);
			index = i; // So buoc may da di chuyen 
			countFlip +=1; // So lan lat ly
		} 
	}
	printf("  Khoang cach di chuyen: %d\n", index);
	printf("  So lan lat ly: %d\n", countFlip);
	return index + countFlip; // Tra ve tong chi phi giai phap
}

int solution2(char arr[]){ // lat tu phai sang trai
	int i, j;
	int index = 0, countFlip = 0;
	for (i=MAX-1; i>=FLIP-1; i--){
		if (arr[i]=='0'){
			int k;
			printf("Lat ly o vi tri ");
			for(k =FLIP; k >=1; k--){
				printf("%d ", i-k +2); // in ra cac vi tri se duoc Lat
			}
			printf(": ");
			
			arr[i] = '1';
			for (j=1; j< FLIP; j++){
				if (arr[i-j]=='0') arr[i-j] = '1';
					else arr[i-j] = '0';
			}
			puts(arr);
			index = MAX -i -1; // So buoc may da di chuyen
			countFlip +=1; // So lan lat ly
		}
	}
	printf("  Khoang cach di chuyen: %d\n", index);
	printf("  So lan lat ly: %d\n", countFlip);
	return index + countFlip; // tra ve tong chi phi giai phap
}

int main(){
	while (1){
		char *arr = (char*) malloc(sizeof(char)*(MAX+1));
		char *temp1 = (char*) malloc(sizeof(char)*(MAX+1));
		char *temp2 = (char*) malloc(sizeof(char)*(MAX+1));
		do {
			system("cls");
			printf("Quy uoc: vi tri cac ly bac dau tu 1 den 6\n\n");
			printf("Nhap trang thai ban dau: ");
			fgets(arr, MAX +1, stdin);
			strtok(arr, "\n");
			strcpy(temp1, arr);	
			strcpy(temp2, arr);
			if (!checkInvalid(arr)) {
				printf("\nTrang thai nhap khong hop le!\n\n");
			}
		} while (!checkInvalid(arr) || !strcmp(arr, "9999"));
		if (checkGoal(arr)){ 
			printf("\nGiai phap 1: Di tu trai qua phai \n");
			int cost1 = solution1(temp1);
			printf("Tong chi phi: %d\n\n", cost1);
			printf("Giai phap 2: Di tu phai qua trai \n");
			int cost2 = solution2(temp2);
			printf("Tong chi phi: %d\n\n", cost2);
			free(arr);
			free(temp1);
			free(temp2);
			int keyBreak = -1;
			printf("Ban co tiep tuc chuong trinh?\n");
			printf("Nhap so bat ki de tiep tuc, nhap 9999 de ket thuc chuong trinh: ");
			scanf("%d", &keyBreak);
			if (keyBreak == 9999) break;
		} else{
			printf("Trang thai khong the di den dich!\n\n");
			int keyBreak = -1;
			printf("Ban co tiep tuc chuong trinh?\n");
			printf("Nhap so bat ki de tiep tuc, nhap 9999 de ket thuc chuong trinh: ");
			scanf("%d", &keyBreak);
			if (keyBreak == 9999) break;
		}
	}
	printf("\nChuong trinh ket thuc!\n");
	return 0;
}

