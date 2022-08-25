#include<stdio.h>
#include<conio.h>

int main(){
	int i, y, n;
	printf("Nhap so tang: ");
	scanf("%d", &n);
	for (i=1;i<=n;i++){
		for (y=1;y<=2*n-1;y++) //in tan CAY THONG NOEL
			if (y==n-i+1 || y==n+i-1) printf("*");	else printf(" ");
		printf("\n");
		sleep(1);
		};
	for (i=n+1;i<n+ 2*n/3;i++){ //in than CAY THONG NOEL
		for (y=1;y<=(2*n-1);y++) if (y==n-3*n/5 || y==n+3*n/5) printf("*"); else printf(" ");
		printf("\n");
		sleep(1);
		};

	getch();
	return 0;
	}
