#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ranDomSo(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}

void taoMapNgoai(int a[50][50], int n, int m){
	int i, j;
	//khoi tao gia tri ban dau cua o trong (=100)
    for (i=0;i<n+1;i++){
		for (j=0;j<m+1;j++){
			a[i][j]= 100;
		}
	}
	//khoi tao gia tri Dong bien (0 --> ...)
	for (i =0; i<n+1;i++){
		a[i][0]=i;
	}
	//khoi tao gia tri Cot bien ( 0 --> ...)
	for (i =0; i<m+1;i++){
		a[0][i]=i;
	}
}


void taoMapRanDom(int a[50][50], int n, int m, int soBoom){
	int i, j, k, row, column, demMin=0;
	char in1='x', in2='.';
	
	//khoi tao gia tri ban dau cua o trong (=111)
    for (i=0;i<n+1;i++){
		for (j=0;j<m+1;j++){
			a[i][j]= 111;
		}
	}
	//khoi tao gia tri Dong bien (0 --> ...)
	for (i =0; i<n+1;i++){
		a[i][0]=i;
	}
	//khoi tao gia tri Cot bien ( 0 --> ...)
	for (i =0; i<m+1;i++){
		a[0][i]=i;
	}
 	// random tim vi tri dat boom va gan gia tri tai vi tri boom (=1111)
	for (k=1;k<=soBoom;k++){
		srand((int)time(0)+k);
		row = ranDomSo(1,n);
 		column = ranDomSo(1,m);
		for (i=1;i<n+1;i++){
			for (j=1;j<m+1;j++){
				if (i==row && j==column){
					a[i][j]= 1111 ;
				} 
			}
		}
	}
	//dem so min xung quang tung o va gan gia tri tuong ung (1..8)
	for (i=1;i<n+1;i++){
		for (j=1;j<m+1;j++){
			if (a[i][j] == 1111) continue;
			if (a[i][j] == 111){
				demMin=0;
				if (a[i-1][j-1]==1111) demMin+=1;
				if (a[i-1][j]==1111) demMin+=1;
				if (a[i-1][j+1]==1111) demMin+=1;
				if (a[i][j-1]==1111) demMin+=1;
				if (a[i][j+1]==1111) demMin+=1;
				if (a[i+1][j-1]==1111) demMin+=1;
				if (a[i+1][j]==1111) demMin+=1;
				if (a[i+1][j+1]==1111) demMin+=1;
			}	
			if (demMin != 0) a[i][j]=demMin;
		}
	}
}

void moO(int a[50][50], int b[50][50], int n, int m, int r, int c){
	if (a[r][c]==1111) return;
	if (0>r || 0>c || r>n || c>m) return;
	if (0 < a[r][c] && a[r][c] <9) {
		b[r][c]=a[r][c];
		return;
	}
	if (a[r][c] == 111) {
		if (b[r][c] != 111) {
			b[r][c]=111;
			moO(a, b, n, m, r-1, c-1);
			moO(a, b, n, m, r-1, c);
			moO(a, b, n, m, r-1, c+1);
			moO(a, b, n, m, r, c-1);
			moO(a, b, n, m, r, c+1);
			moO(a, b, n, m, r+1, c-1);
			moO(a, b, n, m, r+1, c);
			moO(a, b, n, m, r+1, c+1);
		}
		
	}
}

void timePlay(int timeT, int timeS){
	int h, m, s;
	s=timeS-timeT;
	h=s/3600;
	m= (s - 3600*h)/60;
	s= s - 3600*h - 60*m;
	printf("  Thoi gian choi: ");
		if (h<10) printf("0%d:", h); else printf("%d:", h);
		if (m<10) printf("0%d:", m); else printf("%d:", m); 
		if (s<10) printf("0%d", s); else printf("%d", s);  
	
}

void inMap(int a[50][50], int n, int m){
	int i, j;
	char in1='x', in2='.', in3='#', in4='P';
	for (i=0;i<n+1;i++){
		for (j=0;j<m+1;j++){
			if (a[i][j]==1000)	printf("%-3c", in4);
				else if (a[i][j]==100)	printf ("%-3c", in3);
					else if (a[i][j]==111) printf("%-3c", in2);
	    				else if (a[i][j] == 1111) printf("%-3c", in1);
	    					else if (0<=a[i][j] && a[i][j] <= 50 && i==0 && 0<=j && j<= m) printf("%-3d", a[i][j]);
								else if (0<=a[i][j] && a[i][j] <= 50 && 0<=i && i<=n && j==0) printf("%-3d", a[i][j]);
									else printf("%-3d", a[i][j]);
		}
		printf("\n");
	}
}

void huongDan(){
		printf("\n                ---+++HUONG DAN+++---\n");
		printf(" ___________________________________________________________\n");
		printf("|	1. Nguoi choi chon muc choi phu hop.                |\n");
		printf("|	2a. Nhap toa do o can mo.                           |\n");
		printf("|	2b. Nhap toa do de danh dau vi tri Boom	            |\n");
		printf("\n                ---+++LUAT CHOI+++---\n");
		printf(" ___________________________________________________________\n");
		printf("|	- Cac so 1,2,...,8: La so qua Boom xung quanh o do. |\n");
		printf("|	- Ki tu '.' nghia la khong co Boom xung quanh o do. |\n");
		printf("|	--> Lose: Neu mo ngay o chua Boom.                  |\n");
		printf("|	--> Win: Neu danh dau het Boom, mo het o khong Boom |\n\n");
		printf("Go Back de quay lai Menu."); 
	getch();
}

void kyLuc(int de, int tb, int kho){
		int h, m, s;
		system("cls");
		printf("\n               ---+++KY LUC WINNER+++---\n");
		printf(" _______________________________________________________________\n");
		printf("|_____DE: ");
			s=de;
			h=s/3600;
			m= (s - 3600*h)/60;
			s= s - 3600*h - 60*m;
				if (h<10) printf("0%d:", h); else printf("%d:", h);
				if (m<10) printf("0%d:", m); else printf("%d:", m); 
				if (s<10) printf("0%d", s); else printf("%d", s); 
		printf("|_____TRUNG BINH: ");
			s=tb;
			h=s/3600;
			m= (s - 3600*h)/60;
			s= s - 3600*h - 60*m;
				if (h<10) printf("0%d:", h); else printf("%d:", h);
				if (m<10) printf("0%d:", m); else printf("%d:", m); 
				if (s<10) printf("0%d", s); else printf("%d", s); 
		printf("|_____KHO: ");
			s=kho;
			h=s/3600;
			m= (s - 3600*h)/60;
			s= s - 3600*h - 60*m;
				if (h<10) printf("0%d:", h); else printf("%d:", h);
				if (m<10) printf("0%d:", m); else printf("%d:", m); 
				if (s<10) printf("0%d|", s); else printf("%d|", s);
		printf("\n\nGo Back de quay lai Menu."); 
	getch();
}

int kiemTraWin(int a[50][50], int n, int m) {
	int i, j, count=0;
	for (i=1;i<n+1;i++){
		for (j=1;j<m+1;j++){
			if (a[i][j]== 100) {
				count+=1;
			}
		}
	}
	count = n*m - count;
	return count;
}

int main(){
    int a[50][50], b[50][50], chonMenu=0, chonThietLap, chonDie;
	int soCot, soDong, soBoom, cotNhap, dongNhap, timeT, timeS;	
	int die = 0, win = 0, flag, boomConLai, ktWin;
	int rankDe = 0, rankTb = 0, rankKho = 0;
	while (chonMenu != 4){
		system("cls");
		printf("  %c...MINESWEEPER...%c\n\n", (char)174, (char)175);
		printf("_____Moi Ban Chon______\n");
		printf("|...1. CHOI NGAY......|\n");
		printf("|...2. HUONG DAN......|\n");
		printf("|...3. KY LUC.........|\n");
		printf("|...4. THOAT..........|\n\n");
		printf("Ban chon: "); scanf("%d", &chonMenu);
		switch (chonMenu){
			case (1):{
				system("cls");
				printf("___________CHON DO KHO_______________\n");
				printf("|___1.DE..........(9x9-10 BOOM)_____|\n");
				printf("|___2.TRUNG BINH..(16x16-40 BOOM)___|\n");
				printf("|___3.KHO.........(16x31-99 BOOM)___|\n");
				printf("|___4.TU THIET LAP DO KHO___________|\n\n");
				printf("Ban chon: "); scanf("%d", &chonThietLap);
				
				switch (chonThietLap){
					case (1):{
						soCot = 9;
						soDong = 9;
						soBoom = 10;
						break;
					}
					case (2):{
						soCot = 16;
						soDong = 16;
						soBoom = 40;
						break;
					}
					case (3):{
						soCot = 30;
						soDong = 16;
						soBoom = 99;
						break;
					}
					case (4):{
						printf("LUU Y: QUY MO <=[50x50] - SO BOOM <=2500\n");
						do {	printf("So Dong: "); scanf("%d", &soDong);	} while (soDong<1 || soDong>50);
						do {	printf("So Cot : "); scanf("%d", &soCot);	} while (soCot<1 || soCot>50);
						printf("LUY Y: 0 < BOOM < %d", soDong*soCot*25/100);
						do {	printf("\nSo Boom: "); scanf("%d", &soBoom);} while (soBoom<1 || soBoom > soDong*soCot*25/100);
						break;
					}
				}
				taoMapRanDom(a, soDong, soCot, soBoom);
				taoMapNgoai(b, soDong, soCot);
				timeT = time(0);
				die = 0; win = 0; boomConLai=soBoom; ktWin=0;
					while (1)	{
						system("cls");
						for (flag = 0; flag <= (soCot*3 -18)/2; flag++){
							printf(" ");
						}
						printf("%c...MINESWEEPER...%c\n\n", (char)174, (char)175);
						printf("Cap Do: ");
						if (soDong == 9 && soCot == 9 && soBoom == 10) {
							printf("De [%dx%d]\n", soCot, soDong);
						} 	else if (soDong == 16 && soCot == 16 && soBoom == 40) {
									printf("Trung Binh [%dx%d]\n", soCot, soDong);
							} 	else if (soDong == 16 && soCot == 30 && soBoom == 99) {
								 		printf("Kho [%dx%d]\n", soCot, soDong);
								}	else {
											printf("Nguoi Choi Thiet Lap: [%dx%d]\n", soCot, soDong);
									}
						printf("So Boom con lai: %d\n", boomConLai);
						printf("So o chua mo: %d\nSo o da mo: %d\n", soDong*soCot - ktWin, ktWin);
						for (flag = 1; flag<= soCot;flag++){
							printf("___");
						}
						printf("\n");
						inMap(b, soDong, soCot);
						for (flag = 1; flag<= soCot;flag++){
							printf("___");
						}
						printf("\nChon o: \n");
						printf("Dong: "); scanf("%d", &dongNhap);
						printf(" Cot: "); scanf("%d", &cotNhap);
						printf("Ban mo hay danh dau Boom?");
						flag=0;
						printf("\n1.Mo\n2.Danh dau\nBan chon: "); scanf("%d", &flag);
						if (flag == 1){
							//xu ly khi mo O Chua Boom --> thua
							if (a[dongNhap][cotNhap]==1111) {
								timeS = time(0);
								die = 1;
								break;
							}
							//Xu ly khi mo O Mang So (0<so<9) --> tiep tuc
							if (0<a[dongNhap][cotNhap] && a[dongNhap][cotNhap] <9) {
								b[dongNhap][cotNhap]=a[dongNhap][cotNhap];
								ktWin = kiemTraWin(b, soDong, soCot);
							}
							//xu ly khi mo O Rong
							if (a[dongNhap][cotNhap] == 111) {
								moO(a, b, soDong, soCot, dongNhap, cotNhap);
								ktWin = kiemTraWin(b, soDong, soCot);
							}
						} 
						if (flag == 2) {
							if (0< boomConLai) {
								b[dongNhap][cotNhap]=1000;
								boomConLai-=1;
								ktWin = kiemTraWin(b, soDong, soCot);
							}
							if (boomConLai < 0){
						  		printf("So Boom da danh dau het!");
						  		printf("\nGo Enter de tiep tuc.");
						  		getch();
							} 
						}
						if (boomConLai == 0 && ktWin == soDong*soCot) {
							timeS=time(0);
							if (soCot == 9 && soDong == 9 && soBoom == 10){
								rankDe = timeS - timeT;
							}	else if (soCot == 16 && soDong == 16 && soBoom == 40){
										rankTb = timeS - timeT;
								}   else if (soCot == 30 && soDong == 16 && soBoom == 99){
										rankKho = timeS - timeT;
									}
							win=1;
							break;
						}
						
					};
					//Xu ly khi thua
					if (die == 1){
						system("cls");
						for (flag = 0; flag <= (soCot*3 -18)/2; flag++){
							printf(" ");
						}
						printf("%c...MINESWEEPER...%c\n", (char)174, (char)175);
						for (flag = 1; flag<= soCot;flag++){
							printf("___");
							if (flag == soCot/2) {
								printf("Map");
								flag+=1;
							}
						}
						printf("\n");
						inMap(a, soDong, soCot);
						for (flag = 1; flag<= soCot;flag++){
							printf("___");
						} 
						printf("\n  Vi tri [%d;%d] chua Boom\n  BAN DA THUA\n", dongNhap, cotNhap);
						timePlay(timeT, timeS);
						printf("\nGo Back de quay ve Menu.");
						getch();
						break; 
					}
					//Xu ly khi Thang
					if (win == 1){
						system("cls");
						for (flag = 0; flag <= (soCot*3 -18)/2; flag++){
							printf(" ");
						}
						printf("%c...MINESWEEPER...%c\n", (char)174, (char)175);
						for (flag = 1; flag<= soCot;flag++){
							printf("___");
							if (flag == soCot/2) {
								printf("Map");
								flag+=1;
							}
						}
						printf("\n");
						inMap(a, soDong, soCot);
						for (flag = 1; flag<= soCot;flag++){
							printf("___");
						}
						printf("\n  Tuyet voi!\n");
						printf("  BAN DA THANG\n");
						timePlay(timeT, timeS);
						if ((soCot == 9 && soDong == 9 && soBoom == 10)||
						(soCot == 16 && soDong == 16 && soBoom == 40)||
						(soCot == 31 && soDong == 16 && soBoom == 99)) {
							printf("\n\nKet qua cua ban da duoc ghi nhan.");
						}
						printf("\nGo Back de quay ve Menu.");
						getch();
						break;
					}
				break;
				}
			case (2):{
				system("cls");
				huongDan();
				break;
			}
			case (3):{
				kyLuc(rankDe, rankTb, rankKho);
				break;
			}
		}
	}
	return 0;
}


