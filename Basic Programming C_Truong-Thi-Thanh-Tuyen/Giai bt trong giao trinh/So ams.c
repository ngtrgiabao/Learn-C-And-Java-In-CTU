#include<stdio.h>
#include<math.h>
int ams(int n){
	int temp=n, i=0;
	while (n!=0){
		i++;
		n/=10;
	}
	int sum=temp;
	while (temp!=0){
		n+=pow(temp%10,i);
		temp/=10;
	}
	return sum==n; 
}

int main(){
	int n; 
	printf("Nhap so can kiem tra: "); scanf("%d", &n);
	printf("%d", ams(n));
}
