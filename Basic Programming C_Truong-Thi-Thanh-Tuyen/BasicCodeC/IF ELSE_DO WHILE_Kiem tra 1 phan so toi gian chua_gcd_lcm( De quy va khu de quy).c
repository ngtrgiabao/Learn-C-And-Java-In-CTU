#include<stdio.h>

int gcdKhuDeQuy(int a, int b) { // khu de quy dung giai thuat Euclid
	int r;
	while (b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int gcd(int a, int b){ // viet theo de quy
	a = (a<0) ? (-a) : a; // doi dau neu so am
	b = (b<0) ? (-b) : b;	// doi dau neu so am
	return ((b==0) ? a : gcd(b, a%b));
}

int lcm(int a, int b){
	a = (a<0) ? (-a) : a;	// doi dau neu so am
	b = (b<0) ? (-b) : b;	// doi dau neu so am
	return a/gcd(a, b)*b;
}

int main(){
	int a, b, ucln, bcnn;
	printf("Nhap a = "); scanf("%d", &a);
	do {
		printf("     b = "); scanf("%d", &b);
	} while (b==0);
	if (a<0 && b<0) {
		a = -a;
		b = -b; 
	}
	ucln = gcd(a, b);
	printf("UCLN cua (%d, %d) la: %d\n", a, b, ucln);
	bcnn = lcm(a, b);
	printf("BCNN cua (%d, %d) la: %d\n\n", a, b, bcnn);
	if (ucln==1) {
		printf("Phan so %d/%d da toi gian!", a, b);
	} 	
	else if (b == ucln) {
		printf("Phan so %d/%d chua toi gian!\n", a, b);
		printf("Phan so toi gian la: %d/%d = %d\n", a/ucln, b/ucln, a/ucln);
	}
	else if (b != ucln){
		printf("Phan so %d/%d chua toi gian!\n", a, b);
		printf("Phan so toi gian la: %d/%d\n", a/ucln, b/ucln);
	}
	return 0;
}
