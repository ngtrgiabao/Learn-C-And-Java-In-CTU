#include<stdio.h>

// Bang Bam ( Mang Dac) - 4 ham co ban

// Dinh nghia kieu SET
#define MaxLength 1000 // Bang gom 1000 phan tu
typedef int ElementType; // Chon int la kieu du lieu thanh vien
typedef int Position; // Chon kieu vi tri la int

typedef struct{
	ElementType Data[MaxLength];
	Position Last;
} SET;

// Cac ham co ban
	// Tao Bang Rong
	void makenullSet(SET *L){
		L->Last = 0;
	}
	// Kiem tra su ton tai cua Phan Tu X
	int isMember(ElementType X, SET L){
		Position p = 0;
		while (p < L.Last){
			if (L.Data[p] == X){
				return 1;
			} 
			p++;
		}
		return 0;
	}

// Them 1  Phan tu vao table (Them cuoi)
// Them vao cuoi la nhat
void insertSet(ElementType X, SET *L){
	if (L->Last == MaxLength){
		printf("Tu Dien da day!");
	}
	else if (!isMember(X,*L)) { // Khong ton tai x trong SET
		L->Last++; 
		L->Data[L->Last - 1] = X; // Them vao cuoi SET
	}
	else{
		printf("Phan tu da ton tai!");
	}
}
// Xoa mot phan tu khoi tu Dien
// Tim vi tri Q va thay bang gia tri cuoi (sau do xoa cuoi)
void deleteSet(ElementType X, SET *L){
	if (L->Last == 0){
		printf("Tap hop rong!");
	}
	else{
		Position p = 0;
		while(p <L->Last && L->Data[p] != X){
			p++;	
		}
		if (L->Data[p] == X){
			L->Data[p] = L->Data[L->Last - 1];
			L->Last--;
		}
	}
} 

int main(){
	
	return 0;
}


