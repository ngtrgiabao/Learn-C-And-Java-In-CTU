#include<stdio.h>
#include<string.h>

/*
	Cac che do mo file text:
	rt: chi doc. Neu chua co file tra ve NULL
	wt: chi ghi. Neu da co file thi se xoa noi dung cu va ghi lai. Neu chua co thi tao moi file de ghi
	at: ghi vao cuoi file. Neu da co file thi ghi vao cuoi file. Neu chua co thi tao moi va ghi 
	-> Thuong thi nen luu duoi la .txt
*/

// don gian chi la moi mang khong the thay doi duoc -> dung de so sanh
const char arrayForCompare[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; 

void countFrequencyCharater(FILE *file){
	int countArray[strlen(arrayForCompare)];
	int i;
	char ss;
	printf("Tan xua xuat hien cac chu cai trong file:\n");
	for (i=0; i<strlen(arrayForCompare); i++){
		countArray[i]=0;
		while (!feof(file)){
			fscanf(file,"%c", &ss);
			if (arrayForCompare[i]==ss) countArray[i]+=1;
		};
		if (countArray[i]>0) printf("\nKi tu %c: %-4d lan", arrayForCompare[i], countArray[i]);
		rewind(file); // dua con tro tro ve dau file
	}
	// de toi uu ham nen dong file truoc khi return
	//fclose(file);
}

void countWordAndLine(FILE *file){
	int i, demTu=1, demDong=1;
	//demDong = 1 do ban dau o dòng 1
	//demTu= 1 do ban dau co 1 tu
	char ss;
	rewind(file);
	while (!feof(file)){
		ss=fgetc(file);
		if (ss==(char)32 ||ss==(char)10) demTu+=1; //mã khoang trang = 32
		if (ss==(char)10) demDong+=1; // mã LF =newline mã ascii = 10
	}
	printf("\nSo tu trong van ban: %d", demTu);
	printf("\nSo dong trong van ban: %d", demDong);
	// de toi uu ham nen dong file truoc khi return
	//fclose(file);
}

int main(){
	FILE *f;
	char chuoi[80];
	printf("Nhap chuoi de ghi vao file van ban:\n");
	f=fopen("D:\\Bai 1 van ban.txt", "w"); // tao file de ghi
	if (f==NULL){
		printf("Xay ra loi khi mo file");
	} else {
		printf("Nhap noi dung: ");
		fgets(chuoi, 81, stdin);
		strtok(chuoi, "\n");
		fprintf(f,"%s", chuoi);
	}
	fclose(f); // mo thi phai co dong file
	
	printf("\nDoc tu file van ban va in ra man hinh:\n");
	f=fopen("D:\\Bai 1 van ban.txt", "r");
	while (!feof(f)){
		fgets(chuoi, 81, f);
		printf("%s", chuoi);
	}
	countFrequencyCharater(f);
	countWordAndLine(f);
	fclose(f);
	
	printf("\n\nDoc tu file van ban, in ra man hinh va nhap them vao cuoi file:\n");
	f=fopen("D:\\Bai 1 van ban.txt", "a");
	printf("Nhap noi dung them vao cuoi van ban: ");
	fgets(chuoi, 81, stdin);
	strtok(chuoi, "\n");
	fprintf(f,"%s", chuoi);
	fclose(f);
	/*
	// lay noi dung tu file ra
	f=fopen("D:\\Bai 1 van ban.txt", "r");
	while (!feof(f)){
		fgets(chuoi, 81, f);
		printf("%s", chuoi);
	}
	fclose(f);
	*/
	return 0;
}
