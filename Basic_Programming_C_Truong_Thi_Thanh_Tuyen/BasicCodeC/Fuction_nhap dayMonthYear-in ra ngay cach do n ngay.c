#include<stdio.h>

int dayInMonth(int month, int year){
	if (month==1|| month==3|| month==5|| month==7|| month==8|| month==10|| month == 12) return 31;
	else if (month==4|| month==6|| month==9|| month==11) return 31;
	else {
		if ((year%400==0) || (year%4==0 && year%100!=0)) return 29;
		else return 28;
	}
}

int dayInvalid(int day, int month, int year){
	if (day<=0 ||day>dayInMonth(month, year)||month<=0|| month>12|| year<=0) return 0;
}

int main(){
	int month, year;
	unsigned long long day;
	do {
		printf("Nhap ngay: "); scanf("%lld", &day);
		printf("Nhap thang: "); scanf("%d", &month);
		printf("Nhap nam: "); scanf("%d", &year);
		if (!dayInvalid(day, month, year)) printf("Ngay ban nhap khong hop le!\n");
	} while (!dayInvalid(day, month, year));
	printf("Ngay ban nhap: %d- %d- %d\n", day, month, year);
	unsigned long long n;
	printf("Nhap so ngay tiep theo: n = "); scanf("%lld", &n);
	day += n;
 	while (day>=dayInMonth(month, year)){
 		day -= dayInMonth(month, year);
 		month++;
 		if (month>12) {
 			year++;
 			month = 1;
		}
	}
	printf("Ngay in ra: %d- %d- %d", day, month, year);
	return 0;
}
