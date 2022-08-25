#include <stdio.h>
#include <string.h>
struct student{
   char name[50];
   int height;
   char diaChi[50];
};
int main(){
    struct student stud1[50], stud2[50];   
    FILE *fptr;
    int i, n;
    printf("Nhap so luong sinh vien: "); scanf("%d[^\n]", &n);
    fptr = fopen("C:\\tap tin nhi phan (tn1).dat", "w");
    //nhap su lieu vao mang
    for(i = 0; i < n; i++){
        if (fgets(stud1[i].name, 51, stdin)!= NULL);
        printf("Enter name: ");
        fgets(stud1[i].name, 51, stdin);
        strtok(stud1[i].name, "\n");
        
        printf("Enter height: "); 
        scanf("%d[^\n]", &stud1[i].height);
        
        if (fgets(stud1[i].diaChi, 51, stdin)!= NULL);
        printf("Enter diaChi: ");
        fgets(stud1[i].diaChi, 51, stdin);
        strtok(stud1[i].diaChi, "\n");
    }
    
    // ghi du lieu vao file
    fwrite(stud1, sizeof(stud1), 1, fptr);
    fclose(fptr);
    fptr = fopen("C:\\tap tin nhi phan (tn1).dat", "r");
    // doc du lieu tu file
    fread(stud2, sizeof(stud2), 1, fptr);
    for(i = 0; i < n; i++){
        printf("Name: %s Height: %d diaChi: %s\n", stud2[i].name, stud2[i].height, stud2[i].diaChi);
    }
    fclose(fptr);
}



