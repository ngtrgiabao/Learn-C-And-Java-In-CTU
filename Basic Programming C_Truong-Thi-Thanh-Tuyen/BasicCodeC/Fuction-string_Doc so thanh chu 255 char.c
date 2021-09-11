#include<stdio.h>
#include<string.h>

void docSo(int n){
	switch (n){
		case (1):{
			printf(" Mot");
			break;
		}
		case (2):{
			printf(" Hai");
			break;
		}
		case (3):{
			printf(" Ba");
			break;
		}
		case (4):{
			printf(" Bon");
			break;
		}
		case (5):{
			printf(" Nam");
			break;
		}
		case (6):{
			printf(" Sau");
			break;
		}
		case (7):{
			printf(" Bay");
			break;
		}
		case (8):{
			printf(" Tam");
			break;
		}
		case (9):{
			printf(" Chin");
			break;
		}
	}
}

void docChapBaSo(int n, int flag){
	if (0<n && n<10) docSo(n);
	int chuc;
	if (9<n && n<100){
		chuc=n/10;
		n%=10;
		if (flag>0){
			printf(" Khong Tram");
		}
		if (chuc==1){
			printf(" Muoi"); docSo(n);
		}
		 	else {
		 		docSo(chuc); printf(" Muoi"); docSo(n);
		 	}	
	}
	int tram;
	if (99<n && n<1000){
		tram=n/100;
		chuc=(n- 100*tram)/10;
		n%=10;
		if (chuc==0 && n==0){
			docSo(tram); printf(" Tram");
		} 	else if (chuc==0 && n!=0) {
				docSo(tram); printf(" Tram Le"); docSo(n);
			}
		if (chuc!=0 && n==0){
			docSo(tram); printf(" Tram"); 
			if (chuc==1) {
				printf(" Muoi");
			}
				else {
					docSo(chuc); printf(" Muoi"); docSo(n);
				}
		} else 	if (chuc!=0 && n!=0){
					docSo(tram); printf(" Tram");
					if (chuc==1){
						printf(" Muoi"); docSo(n);
					}	else {
							docSo(chuc); printf(" Muoi"); docSo(n);
						}
				}
	} 
}

void docTenChapBa(int n){
	switch (n){
		case (0):{
			break;
		}
		case (1):{
			printf(" Nghin");
			break;
		}
		case (2):{
			printf(" Trieu");
			break;
		}
		case (3):{
			printf(" Ti\n");
			break;
		}
		case (4):{
			printf(" Nghin Ti");
			break;
		}
		case (5):{
			printf(" Trieu Ti");
			break;
		}
		case (6):{
			printf(" Ti Ti\n");
			break;
		}
		case (7):{
			printf(" Nghin Ti Ti");
			break;
		}
		case (8):{
			printf(" Trieu Ti Ti");
			break;
		}
		case (9):{
			printf(" Ti Ti Ti\n");
			break;
		}
		
		case (10):{
			printf(" Nghin Ti Ti Ti");
			break;
		}
		case (11):{
			printf(" Trieu Ti Ti Ti");
			break;
		}
		case (12):{
			printf(" Ti Ti Ti Ti\n");
			break;
		}
		case (13):{
			printf(" Nghin Ti Ti Ti Ti");
			break;
		}
		case (14):{
			printf(" Trieu Ti Ti Ti Ti");
			break;
		}
		case (15):{
			printf(" Ti Ti Ti Ti Ti");
			break;
		}
		//neu Chap Ba lon hon nua thi nhap them case o day
	}
}

int taoMangChapBa(int a[50], char s[150]){
	int i, n, dodaimang=-1;
	n=strlen(s);
	if (n%3==0){
		for (i=0; i<n; i+=3){
			dodaimang+=1;
			a[dodaimang]=((int)s[i] -48)*100 + ((int)s[i+1] -48)*10 + ((int)s[i+2] - 48);
		}
	}
	if (n%3==1){
		dodaimang+=1;
		a[dodaimang]=((int)s[0] -48);
		for (i=1; i<n; i+=3){
			dodaimang+=1;
			a[dodaimang]=((int)s[i] -48)*100 + ((int)s[i+1] -48)*10 + ((int)s[i+2] - 48);
		}
	}
	if (n%3==2){
		dodaimang+=1;
		a[dodaimang]=((int)s[0] -48)*10 + ((int)s[1] -48);
		for (i=2; i<n; i+=3){
			dodaimang+=1;
			a[dodaimang]=((int)s[i] -48)*100 + ((int)s[i+1] -48)*10 + ((int)s[i+2] - 48);
		}
	}
	return (dodaimang+1);
}

void docDaySo(int a[50], int dodai){
	int i;
	for (i=0; i<dodai; i++){
		docChapBaSo(a[i], dodai -1);
		if (a[i]==0) continue;
		docTenChapBa(dodai -i -1);
	}
}

int main(){
	int i, doDaiMang, a[50];
	char s[150];
	while (1){
		fflush(stdin);
		printf("Nhap so tien can doc: "); gets(s);
		doDaiMang = taoMangChapBa(a, s);
		if (a[0]==0) printf("Doc la: Khong Dong\n");
			else {
				printf("Doc la: ");
				docDaySo(a, doDaiMang); printf(" Dong\n");
			}
	}
	return 0;
}
