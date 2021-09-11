#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int ranDomSo(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}

void khoiTaoMang(int a[500], int n){
	int i;
	for (i=0;i<n;i++){
		srand((int)time(0)+i);
		a[i]=ranDomSo(1,n);
	}
}

//Min --> Max
void selectionSort(int a[500], int n){
	int i, j, min, temp;
	for (i=0; i<n; i++){
		min=i;
		for (j=i+1; j<n; j++){
			if (a[min] > a[j]) min=j;
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
}

//Min --> Max
void interchangeSort(int a[500], int n){
	int i, j, temp;
	for (i=0; i<n-1; i++){
		for (j=i+1; j<n; j++){
			if (a[i] > a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			} 
		}
	}
}

//Min --> Max
void bubbleSort(int a[500], int n){
	int i, j, temp;
	for (i=0; i<n; i++){
		for (j=n-1; j>i; j--){
			if (a[j-1] > a[j]){
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			} 
		}
	}
}

//Min --> Max
void ShakerSort(int a[500], int n){
	int i, Left=0, Right=n-1, k=0, temp;
	while (Left < Right){
		for (i = Left; i < Right; i++){
			if (a[i] > a[i + 1]){
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				k=i;
			}
		}
		Right=k;
		for (i = Right; i > Left; i--){
			if (a[i - 1] > a[i]){
				temp=a[i-1];
				a[i-1]=a[i];
				a[i]=temp;
				k=i;
			}
		}
		Left=k;
	}
}
//Min --> Max
void insertionSort (int a[],int n)
{
    int i, j, t;
    for(i=1;i<n;i++)
    {
       j=i-1;
       t=a[i];
       while(j >= 0 && t < a[j])
       {
           a[j+1]=a[j];
           j--;
       }
       a[j+1]=t;
    }  
}

//Min --> Max 
void oddEvenSort(int a[500], int n){
	int i, temp, flag = 1;
  	while(flag){
    	flag = 0;
    	for (i=0; i<n-1; i+=2){ 
      		if (a[i] > a[i+1]){
       			temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
       			flag = 1;
     		}
    	}
    	for (i=1; i<n;i+=2){ 
    		if (a[i] > a[i+1]){
        		temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
        		flag = 1;
    		}
    	}
  	}
}

//Min -->Max
void countingSort(int a[500], int n){
    int temp[n];
	int i, k, max=a[0], min=a[0];
    for(i=1; i<n; i++){
        if(a[i] > max)	max=a[i];
        	else if(a[i] < min)	min=a[i];
    }
 	k=max-min +1; 
 	int count[k];
    for(i=0; i<k; i++)	count[i]=0;
 	for(i=0; i<n; i++)	count[a[i] -min]++;
	for(i=1; i<k; i++)	count[i]+=count[i-1];
 	for(i=0; i<n; i++){
        temp[count[a[i] -min] -1]=a[i];
        count[a[i] -min]--;
    }
 	for(i=0; i<n; i++)	a[i]=temp[i];
 
}
  	
void xuatMang(int a[500], int n){
	int i;
	for (i=0;i<n;i++){
		if (i%20==0) printf("\n");
		printf("%-3d ", a[i]);
	}
}

int main(){
	int a[500], i, n;
	printf("Nhap so phan tu: "); scanf("%d", &n);
	khoiTaoMang(a, n);
	printf("\nMang vua khoi tao:\n");
	xuatMang(a, n);
	printf("\n\nMang sau khi sap xep:\n");
	//selectionSort(a, n);
	//interchangeSort(a, n);
	///bubbleSort(a, n);
	//ShakerSort(a, n);
	//insertionSort(a, n);
	//oddEvenSort(a, n);
	countingSort(a, n);
	xuatMang(a, n);
	return 0;
}
