#include<stdio.h>
#include<math.h>

int checkPrime(int n){
	if (n<2) return 0;
	else if (n==2 || n==3 || n==5 || n==7 || n==9) return 1;
	else if (n%2==0 || n%3==0 || n%5==0 || n%7==0 ) return 0;
	else if (n>10) {
		int i;
		for (i=3; i*i<n; i+=2){
			if (n%i==0) return 0;
		}
		return 1;
	}
}

int main(){
	int i, j, n, prev=2;
	printf("Nhap n: "); scanf("%d", &n);
	for (i=1; i<=n; i++){
		printf("%d. ", i);
		for (j=1; j<=i; j++){
			while (!checkPrime(prev)){
				prev++;
			}
			printf("%-4d ", prev);
			prev++;
		}
		printf("\n");
	}
	return 0;
}
