// Queue (Mang Vong - 7 Ham co ban)-----------------------------
/*
	Hinh tuong trung: 1 vong tron cac phan tu duoc danh so tu 0 den MaxLength -1
					  Theo thu tu tu Trai sang Phai: Front -> Rear
	Dac trung: 
		- Them phan tu vao cuoi Queue: Tang Rear len 1, gan gia tri cho o moi
		- Xoa phant tu o dau Queue: Tang front len 1
*/
#include<stdio.h>

#define MaxLength 100

// Dinh nghia Queue
typedef int ElementType;

typedef struct {
	ElementType Elements[MaxLength];
	int Front, Rear; // Front: Dau hang | Rear: Cuoi hang
} Queue;

// Mot so ham bo tro
	// 1. Lam rong Queue
	void makenullQueue(Queue *pQ){
		pQ->Front = -1;
		pQ->Rear = -1;
	}
	// 2. Kiem tra Queue co rong khong
	int emptyQueue(Queue Q){
		return Q.Front == -1;
	}
	// 3. Kiem tra Queue day khong
	int fullQueue(Queue Q){
		return (Q.Rear - Q.Front + 1) % MaxLength == 0;
	} 
	// 4. Tra ve gia tri phan tu dau tien cua Queue
	ElementType front(Queue Q){
		if (Q.Front != -1){
			return Q.Elements[Q.Front];
		}
		else{
			printf("Hang Doi rong!");
		}
	}
// 5. Xoa phan tu o dau Queue
	void deQueue(Queue *pQ){
		if (pQ->Front != -1){
			if (pQ->Front == pQ->Rear){
				makenullQueue(pQ);
			}
			else{
				pQ->Front = (pQ->Front+1) % MaxLength;
			}
		}
		else{
			printf("Hang rong!");
		}
	}
// 6. Them phan tu vao cuoi Queue
	void enQueue(ElementType x, Queue *pQ){
		if ((pQ->Rear - pQ->Front + 1) % MaxLength != 0){ // kt fullQueue chua
			if (pQ->Front == -1){
				pQ->Front=0;
			}
			pQ->Rear = (pQ->Rear + 1) % MaxLength; 
			pQ->Elements[pQ->Rear] = x;
		}
		else{
			printf("Hang day!");
		} 
	} 
// 7. Hien thi danh sach phan tu trong Queue (chi co the xoa phan tu va lay gia tri o dinh Queue)
	void printQueue(Queue *pQ){
		while(!emptyQueue(*pQ)){
			int top;
			deQueue(pQ, &top);
		 	printf("%d\t",top);
		}
		printf("\n");
	} 
	
int main(){
	
	return 0;
}
	
// Tren Else nen dung mang vong 
// Cac bai tren Else no khong co yeu cau viet ham, chi viet chuong trinh
