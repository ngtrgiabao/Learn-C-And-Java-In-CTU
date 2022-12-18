#include<stdio.h>
#include<string.h>

void xoa(char a[], int pos){
	int i, n = strlen(a);
	for (i=pos; i<n; i++){
		a[i]=a[i+1];
	}
}

void chuanHoa(char a[]){
	int i, n=strlen(a);
	// xoa giua
	for (i=0; i< n; i++){
		if (a[i]==' ' && a[i+1]==' '){
			xoa(a, i);
			i--;
		}
	}
	//xoa dau
	if (a[0]==' ') xoa(a, 0);
	//xoa cuoi
	if (a[strlen(a)-1]==' ') xoa(a, strlen(a)-1);
}

int main(){
	char ten[50];
	printf("Nhap ho va ten: ");
	fgets(ten, 51, stdin);
	strtok(ten, "\n");
//	printf("Do dai chuoi truoc: %d\n", strlen(ten));
	chuanHoa(ten);
	printf("Ten sau khi chuan hoa: %s\n", ten);
//	printf("Do dai chuoi sau: %d", strlen(ten));
	return 0;
}
