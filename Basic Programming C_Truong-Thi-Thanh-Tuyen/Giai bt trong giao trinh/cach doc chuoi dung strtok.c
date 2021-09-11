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
	f = fopen("C:\\docchuoibangstrtok.txt", "r");
	if (f == NULL){
		printf("Xay ra loi!");
		return;
	}
	int i=0, len = 0;
	char src[100];
	fgets(src, 101, f);
	if (src[strlen(src) -1] == '\n') src[strlen(src) -1] = '\0';
	fclose(f);
	sv a;
	char *token, tam[100];
	token = strtok(src, "|");
	while (token != NULL){
		strcpy(tam, token);
		chuanHoa(tam);
		printf("Dinh dang xuat cua tam: %s\n", tam);
	 	len = strlen(tam);
	 	printf("do dai chuoi tam: %d\n", len);
	 	switch (len){
	 		case (3):{
	 			strcpy(a.ma, tam);
				break;
			}
			case (2):{
				a.tuoi = atoi(tam);
				break;
			}	
			default :{
				strcpy(a.hoTen, tam);
				break;
			}
		}
		token = strtok(NULL, "|");
	}
	printf("Du lieu sau khi doc: \n%s %s %d", a.ma, a.hoTen, a.tuoi);
	return 0;
}
