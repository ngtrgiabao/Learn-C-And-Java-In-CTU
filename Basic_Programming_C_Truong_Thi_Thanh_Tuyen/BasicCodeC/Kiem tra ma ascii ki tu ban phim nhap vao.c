#include<stdio.h>
#include<stdlib.h>
/*
Ph�m Enter : 13
Ph�m ESC: 27
Ph�m Tab: 9
Mui t�n l�n: -32 -> 72
Mui t�n xuong: -32 -> 80
Mui t�n sang tr�i: -32 -> 75
Mui t�n sang phai: -32 -> 77
Ph�m c�ch: 32
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
