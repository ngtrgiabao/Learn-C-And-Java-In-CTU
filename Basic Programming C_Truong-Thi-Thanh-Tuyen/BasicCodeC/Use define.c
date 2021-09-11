#include<stdio.h>

// +, -, *, /
#define sum(x, y) x+y
// ? :
#define max(x, y) (x>y) ? (x) : (y)
// multiple lines using '\'
#define greater(x, y) if (x>y)\
	printf("%d > %d\n", x, y);\
		else printf("%d > %d\n", y, x);

int main(){
	printf("Sum of 4 and 5 is: %d\n", sum(4, 5));
	printf("Max of 4 and 5 is: %d\n", max(4, 5));
	greater(10, 1000);
	// lay ngay thang tren may tinh
	printf("DATE is %s\n", __DATE__); 
	printf("TIME is %s\n", __TIME__);
	return 0;
}
