#include<stdio.h>
#include<conio.h>
#include<math.h>

int diChuyen(int n, char a, char b, char c){
	if (n==1){
		printf("---> Chuyen khoi tu cot %c sang cot %c|\n", a, c);
		return 0;
	} else
	diChuyen(n-1, a, c, b);
	diChuyen(1, a, b, c);
	diChuyen(n-1, b, a, c);
}

int main(){
	int n;
	char a='A', b='B', c='C';
	printf("Nhap so tang thap: n = "); scanf("%d", &n);
	printf("\nCach giai quyet:\n____________________________________\n");
	diChuyen(n, a, b, c);
	printf("____________________________________\n		 Tong cong: %.f (Buoc)", pow(2,n)-1);
	getch();
	return 0;
}
