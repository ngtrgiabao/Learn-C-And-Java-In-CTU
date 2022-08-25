// Queue (Danh Sach Lien Ket - 4 Ham co ban)-----------------------------
#include<stdio.h>
#include<malloc.h>

// Dinh nghia Queue
typedef int ElementType;

struct Node {
	ElementType Element;
	struct Node* Next; 
};
 typedef struct Node* Position;
 typedef struct{
 	Position Front, Rear; // Front: Dau Queue, Rear: Cuoi Queue
 } Queue;
 
// Mot so ham bo tro
	// 1. Lam rong Queue
	void makenullQueue(Queue *pQ){
		Position hear;
		hear = (struct Node*)malloc(sizeof(struct Node));
		hear->Next = NULL;
		pQ->Front = hear;
		pQ->Rear = hear;
	}
	// 2. Kiem tra Queue co rong khong
	int emptyQueue(Queue Q){
		return Q.Front == Q.Rear;
	}
	
// 3. Xoa phan tu o dau Queue
	void deQueue(Queue *pQ){
		if (pQ->Front != pQ->Rear){
			Position temp;
			temp = pQ->Front;
			pQ->Front = pQ->Front->Next;
			free(temp);
		}
		else{
			printf("Hang rong");
		}
	}

// 4. Them phan tu vao cuoi Queue
	void enQueue(ElementType x, Queue *pQ){
		pQ->Rear->Next = (struct Node*) malloc(sizeof(struct Node));
		pQ->Rear = pQ->Rear->Next;
		pQ->Rear->Element = x;
		pQ->Rear->Next = NULL;
	} 
	
int main(){
	
	return 0;
}
	



