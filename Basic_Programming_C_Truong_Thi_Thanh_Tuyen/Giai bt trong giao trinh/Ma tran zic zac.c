#include<stdio.h>
#include<conio.h>
//De bai:
//tao ma tran zic zac
//vidu dong 

int main()
{
	int n, m, i, j, tam, u=0;
	printf("Chieu doc n	= ");	scanf("%d", &n);
	printf("Chieu ngang m = ");	scanf("%d", &m);
	printf("Ma tran ket qua la:\n");
	for (i=1;i<=n;i++)
	{
		if (i%2==1)
			for (j=1;j<=m;j++){
				tam=i+j+u-1;
				printf("%d\t", tam);
			} 
		if (i%2==0) 
			for (j=m;j>=1;j--){
				tam=i+j+u-1;
				printf("%d\t", tam);
			} 
		u=i*(n-1);
		printf("\n");
	}
	getch();
	return 0;
}
