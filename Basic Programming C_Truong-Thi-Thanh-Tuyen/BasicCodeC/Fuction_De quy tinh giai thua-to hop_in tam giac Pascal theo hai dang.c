#include<stdio.h>

int giaiThua(int n){ 
	if (n==0) return 1;
	else return n*giaiThua(n-1);
}

int toHop(int n, int k){
	return giaiThua(n)/(giaiThua(n-k)*giaiThua(k));
}

int tohopCongThuc(int n, int k) // cong thuc
{
	if (k==0 || k==n) return 1;
	else if (k>=1 && n>k) return (tohopCongThuc(n-1,k-1) + tohopCongThuc(n-1,k));
}

int main(){
	int n, k=0, i, j;
	printf("Nhap so tang cua tam giac Pascal: ");
	scanf("%d", &n); // doan code dung de in n chan
	printf("\nTam giac pascal dang hinh tam giac can\n");
	for (i=1; i<=n+1; i++){
		if (i%2==0){				
			k=0;
			for (j=1; j<=2*n+1; j++)
				if (j>=n-i+1 && j<=n+i && j%2==0) {
					printf("%-4d", toHop((i-1),k));
					k++;
				} 
				else printf("    ");	
			printf("%c (Bac %d) ", '>',i-1);
		}
		if (i%2==1){		
			k=0;
			for (j=1; j<=2*n+1; j++)
				if (j>=n-i+1 && j<=n+i && j%2==1){
				 	printf("%-4d", toHop((i-1),k)); 
				 	k++;
				} 
				else printf("    ");	
			printf("%c (Bac %d) ", '>',i-1);
		}
		printf("\n");
	}
	printf("Tam giac pascal dang hinh vuong\n");
	for (i=0; i<=n; i++)
	{
		for (j=0; j<=n; j++)
		{
			if (j>=0 && j<=i) printf("%-6d", tohopCongThuc(i,j));
				else printf("------");
		}
		printf("%c (Bac %d)\n", '>', i);
	}
	return 0;
}
