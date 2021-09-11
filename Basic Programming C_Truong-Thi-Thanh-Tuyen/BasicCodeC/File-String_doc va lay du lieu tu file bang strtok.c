#include<stdio.h>
#include<string.h>

typedef struct sv{
	char ma[10];
	char hoTen[50];
	int tuoi;	
}sv;

void xoa(char tam[],int pos){
	int i;
	for (i = pos; i<strlen(tam); i++){
		tam[i]= tam[i+1];
	}
	tam[strlen(tam)] = '\0';
}

void chuanHoa(char tam[]){
 	int i;
 	for (i= 0; i <strlen(tam); i++){ 
 		if (tam[i]== ' ' && tam[i-1] == ' '){
 			xoa(tam, i);
			i--;	
		}
	}
	if (tam[0] == ' ') xoa(tam, 0);
	if (tam[strlen(tam)-1] == ' ') xoa(tam, strlen(tam)-1);
}

int main(){
	FILE *f;
	f = fopen("C:\\file du lieu test.txt", "r");
	if (f == NULL){
		printf("Xay ra loi!");
		return;
	}
	int i, in=0,  len = 0;
	char src[100][100];
	while (!feof(f)){
		fgets(src[in], 101, f);
		if (src[in][strlen(src[in]) -1] == '\n') src[in][strlen(src[in]) -1] = '\0'; // xoa \n cuoi
		in++;
	}
	
	fclose(f);
	sv a[10];
	char *token, tam[100];
	for (i = 0 ; i< in; i++){
		printf("Du lieu dong %d\n", i +1);
		token = strtok(src[i], "|");
		while (token != NULL){
			strcpy(tam, token);
			chuanHoa(tam);
			printf("\tDu lieu: %s\n", tam);
	 		len = strlen(tam);
		 	switch (len){
		 		case (3):{
	 				strcpy(a[i].ma, tam);
					break;
				}
				case (2):{
					a[i].tuoi = atoi(tam);
					break;
				}	
				default :{
					strcpy(a[i].hoTen, tam);
					break;
				}
			}
			token = strtok(NULL, "|");
		}
		printf("\tDu lieu sau khi doc: \n\t%s %s %d\n", a[i].ma, a[i].hoTen, a[i].tuoi);
	}
	return 0;
}

/*
Tom luoc lai la:
strtok dung de tach chuoi khi co cac ki tu dau mut 
co the tach theo nhieu loai: , . | ( tuy vao luc ghi file)
1. tao mang 2 chieu, luu tung dong vao mang. xu ly gia tri '\n' cuoi chuoi
2. xu ly tung dong
3. neu dinh dang so thi chuyen va bang cac ham atoi, atof( sai so 0.0000003)
4. tuy vao yeu cau de cho ma dung switch case luu tru gia tri du lieu thich hop vao cau truc
*/

// code cua nguoi ta
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sv{
	char ma[10];
	char hoTen[50];
	int tuoi;	
}sv;
 
int main(){
    sv a;
    int index = 0, i;
    char a[100], b[100][100], *p;
    printf ("Nhap vao chuoi: ");
    fgets(a, 101, stdin);
    p = strtok(a, ",."); 
    while(p != NULL){
        strcpy(, p);
        printf ("\n%s ", b[index]);
        index++;
         p = strtok(NULL, ",.");
    }
    return 0;
}
*/

