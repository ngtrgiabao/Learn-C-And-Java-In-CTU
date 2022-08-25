#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
	int i,a,y;
	printf("Nhap so tang cua cay thong Noel: ");
	scanf("%d", &i);
	for (a=1;a<=i;a++){ //in tan CAY THONG NOEL
		for (y=1;y<=(2*i-1);y++) if (y>=i-a+1 && y<=i+a-1) printf("*"); else printf(" ");
		printf("\n");}
	for (a=i+1;a<i+ 2*i/3;a++){ //in than CAY THONG NOEL
		for (y=1;y<=(2*i-1);y++) if (y>i-3*i/5 && y<i+3*i/5) printf("*"); else printf(" ");
		printf("\n");}	
	getch();
	return 0;
}
