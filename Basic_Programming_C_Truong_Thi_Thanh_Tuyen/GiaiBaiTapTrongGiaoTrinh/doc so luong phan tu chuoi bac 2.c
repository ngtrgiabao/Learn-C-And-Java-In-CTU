#include<stdio.h>
#include<string.h>


int main(){
	char s[100][100];
	s[0][100] = "jahsjhfjkfhf";
	s[1][100] = "shjhjksf";
	s[2][100] = "fjkjjfs";
	printf("so phan tu: %d", strlen(s));
	return 0;
}
