#include<stdio.h>

const double PI = 3.141592653;

double cosx(double x, double epsilon){
	double sum = 1, tempX = 1, tempGT = 1, check = 2;
	int n = 1, soMu = 1, gt = 1;
	while (check >= epsilon){
		if (soMu == 1){
			sum -= (double) (tempX*x*x)/(tempGT*gt*(gt +1));
			check = (double) (tempX*x*x)/(tempGT*gt*(gt +1));
			tempX = tempX*x*x;
			tempGT = tempGT*gt*(gt +1);
		}	else if (soMu == 0){
				sum += (double) (tempX*x*x)/(tempGT*gt*(gt +1));
				check = (double) (tempX*x*x)/(tempGT*gt*(gt +1));
				tempX = tempX*x*x;
				tempGT = tempGT*gt*(gt +1);
			}
		soMu++;
		gt+=2;
		if (soMu == 2) soMu =0;
	}
	return sum;
}
int main(){
	int n;
	double x, epsilon;
	printf("Nhap n trong Cos(PI/n, epsilson): n = "); scanf("%d", &n);
	printf("Nhap epsilon trong Cos(PI/n, epsilson): epsilon = "); scanf("%lf", &epsilon);
	x = (double) PI/n;
	printf("Cos(PI/%d) = %lf", n, cosx(x, epsilon));
	return 0;
}


