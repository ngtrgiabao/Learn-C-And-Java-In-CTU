#include<stdio.h>

int main(){
	FILE *f;
	int i=10;
	char ten[30];
	printf("Nhap ten: ", ten);
	fgets(ten, 31, stdin);
	f=fopen("C:\\test1234.txt","w");
	if (f==NULL) printf("Loi khi mo file!");
	fprintf(f, "%d\n", i);
	fprintf(f, "%s", ten);
	fclose(f);
	f=fopen("C:\\test1234.txt","r");
	fscanf(f, "%d ", &i);
	fgets(ten, 31, f);
	int j;
	for (j=30-1; j>=0; j--){ 
		if (ten[j] == (char)10) {
			ten[j]='\0';
			break;
		}
	}
	printf("Ho Ten: %s  Diem: %d", ten, i);
	fclose(f);
	return 0;
}
