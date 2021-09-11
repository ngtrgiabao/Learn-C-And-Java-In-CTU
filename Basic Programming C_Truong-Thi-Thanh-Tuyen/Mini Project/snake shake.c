#include<stdio.h>
#include<malloc.h>
#include<Windows.h>
// Thong so dieu chinh
#define WIDTH 50 // truc Ox
#define HEIGHT 25 // truc Oy
#define MAXLENGTH 1000 // gioi han do dai than ran 
// Thao tac ban phim
#define LEN 72
#define XUONG 80
#define TRAI 75
#define PHAI 77
#define THOAT 27 // Esc
#define ENTER 13
#define SPACE 32

typedef struct{ // khai bao cau truc toa do tung diem tren than ran
	int x, y;	
} coordinate;

int keyInput(){
	if (kbhit()){
		char c = getch();
		if (c==-32) c = getch();
		if (c==72|| c==80|| c==75|| c==77|| c==27|| c==32) return (int) c;
	}
	return 0; // phim nhap vao khong xac dinh	
}
int main(){
	int a;
	while(1){
		int a = keyInput();
		printf("Key: %d\n", a);
	}
	return 0;
}


