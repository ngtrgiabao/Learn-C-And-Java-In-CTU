#include<stdio.h>

int Giaithua(int n){
	if (n==0) return (1);
	 	else return (n*Giaithua(n-1));
}

int Tohop(int n, int k){
	return (Giaithua(n)/(Giaithua(n-k)*Giaithua(k)));
}

int main(){
	int n, k=0, i, j;
	printf("Nhap so tang cua tam giac Pascal: ");
	scanf("%d", &n);
	printf("\n");
	for (i=1;i<=n+1;i++){
		if (i%2==1){
			for (j=1;j<=2*n+1;j++)
				if (j>=n-i+2 && j<=n+i && j%2==1) {
					printf("%-4d", Tohop((i-1),k));
					k+=1;
				} else printf("----");	
			printf("%c (Bac %d) ", '>',i-1);				
			k=0;
			
		}
		if (i%2==0){
			for (j=1;j<=2*n+1;j++)
				if (j>=n-i+2 && j<=n+i && j%2==0) {
				 	printf("%-4d", Tohop((i-1),k)); 
				 	k+=1;
				} 
				else printf("----");	
			printf("%c (Bac %d) ", '>',i-1);		
			k=0;
		}
		printf("\n");
	}
	return 0;
}
