#include<stdio.h>
#include<malloc.h>

// Binary Tree - 9 Ham co ban-------------------------------
// Khai Bao
typedef int TData; // chon int lam kiue du lieu cho cay
struct TNode{
	TData Data;
	struct TNode *Left,*Right;
};
typedef struct TNode* TTree;

// Cac ham co ban
	// 1. Tao cay rong
	void makenullTree(TTree *pT){ 
		*pT = NULL; // trong BT khong co node header 
	}
	// 2. Kiem tra cay rong
	int emptyTree(TTree T){ 
		return T==NULL; 
	}
	// 3. Xac dinh con Trai
	TTree leftChild(TTree T){ 
		if (T != NULL) return T->Left;
		else return NULL; 
	}
	// 4. Xac dinh con Phai
	TTree rightChild(TTree T){ 
		if (T != NULL) return T->Right;
		else return NULL; 
	}
	// 5. Kiem tra nut La 
	int isLeaf(TTree T){ 
		if (T != NULL){
			return (T->Left == NULL) && (T->Right == NULL);
		}
		else return 0;
	} 
	// Cac ham duyet cay: Node(Root) - Left - Right
	// Phan biet 3 thanh phan tren
	// 6. Duyet Tien Tu - NLR
	void preOrder(TTree T){ //
		if (T != NULL){
			printf("%d ", T->Data);
			preOrder(T->Left);
			preOrder(T->Right); 
		}
		else printf("Cay rong!");
	}
	// 7. Duyet Trung Tu - LNR
	void inOrder(TTree T){
		if (T != NULL){
			inOrder(T->Left);
			printf("%d ", T->Data);
			inOrder(T->Right); 
		}
		else printf("Cay rong!");
	}
	// 8. Duyet Hau Tu - LNR
	void  posOrder(TTree T){
		if (T != NULL){
			posOrder(T->Left);
			posOrder(T->Right); 
			printf("%d ", T->Data);
		}
		else printf("Cay rong!");
	}
	// 9. Tao cay moi tu hai cay da co
	TTree create2(TData value,TTree left,TTree right){ 
		TTree N;
		N = (TTree)malloc(sizeof(struct TNode));
		N->Data = value;
		N->Left = left;
		N->Right = right;
		return N;
	}

int main(){
	
	return 0;
}
