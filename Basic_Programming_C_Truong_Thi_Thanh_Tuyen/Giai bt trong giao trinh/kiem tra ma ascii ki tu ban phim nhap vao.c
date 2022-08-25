#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char c;
	while (1){
		c = getch();
		printf("%c.....%-2d\n", c, c);
	}
	return 0;
}
