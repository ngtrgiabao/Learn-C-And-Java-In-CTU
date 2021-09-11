#include<stdio.h>

void inputArray(int a[], int n){ // co the ghi a[100] hoac a[] deu duoc
	int i;
	for (i=0; i<n; i++){ // chi so mang bac dau tu 0 nen i chay tu 0
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void outputArray(int a[], int n){
	int i;
	printf("\nMang da nhap: ");
	for (i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}

void minMaxSumOfArray(int a[], int n){
	int i, demimax=0, demimin=0, max=a[0], min=a[0], sum=0;
	for (i=0;i<n;i++){
		if (a[i]>max) {
			max=a[i];
			demimax=i;
		}
		if (a[i]<min) {
			min=a[i];
			demimin=i;
		}
		sum+=a[i];
	}
	printf("\nPhan tu lon nhat cua mang: %d o vi tri: %d", max, demimax);
	printf("\nPhan tu nho nhat cua mang: %d o vi tri: %d", min, demimin);
	printf("\nTong cac phan tu: %d", sum);
}

void reverse(int a[], int n){ // dao chuoi khong dung ham trong string.h
	int i;
	if (n%2==0){
		for (i=0;i<n/2;i++){
			a[i] = a[i] + a[n -i -1] - (a[n -i -1] = a[i]);
		}
	}
	if (n%2==1){
		for (i=0;i<(n-1)/2;i++){
			a[i] = a[i] + a[n -i -1] - (a[n -i -1] = a[i]);
		}
	}
}

int main(){
	int a[50], n; // o ham main phai khai bao kich thuoc toi da cua mang
	do {
		printf("Nhap so phan tu: n = "); scanf("%d", &n);
	} while (n<=0);
	inputArray(a,n); // truyen mang la truyen dia chi
	outputArray(a,n); // nen a o day la &a = &a[0]
	minMaxSumOfArray(a,n); // truyen mang la truyen con tro. dung hon mang la Hang con tro
	reverse(a, n);
	printf("Mang sau khi dao: "); 
	outputArray(a,n);
	return 0;
}
