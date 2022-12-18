#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int uc(int a, int b){
	a = (a<0) ? (-a) : a; // doi dau neu so am
	b = (b<0) ? (-b) : b;	// doi dau neu so am
	return ((b==0) ? a : uc(b, a%b));
}

int bc(int a, int b){
	a = (a<0) ? (-a) : a;	// doi dau neu so am
	b = (b<0) ? (-b) : b;	// doi dau neu so am
	return a/uc(a, b)*b;
}

int main(){
	int a, b;
	printf("Nhap a: "); scanf("%d", &a);
	printf("Nhap b: "); scanf("%d", &b);
	printf("\nuc: %d", uc(a, b));
	printf("\nbc: %d", bc(a, b));
	return 0;
}
