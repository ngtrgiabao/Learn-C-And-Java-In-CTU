#include<stdio.h>

void factorize(int n){
	int i = 2, count_x = 0;
	printf("%d = ", n);
	while (n != 1){
		if (n % i == 0){
			n /= i;
			count_x++;
			if (count_x == 1) printf("%d", i);
			else {
				printf(" x %d", i);
			}
		} else {
			i++;
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	factorize(n);
	return 0;
}
