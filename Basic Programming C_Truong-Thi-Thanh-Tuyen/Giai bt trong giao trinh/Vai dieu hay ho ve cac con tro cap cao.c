#include<stdio.h>

int min(int a,int b)
{
    if (a<b) return a;
    return b;
}

void swap(int *a, int *b){
// Day la dang tham so truyen la con tro. nen ta phai truyen dia chi vao: swap(&a, &b)	
/*	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
	//Hoac */
	*a += *b -= *a = *b - *a; 
}

int main(){
	int (*pMin)(int,int); //con tro ham
    pMin=min;
    printf("min cua 4 va 5 la %d\n", pMin(4,5));
	void *c;
	int a = 5;
	c = &a;
	printf("%d\n", *(int*)c);
	// cu phap ep kieu con tro
	int *pa = &a;
	int **ppa = &pa;
	int ***pppa = &ppa;
	printf("Gia tri cua a: %d\n", a);
	printf("Gia tri *pa tro den: %d\n", *pa);
	printf("Gia tri **ppa tro den: %d\n", **ppa);
	printf("Gia tri ***pppa tro den: %d\n\n", ***pppa);
	// => ***pppa = **ppa = *pa = a: cung chi den du lieu bien.
	printf("Dia chi cua &a: %d\n", &a);
	printf("Dia chi cua &pa: %d\n", &pa);
	printf("Dia chi cua &ppa: %d\n", &ppa);
	printf("Dia chi cua &pppa: %d\n\n", &pppa);
	// => con tro cap nao cung chi can them & de lay dia chi.
	printf("Gia tri pa mang: %d\n", pa);
	printf("Gia tri ppa mang: %d\n", ppa);
	printf("Gia tri pppa mang: %d\n\n", pppa);
	// => con tro cap nao chi can bo het dau * la lay duoc gia tri no mang
	printf("Gia tri **pppa: %d\n", **pppa);
	printf("Gia tri *pppa mang: %d\n", *pppa);
	printf("Gia tri pppa mang: %d\n", pppa);
	printf("Gia tri *ppa mang: %d\n\n", *ppa);
	// => dau * neu thieu se chi ra dia chi con tro cap tuong ung **pppa chi mang dia chi pa
	// so dau * chi bac tu con tro do chi xuong 
	int b = 10;
	swap(&a, &b);
	printf("%d %d", a, b);
	return 0;
}

