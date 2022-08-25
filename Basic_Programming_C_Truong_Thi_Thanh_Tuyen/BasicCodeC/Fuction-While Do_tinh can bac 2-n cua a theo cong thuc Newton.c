#include<stdio.h>
#include<math.h>

double sqrtN(double n, double a){ // tinh can bac n cua a 
	double xn, xn1, kt=1;
	xn=a/n;	//xn=x0
	// cong thuc Newton tinh can bac n cua a (a>0)
	while (kt>=0.001){  // o day lay epsilon = 0,001 (do chinh xac cua phep tinh)
		// fabs lay tri tuyet doi cua so thua
		xn1=fabs( ((n-1)*pow(xn,n) + a) / (n*pow(xn,n-1)) ); 
		kt=fabs(a - pow(xn,n));
		xn=xn1;
	}
	return xn1;
}

double sqrt2(double a){ // tinh can bac 2 cua a 
	double xn, xn1, kt=1;
	xn=(a+1)/2;	//xn=x0
	// cong thuc Newton tinh can bac n cua a (a>0)
	while (kt>=0.001) {// o day lay epsilon = 0,001 (do chinh xac cua phep tinh)
		xn1=(xn+ a/xn)/2;
		kt=fabs((xn1-xn)/xn);
		xn=xn1;
	}
	return xn1;
}

int main(){
	double a, n; 	
	do {
		printf("Nhap n = "); scanf("%lf", &n);
		printf("     a = "); scanf("%lf", &a);
	} while (a<0 && n==0);
	printf("Can bac 2 cua %.f la %f\n", a, sqrt2(a));
	printf("Can bac %.f cua %.f la %f\n", n, a, sqrtN(n, a));
	return 0;
}
