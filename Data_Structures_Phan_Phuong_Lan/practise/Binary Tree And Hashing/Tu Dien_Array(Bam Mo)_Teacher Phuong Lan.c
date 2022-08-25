#include<stdio.h>
#include<malloc.h>

// Bang Bam (Bang Mo) - Ham co ban
// Thuc chat la mang cac danh sach (pointer)

// Dinh nghia kieu Dictionary
#define B 1000 // danh B co 1000 bang
typedef int ElementType;

struct Node{
    ElementType Data;
    struct Node* Next;
};

typedef struct Node* Position;
typedef Position Dictionary[B]; // Dictionary[i] co kieu la Position(struct Node*)

// Cac ham co ban
	// Tao Tu Dien Rong
    void makenullDic(Dictionary *D){
        for(int i=0;i<B;i++){
            (*D)[i] = NULL;    
        }
    }
    // Cai dac ham Bam
    int H(ElementType X){
        return X % B;
    }
	// Kiem tra su ton tai cua Phan Tu X
    int isMember(ElementType X, Dictionary D){
        Position P;
        P = D[H(X)]; //Tim phan tu o muc tuong ung trong Bang D[]
        while(P != NULL){
            if (P->Data == X) return 1;
            P = P->Next; 
        }
        return 0;
    }
    
// Them 1  Phan tu vao table (Them cuoi)
void insertDic(ElementType X, Dictionary *D){
    int bucket;
    Position P;
    if (!isMember(X,*D)){
        bucket = H(X);
        P = (*D)[bucket];
        //Cap phat o nho moi cho *D[Bucket]
        (*D)[bucket] = (struct Node*)malloc(sizeof(struct Node));
        (*D)[bucket]->Data = X; 
        (*D)[bucket]->Next = P; // them p vao dau cua P
    }
} 

// Xoa mot phan tu khoi tu Dien
void deleteDic(ElementType X,Dictionary *D){
    int Bucket = H(X);
    if ((*D)[Bucket] != NULL){
        Position P, Q;
        if ((*D)[Bucket]->Data == X){ // X o dau ds
            Q = (*D)[Bucket];
            (*D)[Bucket] = (*D)[Bucket]->Next;
            free(Q); // tuong tu ham deleteList
        }
        else{ // (*D)[Bucket]->Data != X
            int Done = 0;
            P = (*D)[Bucket];
            while (P->Next != NULL && !Done){
                if (P->Next->Data == X) Done = 1; 
                else P = P->Next;
            }
            if (Done){ 
                Q = P->Next; 
                P->Next = Q->Next;
                free(Q); //Xoa P->Next
            }
            else{
                printf("Khong ton tai x trong Danh sach!");
            }
        }
    }
    else{
        printf("Danh sach rong!");    
    }
}

int main(){
	
	return 0;
}

