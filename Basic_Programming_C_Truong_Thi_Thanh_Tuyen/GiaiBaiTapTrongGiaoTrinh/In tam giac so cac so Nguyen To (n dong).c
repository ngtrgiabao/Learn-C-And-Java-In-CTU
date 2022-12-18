#include<stdio.h>

int nguyenTo(int a){
	int i, dem=1, n=1, flag=0;
	if (a==1) return 2;
		else 	while (dem<=a){
					flag=0;
					for (i=2; i<n; i++){
						if (n%i==0) {
							flag=1;
						} 
					}
					if (flag==0){
						dem++;
						n+=2;
					} 
					if (flag==1) n+=2; 		
				}
	return (n-2);
}

int main(){
	int i, j, n, dem=0;
	printf("Nhap n: "); scanf("%d", &n);
	for (i=1; i<=n; i++){
		for (j=1; j<=i; j++){
			dem++;
			printf("%-3d ", nguyenTo(dem));
		}
		printf("\n");
	}
	return 0;
}
