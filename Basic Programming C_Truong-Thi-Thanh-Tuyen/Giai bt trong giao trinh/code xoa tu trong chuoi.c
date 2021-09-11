#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define max 100

char XoaTu(char s[], char s1[]){
	int len = strlen(s);
	int len2 = strlen(s1);
	int i;
	for(i= 0; i<len; i++){
		if ((s[i]==s1[0]) && (s[i+ len2 -1]==s1[len2 -1])){
			int j;
			for (j = 0; j< len; j++){
				s[j]=s[j+len2];
			}
			s[j+len2] ='\0';
			break;
		}
	}
	printf("chuoi sau khi cat: %s", s);
}

int main(){
	char s[100], s1[100];
	printf("nhap chuoi s: ");
	fflush(stdin);
	gets(s);
	printf("Nhap chuoii s1: ");
	gets(s1);
	XoaTu(s, s1);
}
