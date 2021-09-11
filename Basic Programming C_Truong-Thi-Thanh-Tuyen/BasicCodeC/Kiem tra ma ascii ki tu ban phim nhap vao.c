#include<stdio.h>
#include<stdlib.h>
/*
Phím Enter : 13
Phím ESC: 27
Phím Tab: 9
Mui tên lên: -32 -> 72
Mui tên xuong: -32 -> 80
Mui tên sang trái: -32 -> 75
Mui tên sang phai: -32 -> 77
Phím cách: 32
*/

int main(){
	char c;
	printf("Thich gi nhap do!\n");
	while (1){
		c = getch();
		printf("%5c -- %-2d\n", c, c);
	}
	return 0;
}
