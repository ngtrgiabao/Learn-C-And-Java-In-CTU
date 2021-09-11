#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   char chuoi[100];
   FILE *fptr;
   /*
   r doc file moi
   w ghi phai moi (xoa du lieu cu)*/
   fptr = fopen("C:\\Program Files\\Dev-Cpp\\cau truc file\\nhapdulieuvaofile.txt","w");
   if(fptr == NULL){
      printf("Error!");   
	  exit(1);         
   }
   printf("Enter num:");
   gets(chuoi);
   fprintf(fptr,"%s",chuoi);
   fclose(fptr);
   return 0;
}
