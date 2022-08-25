//De:
/* Nhap vao so dong (n = )
   in tam giac so nguyen to (n= 4) 
	2
	3	5
	7	11	13
	17	19	23	29
*/
#include<stdio.h>
#include<conio.h>

int nguyenTo(int a){
	int i, n=1, demuoc=0, moc=1;
	if (a==1) return 2;
		else if (a>=2)
		{
			while (moc<=a){
				n+=2;
				for (i=2;i<n;i++)
				{
					if(n%i==0) demuoc+=1;
				}
				if (demuoc==2)
				{
					moc+=1;
				} 
			} 
			return n;
		}
}

int main(){
	int n, i, j;
	do{
		printf("Nhap so tang tam giac: n = "); scanf("%d", &n);
	}	while (n<=0);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=i;j++)
		{
			printf("%-3d", nguyenTo(i+j-1));
		}
		printf("\n");
	}
	getch();
	return 0;
}
