#include<stdio.h>

// Bang Bam (Bang Dong) - Ham co ban

// Dinh nghia kieu Dictionary
#define B 100
#define DELETED – 1000 // Danh dau o da xoa - 1000
#define EMPTY 1000 // Danh dau o Rong

typedef int ElementType;
typedef ElementType Dictionary[B]; 

// Cac ham co ban
	// Tao Tu Dien Rong
    void makenullDic(Dictionary D){
       for (int i=0 ;i<B; i++){
            D[i] = EMPTY;
        }
    }
    // Cai dac ham Bam
    int H(ElementType X){
        return X % B;
    }
	// Kiem tra su ton tai cua Phan Tu X
	// Ham member tim kiem neu gap DELETED van tim tiep
    int isMember(ElementType X, Dictionary D){
        int i = 0, init = H(X);
        while(i<B && D[(i+init)%B] != EMPTY && D[(i+init)%B] != X){
            i++;   
        }
        return D[(i+init)%B] == X;
    }
    // Kiem tra Bang day
    int fullDic(Dictionary D){
        for (int i = 0; i<B; i++){
            if (D[i] == EMPTY) return 0;
        }
        return 1;
    }
    // Kiem tra Bang rong
    int emptyDic(Dictionary D){
        for (int i = 0; i<B; i++){
            if (D[i] != EMPTY) return 0;
        }
        return 1;
    }
// Them 1  Phan tu vao table (Them cuoi)
// Ham them se them khi gap DELETED hoac EMPTY

void insertDic(ElementType X, Dictionary D){
    if (fullDic(D)){
        printf("Bang bam day!");
    }
    else if (!isMember(X,D)){
        int i = 0, init = H(X); // Bam lan 1
        while(i<B && D[(i+init)%B] != EMPTY && D[(i+init)%B] != DELETED){ 
            i++;   // Bam them neu thoat dk while
        }
        D[(i+init)%B] = X; // bam xong roi gan lai
    }
    else{
        printf("Phan tu da ton tai!");   
    }
}
// Xoa mot phan tu khoi tu Dien
// Tim vi tri Q va thay bang gia tri cuoi (sau do xoa cuoi)
void deleteDic(ElementType X, Dictionary D){
    if (emptyDic(D)){
        printf("\nBang bam rong!");
    }
    else{
        int i = 0, init = H(X); // Bam lan 1
        // Neu D[(i+init)%B] != EMPTY thi khong ton tai x trong D
        while(i<B && D[(i+init)%B] != X && D[(i+init)%B] != EMPTY){ 
            i++;   // Bam them neu thoat dk while
        }
        if (D[(i+init)%B] == X){
            D[(i+init)%B] = DELETED; // Danh dau da xoa
        }
    }
}


int main(){
	
	return 0;
}

