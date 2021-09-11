#include<stdio.h>
#include<malloc.h>
#include<Windows.h>
//Thong so dieu chinh
#define CHIEUDAIKHUNG 50
#define CHIEURONGKHUNG 25
#define DODAIMAX 1000 
// thao tac ban phim
#define LEN 72
#define XUONG 80
#define TRAI 75
#define PHAI 77
#define THOAT 27
#define ENTER 13
#define SPACE 32

typedef struct Diem{
	int x, y;
} diem;

void gotoxy(int x, int y){
    static HANDLE  h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x,y};
    SetConsoleCursorPosition(h,c);
}

void SetTeColor( WORD color)
{ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void veKhung(int soMoiDaAn, char hoTen[50]){
	// in dong ky luc
	int i, j;
	FILE *file;
	file = fopen("C:\\ky_luc_game.txt", "r");
	int maxScore = 0;
	char hoTenFile[30];
	fscanf(file, "%d ", &maxScore);
	fgets(hoTenFile, 31, file);
	fclose(file);
	//ve khung trong
	for (i = 10; i<=CHIEUDAIKHUNG+10; i++){
		for (j = 2; j<=4; j++){
			if (i==10 || i==CHIEUDAIKHUNG+10 || j==2) {
				gotoxy(i, j);
				SetTeColor(14);
				printf("%c", (char)15); 
			}
		}
		printf("\n");
	}
	// in ky luc truoc day
	gotoxy((CHIEUDAIKHUNG+10)/2 -10, 3);
	SetTeColor(12);
	strtok(hoTenFile, "\n"); 
	printf("KY LUC: %s DIEM: %-4d", hoTenFile, maxScore);
	// in khung gioi han choi
	for (i = 10; i<=CHIEUDAIKHUNG+10; i++){ //ve khung trong----------------------------------------
		for (j = 5; j<=CHIEURONGKHUNG+5; j++){
			if (i==10 || i==CHIEUDAIKHUNG+10 || j==5 || j==CHIEURONGKHUNG+5) {
				gotoxy(i, j);
				SetTeColor(4);
				printf("%c", (char)15); 
			}
		}
		printf("\n");
	}
	for (i = 9; i<=CHIEUDAIKHUNG +11; i++){ //ve khung ngoai----------------------------------------
		for (j = 4; j<=CHIEURONGKHUNG +6 +4; j++){
			if (i==9 || i==CHIEUDAIKHUNG +11 || j==4 || j==CHIEURONGKHUNG +6 || j==CHIEURONGKHUNG +6 +4) {
				gotoxy(i, j);
				SetTeColor(10);
				printf("%c", (char)178); 
			}
		}
		printf("\n");
	}
	// in thong tin nguoi dang choi
	SetTeColor(14);
	gotoxy(12, CHIEURONGKHUNG + 8); printf("DIEM: %d", 10*soMoiDaAn); 
	gotoxy(24, CHIEURONGKHUNG + 8); printf("Ten: ");
	gotoxy(30, CHIEURONGKHUNG + 8);
	SetTeColor(12);	 printf("%s", hoTen);
	SetTeColor(10);
	gotoxy(22, CHIEURONGKHUNG + 7); printf("%c", (char)178);
	gotoxy(22, CHIEURONGKHUNG + 8); printf("%c", (char)178);
	gotoxy(22, CHIEURONGKHUNG + 9); printf("%c", (char)178);
	gotoxy(52, CHIEURONGKHUNG + 7); printf("%c", (char)178);
	gotoxy(52, CHIEURONGKHUNG + 8); printf("%c", (char)178);
	gotoxy(52, CHIEURONGKHUNG + 9); printf("%c", (char)178);
}
void huongDan(){
	SetTeColor(12);
	printf("\n                ---+++HUONG DAN+++---\n");
	SetTeColor(14);
	printf(" _____________________________________________________________\n");
	printf("|  - Rat don gian, ban co gang an that nhieu Moi la duoc.     |\n");
	printf("|  - Moi lan an moi Ran se dai ra mot chut.                   |\n");
	printf("|  - Toc do nhanh dan nen hay co gang song sot!	              |\n");
	printf("|  --> Tro choi khong co win, chi co xep hang diem cao nhat   |\n");
	printf("|  --> Lose: Neu cham tuong hoac can trung than.              |\n\n");
	SetTeColor(2);
	printf("Go Esc de quay lai Menu."); 
	while (1){
		if (kbhit()){
			int keyPhim = keyPhimNhapVao();
			if (keyPhim == THOAT) break;
		}
	}
}

void khoiTaoRan(diem **thanRan){
	int i, soDot = 5;
	for (i=0; i<soDot; i++){
		thanRan[i]->x = CHIEUDAIKHUNG/2 - i;
		thanRan[i]->y =CHIEURONGKHUNG/2;
	}
}

int keyPhimNhapVao(){
	char c = getch();
	if (c==-32) {
		c = getch();
		if (c==72) return c; //di len
		if (c==80) return c; //di xuong
		if (c==75) return c; //sang trai
		if (c==77) return c; //sang phai
		if (c==32) return c; //tam dung Enter
		if (c==27) return c; //thoat
	}
}

int soLuongDotRan(diem **thanRan){ //dem so luong dot ran hien co
	int soDot=0;//
	while (thanRan[soDot]->x != 0 || thanRan[soDot]->y != 0){
		soDot++;
	}
	return soDot;
}

void hienThiRan(diem **thanRan, int color){
	int i, soDot = soLuongDotRan(thanRan);
	for (i=soDot -1; i>=0; i--){
		gotoxy(thanRan[i]->x, thanRan[i]->y);
		if (color == 0){
			SetTeColor(thanRan[i]->x / 14 +i);
			printf("%c", (char)2); 
		} else if (color != 0) {
				SetTeColor(color);
				printf("%c", (char)2); 
			}	
	}
}
void dieuKhienHuong(diem **thanRan, int keyPhim){
	int i, soDot = soLuongDotRan(thanRan);
	for (i=soDot -1; i>0; i--){
		thanRan[i]->x = thanRan[i-1]->x;
		thanRan[i]->y = thanRan[i-1]->y;
	}
	switch (keyPhim) {
		case (LEN):{
			thanRan[0]->y -=1;
			break;
		}
		case (XUONG):{
			thanRan[0]->y +=1;
			break;
		}
		case (TRAI):{
			thanRan[0]->x -=1;
			break;
		}
		case (PHAI):{
			thanRan[0]->x +=1;
			break;
		}
	}
}

diem khoiTaoMoi(int color){
	diem viTriMoi;
	viTriMoi.x = 11 + rand() % (CHIEUDAIKHUNG -1);
	viTriMoi.y = 6 + rand() % (CHIEURONGKHUNG -1);
	gotoxy(viTriMoi.x, viTriMoi.y); SetTeColor(color);	printf("%c", (char)15);
	return viTriMoi;
}
void resetGame(diem **thanRan, int *keyPhim, int *shakeColor , int *soMoiDaAn, int *countWhile, int *flag1, int *flag2, int *countMoi1){
	int i, j;
	for (i = 0; i < DODAIMAX; i++){
		thanRan[i]->x = 0; //khoi tao lai gia tri ban dau
		thanRan[i]->y = 0;	//khoi tao lai gia tri ban dau
	}
	khoiTaoRan(thanRan); // khoi tao lai than ran
	*keyPhim = PHAI;
	*shakeColor = 0;
	*soMoiDaAn = 0;
	*countWhile = 0; 
	*flag1 = 0; 
	*countMoi1 = 0;
	*flag2 = 0;
}

void xuLyMoiDacBiet(diem moi2, int moiColor){
	gotoxy(moi2.x, moi2.y);
	SetTeColor(moiColor);
	printf("%c", (char)15);
}


void kyLuc(char hoTen[30], int diem){
	FILE *file;
	file = fopen("C:\\ky_luc_game.txt", "r");
	int maxScore = 0, i;
	char hoTenFile[30];
	fscanf(file, "%d ", &maxScore);
	fgets(hoTenFile, 31, file);
	if (diem>maxScore){
		fclose(file);
		file = fopen("C:\\ky_luc_game.txt", "w");
		fprintf(file, "%d\n", diem);
		fprintf(file, "%s", hoTen);
		fclose(file);
		system("cls");
		veKhung(diem/10, hoTen);
		SetTeColor(14);
		gotoxy((CHIEUDAIKHUNG+ 10)/2 -20, (CHIEURONGKHUNG+5)/2 +1);
		printf("XIN CHUC MUNG, BAN VUA DAT KY LUC MOI VOI SO DIEM: %d!", diem);
		gotoxy((CHIEUDAIKHUNG+ 10)/2 -20, (CHIEURONGKHUNG+5)/2 +3);
		SetTeColor(2);
		printf("Go Esc de quay lai Menu.");
	}
	else {
		fclose(file);
		system("cls");
		veKhung(diem/10, hoTen);
		SetTeColor(14);
		gotoxy((CHIEUDAIKHUNG+ 10)/2 -20, (CHIEURONGKHUNG+5)/2 +1);
		printf("DIEM CUA BAN LA: %d, LAN SAU HAY CO GANG HON!", diem);
		gotoxy((CHIEUDAIKHUNG+ 10)/2 -20, (CHIEURONGKHUNG+5)/2 +3);
		SetTeColor(2);
		printf("Go Esc de quay lai Menu.");
	}
	while (1){
		if (kbhit()){
			int keyPhim = keyPhimNhapVao();
			if (keyPhim == THOAT) break;
		}
	}
}

void loiKhen(int soMoiDaAn){
	if (soMoiDaAn == 0){
		gotoxy(54, CHIEURONGKHUNG +8);
		SetTeColor(8);
		printf("Co gang song sot nhe ban hien! :))");
	}
		else if (soMoiDaAn >= 11 && soMoiDaAn <= 20){
			gotoxy(54, CHIEURONGKHUNG +8);
			printf("                                       ");
			SetTeColor(6);
			gotoxy(54, CHIEURONGKHUNG +8);
			printf("Qua moc 100 diem roi a? Cung kha day!");
		}
			else if (soMoiDaAn >=21 && soMoiDaAn <= 50){
				gotoxy(54, CHIEURONGKHUNG +8);
				printf("                                       ");
				gotoxy(54, CHIEURONGKHUNG +8);
				SetTeColor(3);
				printf("Hon 200 diem roi? Gioi day!");
			}
			else if (soMoiDaAn >= 51 && soMoiDaAn <= 100){
				gotoxy(54, CHIEURONGKHUNG +8);
				printf("                                       ");
				gotoxy(54, CHIEURONGKHUNG +8);
				SetTeColor(10);
				printf("Ghe nha. Hon 500 diem roi!");
			}
				else if (soMoiDaAn >= 101 && soMoiDaAn <= 200){
					gotoxy(54, CHIEURONGKHUNG +8);
					printf("                                       ");
					gotoxy(54, CHIEURONGKHUNG +8);
					SetTeColor(9);
					printf("Woaa hon 1000 diem roi, that tuyet!");
				}
					else if (soMoiDaAn >= 201 && soMoiDaAn <= 500){
						gotoxy(54, CHIEURONGKHUNG +8);
						printf("                                       ");
						gotoxy(54, CHIEURONGKHUNG +8);
						SetTeColor(11);
						printf("Ban that dep trai day :3");
					}
						else if (soMoiDaAn >= 501 && soMoiDaAn <= 950){
							gotoxy(54, CHIEURONGKHUNG +8);
							printf("                                       ");
							gotoxy(54, CHIEURONGKHUNG +8);
							SetTeColor(14);
							printf("Hiem ai song den tan gio! Dinh that 0.o");
						}
							else if (soMoiDaAn >= 951){
								gotoxy(54, CHIEURONGKHUNG +8);
								printf("                                       ");
								gotoxy(54, CHIEURONGKHUNG +8);
								SetTeColor(13);
								printf("Chuc mung ban da pha dao game!");
							}
}

int main(){
	diem **thanRan;
	int i, flag1 = 0, countMoi1 = 0; //flag1 = 0: chua co moi, flag1 = 1: da co moi
	int flag2 = 0; // flag2 la moi dac biet tang 5 dot
	thanRan = (diem**)malloc(sizeof(diem*) *DODAIMAX); // Cap phat vung nho cho Toan Than Con Ran
	// cap phat bo nho cho con tro
 	for (i = 0; i < DODAIMAX; i++){
 		thanRan[i]=(diem*)malloc(sizeof(diem)); // Cap phat vung nho cho tung phan tu Dot Ran
		thanRan[i]->x = 0; //khoi tao gia tri ban dau
		thanRan[i]->y = 0;	//khoi tao gia tri ban dau
	}
	// khoi tao vi tri ban dau cho Con Ran
	khoiTaoRan(thanRan);
	int soMoiDaAn = 0;
	hienThiRan(thanRan, 0);
	int keyPhim, soDot = 0, chon = 0, countWhile = 0, tocDo=0;
	int shakeColorTime = 0, shakeColor = 0, moiColor = 0, lose = 0;
	char hoTen[30];
	diem menu, moi1, moi2;
	menu.x = 0; menu.y = 3;
	gotoxy(menu.x, menu.y); printf("-->");
	// tao file luu ky luc
	FILE *file;
	file = fopen("C:\\ky_luc_game.txt", "r"); 
	if (file == NULL) {
		file = fopen("C:\\ky_luc_game.txt", "w");
		fprintf(file, "%d\n", 10);
		fprintf(file, "%s", "Nguyen Anh Nam");
		fclose(file);
	}
	// Tro choi chi la 1 vong lap cac cau lenh huu han
	while (chon != 4){
		system("cls");
		SetTeColor(13);
		printf("       %c...SNAKE...%c\n\n", (char)174, (char)175);
		SetTeColor(2);
		printf("________Moi Ban Chon______\n");
		SetTeColor(12);
		printf("==> ");
		SetTeColor(14);
		printf("|.....CHOI NGAY......|\n");
		printf("    |.....HUONG DAN......|\n");
		printf("    |.....KY LUC.........|\n");
		printf("    |.....THOAT..........|\n\n");
		SetTeColor(9);
		printf("Lua chon bang cac Phim Mui Ten, go Enter de chon!");
		// Xu ly menu chon
		getch();
		while (1){
			if (kbhit()) {
				keyPhim = keyPhimNhapVao();
				switch (keyPhim){
					case (XUONG): {
						gotoxy(menu.x, menu.y); printf("   ");
						menu.y +=1;
						if (menu.y == 7) menu.y = 3; 
						gotoxy(menu.x, menu.y); SetTeColor(12); printf("==>");
						break;
					}
					case (LEN): {
						gotoxy(menu.x, menu.y); printf("   ");
						menu.y -=1;
						if (menu.y == 2) menu.y = 6; 
						gotoxy(menu.x, menu.y); SetTeColor(12); printf("==>");
						break;
					}
					case (ENTER): {
						if (menu.y == 3) {
							chon = 1;
						}	else {
								chon = menu.y - 2;
							} 
						break;
					}
				}
			} 
			if (keyPhim == ENTER){
				break;
			} 
		}
		// ve khung-
		if (chon == 1){
			system("cls");
			printf("Nhap Ho Ten: ");
			fgets(hoTen, 31, stdin);
			system("cls");
			resetGame(thanRan, &keyPhim, &shakeColor, &soMoiDaAn, &countWhile, &flag1, &flag2, &countMoi1);
			veKhung(soMoiDaAn, hoTen);
		}	
		// xu ly cac van de trong menu
		switch (chon){
			case (1):{
				while (1){
					soDot = soLuongDotRan(thanRan);
					// Xoa dot cuoi
					gotoxy(thanRan[soDot -1]->x, thanRan[soDot -1]->y); printf(" ");
					//xu ly bat su kien ban phim
					if (kbhit()){
						int keyPhimCu = keyPhim;
						keyPhim = keyPhimNhapVao();
						if (keyPhimCu == XUONG && keyPhim == LEN)	keyPhim  = keyPhimCu;
						if (keyPhimCu == LEN && keyPhim == XUONG)	keyPhim  = keyPhimCu;
						if (keyPhimCu == TRAI && keyPhim == PHAI)	keyPhim  = keyPhimCu;
						if (keyPhimCu == PHAI && keyPhim == TRAI)	keyPhim  = keyPhimCu;
						if (keyPhim == THOAT)	break;
					}
					// dich gia tri phan tu trong mang va thay doi gia tri Dau Ran
					dieuKhienHuong(thanRan, keyPhim);
					// in lai Than Ran 
					hienThiRan(thanRan, shakeColor);
					// Xu ly Cham Thanh va Can Trung Than
					if (thanRan[0]->x == 10 || thanRan[0]->x == CHIEUDAIKHUNG +10)	break;
					if (thanRan[0]->y == 5 || thanRan[0]->y == CHIEURONGKHUNG +5)	break;
				//	for (i = 0; i < soDot; i++){
				//		if ((thanRan[0]->x == thanRan[i]->x) && (thanRan[0]->y == thanRan[i]->y))	break;
				//	}
					// khoi tao moi
					if (flag1 == 0){	 // neu khong co moi thi khoi tao moi
						moiColor = 1 +rand()%15;
						shakeColorTime = 2*tocDo;
						moi1 = khoiTaoMoi(moiColor);
						flag1 = 1;
						countMoi1++;
					}
					if (flag2 == 0 && countWhile >= 200 && countMoi1 == 5){	 // neu khong co moi thi khoi tao moi
						moiColor = 1 +rand()%15;
						moi2 = khoiTaoMoi(moiColor);
						flag2 = 1;
					}
					if (countMoi1 == 5) countMoi1 = 0;
					// xu ly an moi
					//  + Ran An Moi Thuong
					if (thanRan[0]->x == moi1.x && thanRan[0]->y == moi1.y){
						flag1 = 0;
						shakeColor = moiColor;
						soMoiDaAn++;
						gotoxy(12 +6, CHIEURONGKHUNG + 8); printf("%d", 10*soMoiDaAn);
						thanRan[soDot]->x = thanRan[soDot -1]->x; // tang them 1 Dot Ran
						thanRan[soDot]->y = thanRan[soDot -1]->y;  // tang them 1 Dot Ran
					} 
					// + Ran An Moi Dac Biet
					if (thanRan[0]->x == moi2.x && thanRan[0]->y == moi2.y){
						flag2 = 0;
						shakeColor = 0;
						soMoiDaAn +=5;
						gotoxy(12 +6, CHIEURONGKHUNG + 8); printf("%d\a", 10*soMoiDaAn);
						for (i = 1; i <=5; i++){ // Tang them 5 dot ran
							thanRan[soDot +i -1]->x = thanRan[soDot -1]->x; 
							thanRan[soDot +i -1]->y = thanRan[soDot -1]->y; 
						}
					}
					if (soMoiDaAn == 0 || soMoiDaAn >= 11 || soMoiDaAn >= 21 || soMoiDaAn >= 51||
					soMoiDaAn >= 101 || soMoiDaAn >= 201 || soMoiDaAn >= 501 || soMoiDaAn >= 950) {
						loiKhen(soMoiDaAn);
					} 
					// dem nguoc thoi gian tro ve mau Thap Cam
					shakeColorTime--; 
					if (shakeColorTime == 0) shakeColor = 0;
					// xu ly hieu ung moi dac biet
					if (flag2 == 1){
						moiColor = 1 +rand()%15;
						xuLyMoiDacBiet(moi2, moiColor);
					}
					// xu ly toc do ran (min -> max -> min -> ...)
					countWhile++;
					tocDo = countWhile / 20;
					if (countWhile >= 280) countWhile = 250;
					Sleep(170 - 10*tocDo);
				}
				// xu ly thua
				kyLuc(hoTen, 10*soMoiDaAn);
				break;
			}
			case (2):{
				system("cls");
				huongDan();
				chon = 0;
				break;
			}
			case (3):{
				system("cls");
				int i, j;
				FILE *file;
				file = fopen("C:\\ky_luc_game.txt", "r");
				int maxScore = 0;
				char hoTenFile[30];
				fscanf(file, "%d ", &maxScore);
				fgets(hoTenFile, 31, file);
				fclose(file);
				SetTeColor(12);
				gotoxy(3, 3);
				printf("KY LUC: %s", hoTenFile);
				gotoxy(3, 4);
				printf("  DIEM: %d", maxScore);
				//ve khung trong
				for (i = 1; i <7; i++){
					for (j = 1; j<51; j++){
						if (i==1 || i==6 || j==1 || j==50) {
							gotoxy(j, i);
							SetTeColor(14);
							printf("%c", (char)15); 
						}
					}
					printf("\n");
				}
				SetTeColor(2);
				printf("\nGo Esc de quay lai Menu."); 
				while (1){
					if (kbhit()){
						int keyPhim = keyPhimNhapVao();
						if (keyPhim == THOAT) break;
					}
				}
				break;
			}		
		}
	}
	//giai phong vung nho
	for (i = 0; i < DODAIMAX; i++){
 		free(thanRan[i]);	
	}
	free(thanRan);
	return 0;
}

