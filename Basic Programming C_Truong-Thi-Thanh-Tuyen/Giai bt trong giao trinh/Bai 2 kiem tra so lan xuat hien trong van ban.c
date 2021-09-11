#include<stdio.h>
#include<string.h>

const char A[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void countarray(FILE *file){
	int B[strlen(A)];
	int i;
	char ss;
	for (i=0; i<strlen(A); i++){
		B[i]=0;
		while (!feof(file)){
			fscanf(file,"%c", &ss);
			if (A[i]==ss) B[i]+=1;
		};
		if (B[i]>0) printf("Ki tu %c: %-4d lan\n", A[i], B[i]);
		rewind(file);
	}
	fclose(file);
}

int main(){
	FILE *f;
	f=fopen("C:\\Bai 1 van ban.txt","r");
	if (f!=NULL){
		countarray(f);
	} else printf("Loi khi mo file!");
	return 0;
}
