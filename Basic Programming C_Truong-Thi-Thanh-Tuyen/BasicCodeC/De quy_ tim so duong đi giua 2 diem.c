#include<stdio.h>

int timDuong(int x1, int y1, int x2, int y2){
	if (x1>x2 || y1>y2) return 0;
	if (x1==x2 && y1==y2) return 1;
		else return (timDuong(x1+1, y1, x2, y2) + timDuong(x1, y1+1, x2, y2));
}

int main(void){
	int x1, y1, x2, y2;
	printf("Nhap toa do diem A:\n");
	do	{
		printf("xA = "); 
		scanf("%d", &x1);
	} while (x1<0);
	do 	{
		printf("yA = "); 
		scanf("%d", &y1);
	} while (y1<0);
	printf("Nhap toa do diem B:\n");
	do 	{
		printf("xB = "); 
		scanf("%d", &x2);
	} while (x2<x1);
	do 	{
		printf("yB = "); 
		scanf("%d", &y2);
	} while (y2<y1);
	printf("\nTong so cac duong di tu A(%d,%d) den B(%d,%d) la: %d", 
		   x1, y1, x2, y2, timDuong(x1, y1, x2, y2));
	return 0;
}
