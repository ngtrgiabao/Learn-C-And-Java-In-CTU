// Stack (Danh Sach Dac - 6 Ham co ban).........................
#include<stdio.h>
/*
	- Luu giu dinh ngan xep bang bien Top_idx;
		Top_idx = MaxLength: Ngan xep rong.
		Top_idx = 0: Ngan xep day.
	- Phan tu thu i co chi so truy cap trong mang la: [i-1]
	- Trong NganXep muon duyet qua tat ca phan tu thi phai:
	  		+ In gia tri o dinh Ngan Xep
	  		+ Giam gia tri Khoa Cuoi (Top_idx hoac Dinh)
*/

// Dinh nghia Stack
    #define MaxLength 100 // Cho Stack chua toi da 100 phan tu
    
	typedef int ElementType; // Doi kieu khac nhu SinhVien, Diem thay cho int (neu co)
	
	typedef struct {
		ElementType Elements[MaxLength];
		int Top_idx; 
	} Stack;

// Mot so ham bo tro
	// 1. Khoi Tao Stack
	void makenullStack(Stack *pS){
		pS->Top_idx = MaxLength;
	}
	// 2. Kiem tra Stack rong hay khong
	int emptyStack(Stack S){
		return S.Top_idx == MaxLength;
	}
	// 3. Kiem tra Stack day hay khong
	int fullStack(Stack S){
		return S.Top_idx == 0;
	}
	// 4. Lay gia tri phan tu dau tien cua Stack
	ElementType top(Stack S){
		if (S.Top_idx != MaxLength){
			return S.Elements[S.Top_idx];
		}
		else{
			printf("Ngan xep rong!");
		} 
	} 

// 5. Xoa 1 phan tu o dinh Stack
	void pop(Stack *pS){
		if (pS->Top_idx != MaxLength){
			pS->Top_idx++;
		}
		else{
			printf("Ngan xep rong!");
		} 
	} 

//  6. Them 1 phan tu vao dinh Stack
	void push(ElementType x, Stack *pS){
		if (pS->Top_idx != 0){
			pS->Top_idx--;
			pS->Elements[pS->Top_idx] = x; 
		}
		else{
			printf("Ngan xep day!"); 
		}
	}

int main(){
	return 0;
}


// Mot so ham tren He Thong Else
/*


#define M 100
typedef int Data;
typedef struct {
	Data DuLieu[M];
	int Dinh; 
} NganXep;


void khoitao(NganXep *pS){
    pS->Dinh = 100;
}


int ktDay(NganXep S){
    return S.Dinh == 0;
}

int ktRong(NganXep S){
    return S.Dinh == 100;
}

int giatriDinh(NganXep S){
    return S.DuLieu[S.Dinh];
}



void xoa(NganXep *pS){
    if (pS->Dinh != 100){
        pS->Dinh++;
    }
    else{
        printf("Ngan Xep rong khong the xoa!");
    }
}

void them(int x, NganXep *pS){
    if (pS->Dinh != 0){
        pS->Dinh--;
        pS->DuLieu[pS->Dinh] = x;
    }
    else{
        printf("Ngan Xep Day!");
    }
}

void hienthi(NganXep *pS){ // in toan bo Ngan Xep
    while (!ktRong(*pS)){
        printf("%d ", giatriDinh(*pS));
        xoa(pS);
    }
}

void hienthi(NganXep *pS){ // khu ham con
    while (pS->Dinh != 100){ // thuc chat la pS->Dinh <100
        printf("%d ", pS->DuLieu[pS->Dinh]);
        pS->Dinh++;
    }
}

*/










