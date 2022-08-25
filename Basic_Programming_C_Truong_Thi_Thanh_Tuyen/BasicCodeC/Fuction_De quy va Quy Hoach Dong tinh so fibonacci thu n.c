#include<stdio.h>
#include<conio.h>

#define MAX 200

unsigned long long temp[MAX];

void inIt(){
	int i;
	for (i=0; i<MAX; i++){
		temp[i] = -1;
	}
}
unsigned long long fibonacciQHD(int n){
	if (temp[n] = -1){
		if (n<=2) temp[n] = 1;
		else {
			temp[n] = fibonacciQHD(n-1) + fibonacciQHD(n-2);
		} 
	} 
	return temp[n];
}
int fibonacci(int n){ // code de quy
	if (n==1 || n==2) return 1;
	else if (n>2) return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
	int i, n;
	printf("Nhap so chu so n = "); scanf("%d", &n);
	inIt();
	fibonacciQHD(n);
	printf("So fibonacci thu %d la: %lld\n", n, temp[n]);
	printf("Day fibonacci tu dau den so thu %d gom: ", n);
	for (i=1; i<=n; i++){
		printf("%lld ", temp[i]);
	}	
	return 0;
}
