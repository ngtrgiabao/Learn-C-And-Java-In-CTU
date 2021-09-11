#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	int m, count;
	int call[25];
} money;

money* readFile(int *n){
	FILE *f = fopen("D:\\ATM.txt", "r");
	if (f == NULL){
		printf("file bi loi!");
	}
	else{
		int i = 0;
		money *temp = (money*)malloc(sizeof(money));
		while(!feof(f)){
			fscanf(f, "%d", &temp[i].m);
			fgets(temp[i].call, 25, f);
			strtok(temp[i].call, "\n");
			temp[i].count = 0;
			i++;
			temp = (money*) realloc(temp, sizeof(money)*(i+1));
		}
		*n = i;
		return temp;	
	}
}

void printData(money *data, int n){
	int i;
	for(i=0; i<n; i++){
		printf("|%7d|%20s|%2d|\n", data[i].m, data[i].call, data[i].count);
	}
}

void swap(money *a, money *b){
	money temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(money *data, int n){
	int i, j;
	for(i = 0; i<n-1; i++){
		for(j=n-1; j>=i+1; j--){
			if (data[j].m > data[j-1].m){ // max - min
				swap(&data[j], &data[j-1]);
			}
		}
	}
}

int greedy(money *data, int n, long long int t){
	int i = 0;
	int minMoney = data[n-1].m;
	while (i<n && t > minMoney){
		data[i].count = t / data[i].m;
		t -= data[i].m*data[i].count;
		i++;
	}
	return t;
}


int main(){
	int n = 0;
	money *data = readFile(&n);
	long long int moneyNeed;
	printf("nhap so tien can rut: "); scanf("%lld", &moneyNeed);
	bubbleSort(data, n); // sort lai cho giong
	int moneyBefore = greedy(data, n, moneyNeed);
	if (!moneyBefore){
		printf("Doi duoc het tien!\nKet qua doi:\n");
		printData(data, n); 
	}
	else{
		printf("Ket qua doi:\n");
		printData(data, n); 
		printf("So tien doi duoc: %d\n", moneyNeed - moneyBefore);
		printf("Con thieu: %d", moneyBefore);
	}

	return 0;
}
