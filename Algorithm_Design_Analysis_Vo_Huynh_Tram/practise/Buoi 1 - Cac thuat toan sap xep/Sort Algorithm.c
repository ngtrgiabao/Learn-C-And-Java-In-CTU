#include<stdio.h>

#define max 100

typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
} recordtype;

void Swap(recordtype *x, recordtype *y){
  recordtype temp = *x;
  *x = *y;
  *y = temp;
}

void selectionSort(recordtype a[], int n){ // Sap xep chon
	int i,j, lowindex;
	keytype lowkey;
	for (i=0; i<n-1; i++){
		lowkey = a[i].key;
		lowindex = i;
		for (j=i+1; j<n; j++){
			if (a[j].key < lowkey){ // doi dau de thay doi min, max
				lowkey = a[j].key;
				lowindex = j;
			}
		}
		Swap(&a[i], &a[lowindex]);
	}
}
void insertionSort(recordtype a[], int n){ // Sap xep xen
	int i, j;
	for(i=1; i<n; i++){
		j=i;
		// min -> max: a[j].key < a[j-1].key
		// max -> min: a[j].key > a[j-1].key
		while (j>0 && a[j].key < a[j-1].key){
			Swap(&a[j], &a[j-1]);
			j--;
		}
	}
}

void bubbleSort(recordtype a[], int n) { // noi bot
	int i, j;
	for(i=0; i<n-1; i++){ // tang
		for(j=n-1; j>i; j--){ // giam
			if (a[j].key < a[j-1].key){ // Doi dau de chon min hay max
				Swap(&a[j], &a[j-1]);
			}
		}
	}	
}
// QuickSort (CTU)
/*___________________________________________*/
//int FindPivot(recordtype a[], int l, int r){ // min -> max
//	keytype firstkey = a[l].key;
//	int k = l+1;
//	while(k <= r && a[k].key == firstkey) k++;
//	if (k>r) return -1;
//	if (a[k].key > firstkey) return k;
//	return l;
//}
//int Partition(recordtype a[], int l, int r, keytype pivot){
//	while (l<=r){
//		while (a[l].key < pivot) l++;
//		while (a[r].key >= pivot) r--;
//		if (l<r) Swap(&a[l], &a[r]);
//	}
//	return l;
//}
//void QuickSort(recordtype a[], int l, int r){
//	keytype pivot;
//	int pivotindex, k;
//	pivotindex = FindPivot(a, l, r);
//	if (pivotindex != -1){
//		pivot = a[pivotindex].key;
//		k = Partition(a, l, r, pivot);
//		QuickSort(a, l, k-1);
//		QuickSort(a, k, r);
//	}
//}

//int FindPivot(recordtype a[], int i, int j){ // max -> min (Find:if:nth-child(2) + Par:while>while)
//	keytype firstkey = a[i].key;
//	int k = i+1;
//	while(k <= j && a[k].key == firstkey) k++;
//	if (k>j) return -1;
//	if (a[k].key < firstkey) return k; // doi dau
//	return i;
//}
//int Partition(recordtype a[], int l, int r, keytype pivot){
//	while (l<=r){
//		while (a[l].key > pivot) l++; // doi dau
//		while (a[r].key <= pivot) r--; // doi dau
//		if (l<r) Swap(&a[l], &a[r]);
//	}
//	return l;
//}

// Code de quy ngan gon tren mang:
	void QuickSortRecursive(recordtype a[], int l , int r){ // min -> max
		if (l <= r){
			int key = a[(l +r)/2].key;
			int i = l, j = r;
			while (i <= j){
				while (a[i].key < key) i++; // doi dau de doi cach sort
				while (a[j].key > key) j--; // doi dau de doi cach sort
				if (i <= j){
					Swap(&a[i], &a[j]);
					i++;
					j--;
				}
			}
			if (l < j) QuickSortRecursive(a, l, j);
			if (r > i) QuickSortRecursive(a, i, r);
		}
	}

	
/*___________________________________________*/
// HeapSort(CTU)

//void PushDown(recordtype a[], int first, int last){ // min -> max [Ðoi dau trong if ( < && >)]
//	int r = first;
//	while(r <= (last-1)/2){
//		if(last == 2*r+1){
//			if (a[r].key < a[last].key) Swap(&a[r], &a[last]);
//			r = last;
//		}
//		else if(a[r].key < a[2*r+1].key && a[2*r+1].key >= a[2*r+2].key){
//			Swap(&a[r], &a[2*r+1]);
//			r = 2*r+1;
//		}
//		else if(a[r].key < a[2*r+2].key && a[2*r+2].key > a[2*r+1].key){
//			Swap(&a[r], &a[2*r+2]);
//			r = 2*r+2;
//		}
//		else r = last;
//	}
//}

//void PushDown(recordtype a[], int first, int last){ // max -> min [Ðoi dau trong if ( > && <)]
//	int r = first;
//	while(r <= (last-1)/2){
//		if(last == 2*r+1){
//			if(a[r].key > a[last].key) Swap(&a[r], &a[last]);
//			r = last;
//		}
//		else if(a[r].key > a[2*r+1].key && a[2*r+1].key <= a[2*r+2].key){
//			Swap(&a[r], &a[2*r+1]);
//			r = 2*r+1;
//		}
//		else if (a[r].key > a[2*r+2].key && a[2*r+2].key < a[2*r+1].key){
//			Swap(&a[r], &a[2*r+2]);
//			r = 2*r+2;
//		}
//		else r = last;
//	}
//}

//void HeapSort(recordtype a[], int n){
//	int i;
//	for (i=(n-2)/2; i>=0; i--) PushDown(a, i, n-1);
//	for (i=n-1; i>=2; i--){	
//		Swap(&a[0], &a[i]);
//		PushDown(a, 0, i-1);
//	}
//	Swap(&a[0], &a[1]);
//}

// Code ngan gon hon tren mang:
	void Heapify(recordtype a[], int n, int i){
	    int largest = i, l = 2*i +1, r = 2*i +2; 
	    if (l<n && a[l].key < a[largest].key) largest = l; // doi chô so sanh key
	    if (r<n && a[r].key < a[largest].key) largest = r; // doi chô so sanh key
	    if (largest != i) {
	        Swap(&a[i], &a[largest]);
	        Heapify(a, n, largest);
	    }
	}
	void HeapSort(recordtype a[], int n){ // ket qua lai in Min - Max 
		int i;
	    for (i=n/2 -1; i>=0; i--) Heapify(a, n, i);
	    for (i=n -1; i>0; i--) {
	        Swap(&a[0], &a[i]);
	        Heapify(a, i, 0);
	    }
	}
/*_________________________________________________*/

// Merge sort: https://www.geeksforgeeks.org/merge-sort/
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    /* create temp arrays */
    int L[n1], R[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r){
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// ho tro code
void readData(recordtype a[], int *n){
	FILE *f = fopen("data_dynamic.txt", "r");
	int i=0;
	if(f!=NULL){
		while (!feof(f)){
			fscanf(f,"%d%f",&a[i].key, &a[i].otherfields);
			i++;
		} 
	}
	else printf("Loi mo file\n");
	fclose(f);
	*n=i; // cap nhap gia tri cho n
}
// in struct co 1 truong
void printArr(recordtype a[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", a[i].key);
	}
	printf("\n");
}
// in struct nhieu hon 1 truong
void printArrDynamic(recordtype a[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%3d%5d%8.2f\n",i+1, a[i].key, a[i].otherfields);
	}
}

int main(){
	int n, i;
	recordtype a[max];
// doc truc tiep voi so luong da biet
	freopen("data.txt", "r", stdin);
	scanf("%d", &n);
	for (i=0; i<n; i++){
		scanf("%d", &a[i].key);
		a[i].otherfields = 0; //gan gia tri mac dinh
	}
	// cac thao tac xu ly
	printf("n = %d\n", n);
	printf("Truoc khi sort: \n");
	printArr(a, n);
	HeapSort(a, n);
//	QuickSort(a, 0, n-1);
//  QuickSortRecursive(a, 0, n-1);
	printf("Sau khi sort: \n");
	printArr(a, n);
	
// doc qua ham voi so luong khong biet truoc
//	readData(a, &n);
//	// cac thao tac xu ly
//	printf("n = %d\n", n);
//	printf("Truoc khi sort: \n");
//	printArrDynamic(a, n);
//	bubbleSort(a, n);
//	printf("Sau khi sort: \n");
//	printArrDynamic(a, n);
	return 0;
}
