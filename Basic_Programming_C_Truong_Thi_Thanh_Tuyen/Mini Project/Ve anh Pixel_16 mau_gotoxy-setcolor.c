#include<stdio.h>
#include<malloc.h>
#include<Windows.h>
// thao tac ban phim
#define LEN 72
#define XUONG 80
#define TRAI 75
#define PHAI 77
#define ESC 27
#define ENTER 13
#define SPACE 32
typedef struct{
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

void meNu(int chieuDai, int chieuRong, int mauKhung){
	system("cls");
	printf("------------------MENU-------------------\n");
	printf("Huong dan su dung!\n");
	printf("   Ve net dai : Chu cai + [phim dieu khien]\n");
	printf("   Ve diem mau: Go chu cai + [space + phim dieu khien]");
	printf("Xoa trang thai: Go Esc\n");
	int i;
	for (i = 0; i <=15; i++){
		SetTeColor(i);
		printf("%-2d. %c : %c%c%c%c%c\n", i, (char)(97 +i), (char)178, (char)178, (char)178, (char)178, (char)178);
	}
	if (chieuDai != 0 && chieuRong != 0 && mauKhung != 100){
		int x, y;
		for (x =25; x <= chieuDai + 25; x++){
			for (y = 6; y <= chieuRong + 6; y++){
				gotoxy(x, y);
				SetTeColor(mauKhung);
				printf("%c", (char)178);
			}
		}
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
	} else return c;
}

void dieuKhienHuong(diem *a, int keyPhim){
	switch (keyPhim) {
		case (LEN):{
			a->y -=1;
			break;
		}
		case (XUONG):{
			a->y +=1;
			break;
		}
		case (TRAI):{
			a->x -=1;
			break;
		}
		case (PHAI):{
			a->x +=1;
			break;
		}
	}
}

int main(){
	int chieuDai=0, chieuRong=0, mauKhung = 100; 
	meNu(chieuDai, chieuRong, mauKhung);
	printf("Nhap chieu dai: "); scanf("%d", &chieuDai);
	printf("Nhap chieu rong: "); scanf("%d", &chieuRong);
	printf("Nhap mau khung: "); scanf("%d", &mauKhung);
	meNu(chieuDai, chieuRong, mauKhung);
	diem a; a.x = chieuDai + 20; a.y = chieuRong +3;
	diem b; b.x = 0; b.y = 0;
	int mauO = 100, mauOCu, inThang = 0, in1O = 0;
	
	while (1){
		if (kbhit()){
			int keyPhim = keyPhimNhapVao();
			// lay gia tri cu cua diem a
			b = a;
			dieuKhienHuong(&a, keyPhim);
			if (a.x < 25 || a.y < 6 || a.y > chieuRong + 6)	a = b;
			if (97<=keyPhim && keyPhim<=112) mauO = (keyPhim - 97) % 16;
			if (keyPhim == ESC) mauO = 100; 
			if (keyPhim == SPACE) in1O = 1;
		}
		gotoxy(a.x, a.y);
		if (mauO != 100){ // xu ly in 1 hang
			SetTeColor(mauO);
			printf("%c", (char)178);
		}
		if (in1O != 0){	// xu ly in 1 o
			gotoxy(b.x, b.y);
			if (mauO != 100) mauOCu = mauO;
			SetTeColor(mauOCu);
			printf("%c", (char)178);
			in1O = 0;
			mauO = 100;
		}
	
	}
	return 0;
}







