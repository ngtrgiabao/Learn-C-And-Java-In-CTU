// Stack (Danh Sach Lien Ket - 5 Ham co ban)-----------------------
#include<stdio.h>
#include<malloc.h>

/*
  Mot So Luu Y:
  	  - Stack cai dac bang con tro chi la goi lai cac ham ben DSLK
  	  	(push <=> insertNode, pop <=> deleteList,..)
      - Goi Ham nhu DSLK (chu y tranh nham khi su dung con tro Bac 1 va Bac 2)
*/
// Dinh nghia Stack
typedef int ElementType;

struct Node{
	ElementType Element; 
	struct Node *Next; 
};

typedef struct Node* Position; 
typedef Position Stack; // Khai bao Position <=> struct Node*


// Mot so ham bo tro
	// 1. Khoi tao Stack
	void makenullStack(Stack *pS){
		*pS = (Stack) malloc(sizeof(struct Node));
		(*pS)->Next = NULL;
	}
	// 2. Kiem tra Stack rong hay khong
	int emptyStack(Stack S){
		return S->Next == NULL;
	}
	// 3. Tra ve gia tri dinh Stack
	   // Tren else co the bi loi do co truong hop khong co return
	   // Ham co gia tri tra ve phai co return o moi truong hop!
	ElementType top(Stack S){
		if (S->Next != NULL){
			return S->Next->Element;
		}
		else{
			printf("Ngan Xep rong!"); 
		}
	}
	
// 4. Them phan tu vao stack (do khong gioi han do dai nen khong can kt
	void push(ElementType x, Stack *pS){
		Position temp;
		temp = (Stack) malloc(sizeof(struct Node));
		temp->Element = x;
		temp->Next = (*pS)->Next;
		(*pS)->Next = temp;
	}

// 5. Xoa phan tu khoi stack
	void pop(Stack *pS){
		if ((*pS)->Next != NULL){
			Position temp = (*pS)->Next;
			(*pS)->Next= temp->Next;
			free(temp);
		}
		else{
			printf("Ngan Xep Rong!");
		}
	}
	

int main(){
	return 0;
}

