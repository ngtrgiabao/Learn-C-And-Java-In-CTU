#include<stdio.h>
#include<conio.h>

int main(){
	int a[5], *pa=NULL, i, *pb=NULL;
	a[0]=1;
	a[1]=2;
	a[2]=3;
	a[3]=4;
	a[4]=5;
	a[5]=6;
	printf("Khai bai a[5], *pa, *pb thuoc kieu int\n");
	for (i=0;i<=4;i++)
	{
		printf("a[%d]: %d \n", i, a[i]);
	}
	pa=&a[2];
	pb=&a[3];
	printf("\nGan pa=&a[2]");
	printf("\ngia tri (tro den) pa: %d", *pa);
	printf("\ngia tri (tro den) pa+1 = a[3]: %d", *(pa+1));
	printf("\ngia tri (tro den) pa+2 = a[4]: %d", *(pa+2));
	printf("\ngia tri (tro den) pa-1 = a[1]: %d", *(pa-1));
	printf("\ngia tri (tro den) pa-2 = a[0]: %d", *(pa-2));
	printf("\nGan pb=&a[3]");
	printf("\ngia tri pa mang: %d", pa);
	printf("\ngia tri pb mang: %d", pb);
	printf("\nKhoang cach giua pa va pb la: %d", pb - pa);
	printf("\ndia chi pa: %d", &pa);
	printf("\nDia chi pb: %d", &pb);
	printf("\nKhoang cach giua &pa va &pb la: %d", &pb - &pa);
	return 0;
}
