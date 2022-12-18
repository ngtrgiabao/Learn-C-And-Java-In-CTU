#include<stdio.h>
#include<string.h>

void docSo(int n){
	switch (n){
		case (1):{
			printf(" mot");
			break;
		}
		case (2):{
			printf(" hai");
			break;
		}
		case (3):{
			printf(" ba");
			break;
		}
		case (4):{
			printf(" bon");
			break;
		}
		case (5):{
			printf(" nam");
			break;
		}
		case (6):{
			printf(" sau");
			break;
		}
		case (7):{
			printf(" bay");
			break;
		}
		case (8):{
			printf(" tam");
			break;
		}
		case (9):{
			printf(" chin");
			break;
		}
	}
}
void docChapBaSo(int n, int soluong, int ss){
	if (0<n && n<10) docSo(n);
	int chuc;
	if (9<n && n<100){
		chuc=n/10;
		n%=10;
		if (soluong!=1 || soluong!=ss)
			printf(" khong tram");
		if (chuc==1){
			printf(" muoi"); docSo(n);
		}
		 	else {
		 		docSo(chuc); printf(" muoi"); docSo(n);
		 	}	
	}
	int tram;
	if (99<n && n<1000){
		tram=n/100;
		chuc=(n- 100*tram)/10;
		n%=10;
		if (chuc==0 && n==0){
			docSo(tram); printf(" tram");
		} 	else if (chuc==0 && n!=0) {
				docSo(tram); printf(" tram le"); docSo(n);
			}
		if (chuc!=0 && n==0){
			docSo(tram); printf(" tram"); 
			if (chuc==1) {
				printf(" muoi");
			}
				else {
					docSo(chuc); printf(" muoi"); docSo(n);
				}
		} else 	if (chuc!=0 && n!=0){
					docSo(tram); printf(" tram");
					if (chuc==1){
						printf(" muoi"); docSo(n);
					}	else {
							docSo(chuc); printf(" muoi"); docSo(n);
						}
				}
	} 
}

int demSoChuSo(unsigned long long int n, int a[50]){
 	int demSo=0, demMang=0, b[50], i;
 	unsigned long long int m=n;
	while (n!=0){
		n/=10;
		demSo+=1;
	}
	while (m!=0){
		b[demMang]=m%1000;
		m/=1000;
		demMang+=1;
	}
	for (i=0;i<demMang;i++){
		a[i]=b[demMang-1-i];
	}
	return demSo;
}

void docTenChapBa(int n){
	switch (n){
		case (0):{
			break;
		}
		case (1):{
			printf(" nghin");
			break;
		}
		case (2):{
			printf(" trieu");
			break;
		}
		case (3):{
			printf(" ti");
			break;
		}
		case (4):{
			printf(" nghin ti\n");
			break;
		}
		case (5):{
			printf(" trieu ti");
			break;
		}
		case (6):{
			printf(" ti ti");
			break;
		}
		case (7):{
			printf(" nghin ti ti");
			break;
		}
		//neu Chap Ba lon hon nua thi nhap them case o day. Ma phai tuy kieu du lieu
	}
}

void docCaDaySo(int a[50], int soPhanTu, int tenChapBa){
	int i;
	for (i=0; i<soPhanTu; i++){
		docChapBaSo(a[i], soPhanTu -i -1, soPhanTu-1); 
		if (a[i]==0) continue;
		docTenChapBa(tenChapBa -i -1); 
	}
}

int main(){
	unsigned long long int n;
	int a[50], demChapBa;
	printf("Nhap so tien: "); scanf("%lld",&n);
	demChapBa=demSoChuSo(n, a);
	if (demChapBa%3==0) demChapBa/=3;
		else demChapBa=demChapBa/3 +1;
	printf("Doc la: ");
	docCaDaySo(a, demChapBa, demChapBa); printf(" dong");
	return 0;
}
