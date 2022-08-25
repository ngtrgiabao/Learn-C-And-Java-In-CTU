#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int main()
{
	int a=5;
    int *pa=&a;
    printf("Gia tri cua a la: %d\n", a);
      printf("Gia tri cua a do pa tro den la: %d\n", *pa);
     printf("Dia chi cua a la: %d\n", &a);
       printf("Dia chi cua pa la: %d\n", &pa);
         printf("Gia tri cua pa la: %d\n", pa);
    return 0;
}
