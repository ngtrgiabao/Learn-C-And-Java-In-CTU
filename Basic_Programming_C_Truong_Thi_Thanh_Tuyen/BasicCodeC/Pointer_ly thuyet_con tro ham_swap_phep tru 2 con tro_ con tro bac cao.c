#include<stdio.h>

int min(int a,int b){
    if (a<b) return a;
    return b;
}

void swap(int *a, int *b){
	*a = *a + *b - (*b = *a);
}

int main(){
	// ham swap
	int b=10, a=5;
	printf("Ban dau: a = %d; b = %d\n", a, b);
	swap(&a, &b);
	printf("Swap: a = %d; b = %d\n", a, b);
	//con tro ham
	int (*pMin)(int,int); 
    pMin = min; // min o day la ham viet rieng => ham cung mang dia chi va duoc pMin tro den
    printf("min giua 4 va 5 la %d\n", pMin(4,5));
	// cu phap ep kieu con tro va con tro bac 1
	void *c;
	int *paa;
	c = &a;
	paa = &a;
	printf("Dia tri con tro c sau khi ep kieu: %d\n", *(int*)c);
	printf("Dia chi cua bien a: %d\n", &a);
	printf("Gia tri pa mang   : %d\n", paa); // => pa mang dia chi cua bien a
	printf("Dia chi cua pa: %d\n", &paa);
	printf("gia tri cua bien ma pa tro den: %d\n", *paa); 
	// phep tru hai con tro
	int arr[10];
	arr[0] = 111;
	arr[1] = 222;
	int *pArr0 = &arr[0], *pArr1 = &arr[1];
	printf("Size of Integer: %d\n", sizeof(int));
	printf("Dia chi arr[0]: %d\n", &arr[0]);
	printf("Dia chi arr[1]: %d\n", &arr[1]);
	printf("pArr1 - pArr0 = %d\n", pArr1 - pArr0); // phep tru hai con tro dua ra khoang cach giua chung
	// vai dieu hay ho ve con tro bac cao
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
	return 0;
}

