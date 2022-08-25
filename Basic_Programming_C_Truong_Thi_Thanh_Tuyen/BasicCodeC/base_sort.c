#include<stdio.h>
#include<math.h>

int ucln(int a, int b){
    return (b==0) ? a : ucln(b, a%b);
}

int linearSearch(int arr[], int lengthArr, int data){
    int i = 0;
    arr[lengthArr] = data;
    while (arr[i] != data) i++;
    if (i==lengthArr) return -1;
    return i;
}

void insert(int arr[], int lengthArr, int pos, int data){
	int i;
    for (i = lengthArr; i>pos; i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=data;
}

void deletek(int arr[], int lengthArr, int pos){
	int i;
    for (i = pos; i<lengthArr; i++){
        arr[i]=arr[i+1];
    }
}


int nguyenTo(int arrI){
    if (arrI == 1) return 0;
    int i;
    for (i = 2; i <= (int) sqrt(arrI); i++){
        if (arrI % i == 0) return 0;
    }
    return 1;
}

void inputArr(int arr[][100], int lengthRow, int lengthCol){
	int i;
    for (i =0; i<lengthRow*lengthCol; i++){
        scanf("%d", &arr[i/lengthCol][i%lengthCol]);
    }
}

void outputArr(int arr[][100], int lengthRow, int lengthCol){
	int i;
    for (i =0; i<lengthRow*lengthCol; i++){
        printf("%d ", arr[i/lengthCol][i%lengthCol]);
        if ((i+1)%lengthCol == 0) printf("\n");
    }
}

void bubbleSort(int arr[], int lengthArr){
    int i, y, temp, check = 1;
    for (i = lengthArr -1; i>=1; i--){
        for (y = 0; y < i; y++){
            if (arr[y]>arr[y+1]){
                temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
                check = 0;
            }
        }
        if (check) break;
    }
}

void insertionSort(int arr[], int lengthArr){
    int i, value, index;
    for (i = 1; i < lengthArr; i++){
        index= i;
        value=arr[i];
        while(index>0 && arr[index-1]>value){
            arr[index]=arr[index -1];
            index--;
        }
        arr[index]=value;
    }
}
void selectionSort(int a[], int n){
	int i, j, indexMin;
	for (i = 0; i < n-1; i++){
		indexMin = i;
		for (j = i+1; j < n; j++){
			if (a[indexMin] > a[j]){
				indexMin = j;
			}
		}
		if (i != indexMin){
			int temp = a[i];
			a[i] = a[indexMin];
			a[indexMin] = temp;
		}
	}
} 
void shellSort(int a[], int n){
	int interval, i, j, temp;
	for(interval = n/2; interval > 0; interval /= 2){
		for(i = interval; i < n; i++){
			temp = a[i];
			for(j = i; j >= interval && a[j - interval] > temp; j -= interval){
				a[j] = a[j - interval];				
			}
			a[j] = temp;
		}
    }
}

void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a, i, r);
	}
	if (l < j){
		quickSort(a, l, j);
	}
}

int main(){
    int n, i, arr[100], x, count=0;
    scanf("%d", &n);
    for (i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    } 
    scanf("%d", &x);
    for (i = 0; i<n; i++){
        if (arr[i]==x) count++;
    }
    printf("%d", count);
    return 0;
} 


