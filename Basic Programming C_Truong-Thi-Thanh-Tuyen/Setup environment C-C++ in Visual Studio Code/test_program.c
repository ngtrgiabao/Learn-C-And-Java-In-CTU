#include<stdio.h>
#include<string.h> 

int main(){
   int a;
   printf("Input number a = ");
   scanf("%d", &a);
   getchar(); // bỏ kí tự xuống dòng trong khi scanf
   char name[20];
   printf("Input name: ");
   fgets(name, 21, stdin);
   strtok(name, "\n");
   printf("Answer: %s %d", name, a);
   return 0;
}