#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int main()
{
    int *arr;
    int n, i;
    arr=(int *)malloc(2);
    do
    {
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);
    } while (n < 1);
 
    // Nh?p m?ng
    for ( i = 0; i < n; i++)
    {
        printf("Nhap a[%d] = ", i);
        scanf("%d", (arr + i));
    }
 
    // Xu?t m?ng
    for ( i = 0; i < n; i++)
    {
        printf("\nGia tri a[%d] = %d", i, *(arr + i));
    }
    return 0;
}
