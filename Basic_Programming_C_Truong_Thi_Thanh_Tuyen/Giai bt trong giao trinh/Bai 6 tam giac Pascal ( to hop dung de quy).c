#include<stdio.h>
#include<conio.h>

int Tohop(int n, int k)
{
	if (k==0 || k==n) return 1;
		else if (k>=1 && n>k) return (Tohop(n-1,k-1) + Tohop(n-1,k));
}

int main(){
	int n, k, i, j;
	printf("Nhap so tang cua tam giac Pascal: ");
	scanf("%d", &n);
	printf("\n");
	for (i=0; i<=n; i++)
	{
		for (j=0; j<=n; j++)
		{
			if (j>=0 && j<=i) printf("%-6d", Tohop(i,j));
				else printf("------");
		}
		printf("%c (Bac %d)\n", '>', i);
	}
	getch();
	return 0;
}
