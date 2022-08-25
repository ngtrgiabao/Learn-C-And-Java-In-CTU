#include<stdio.h>

int main(){
	int a[10][10];
	int i, dong, cot;
	printf("Nhap dong: "); scanf("%d", &dong);
	printf("Nhap cot: "); scanf("%d", &cot);
	for (i=0;i<dong*cot;i++){
		printf("Phan tu a[%d][%d]: ", i/cot, i%cot);
		scanf("%d", &a[i/cot][i%cot]);
	}
	printf("\nMang sau khi nhap: \n");
	for (i=0;i<dong*cot;i++){
		if (i%cot==0) printf("\n");
		printf("%d\t", a[i/cot][i%cot]);
	}
	return 0;
}

