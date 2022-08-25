#include<stdio.h>
#include<time.h>

int main(){
	//slep(sogiay) trong stdio.h
	//Slep(1 phan 1000 giay) trong window.h
	int i=0, timet, times;
	timet = time(0);
	printf(" Thoi gian bac dau: %d\n", timet);
	sleep(10);
	times = time(0);
	printf(" Thoi gian bac dau: %d\n", times);
	printf("Thoi gian chay chuong trinh: %d", times-timet);
	return 0;
}

