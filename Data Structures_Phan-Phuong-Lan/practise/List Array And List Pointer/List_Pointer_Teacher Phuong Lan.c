/*
	Quy tac dat ten trong C (Google):
	- tên bien: hocSinh, sinhVien
	- tên Hang: MAX, MIN
	- tên ham: interchangeSort, quickSort
		 hoac: interchange_sort, quick_sort
	- tên struct: student_in_class_t, teacher_t, list_t (_t: type)
		 hoac: StudentInClass, Teacher, List (bao gom typedef)
	*** Nhung mà hoc ai thi nghe nguoi do
*/

// List (Danh Sach Lien Ket - Ham Co Ban)-------------------------
#include<stdio.h>
#include<malloc.h>

// Dinh nghia List
typedef int ElementType;
struct Node {
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* List;
typedef List Position;

// Diem khac biet voi 1 so dinh nghia tren google la CTU day co 
// Node Hear (Header) mang gia tri mac dinh la 0

// Cac ham bo tro
	// 1. Khoi tao List
	void makenullList(List *pL){
		*pL = (List) malloc(sizeof(struct Node));
		(*pL)->Next = NULL;

	}
	// 2. Kiem tra List rong hay khong
	int emptyList(List L){
		return L->Next == NULL;
	}
	// 3. Tra ve vi tri dau tien cua List
	Position firstList(List L){
		return L;
	}
	// 4. Tra ve vi tri cuoi cung trong List
	Position endList(List L){
		Position P;
		P = L;
		while (P->Next != NULL){
			P = P->Next;
		} 
		return P;
	}
	// 5. Xac dinh noi dung phan tu tai vi tri p trong List
	ElementType retrieve(Position p, List L){
		if (p->Next != NULL){
			return p->Next->Element;
		}
		else{
			printf("vi tri p khong hop le!");
		}
	}
	
// 6. Them phan tu vao vi tri p trong List
	void insertList(ElementType x, Position p, List *pL){
		Position temp;
		temp = (List) malloc(sizeof(struct Node));
		temp->Element = x;
		temp->Next = p->Next;
		p->Next = temp;

	}

// 7. Xoa phan tu vi tri p trong List
	void deleteList(Position p, List *pL){
		Position temp;
		if (p->Next != NULL){
			temp = p->Next;
			p->Next = temp->Next;
			free(temp);
		}

	}


// 8. Tra ve vi tri cua x trong List
	Position locate(ElementType x, List L){
		Position p = L;
		while (p->Next != NULL){
			if (p->Next->Element == x){
				return p;
			} 
			p = p->Next;
		}
		return p; // p->Next == NULL
	}

// 9. Kiem tra su ton tai cua x trong List
	int member(ElementType x, List L){
		Position p = L->Next;
		while (p != NULL){
			if (p->Element == x){
				return 1;
			} 
			p = p->Next;
		}
		return 0;
	}

// 10. In noi dung cac phan tu cua List
	void printList(List L){
		Position P = L->Next;
		while (P != NULL){
			printf("%d ", P->Element);
			P = P->Next;
		}
		printf("\n"); // Xuong dong cho de nhin
	}


int main(){
	List L;
	int n;
	makenullList(&L);
	printf("Nhap so luong: ");
	scanf("%d", &n);
	int i, temp;
	for (i =1; i<=n; i++){
		printf("Phan tu %d: ", i);
		scanf("%d", &temp);
		insertList(temp, endList(L), &L);
	}
	printf("Danh sach da nhap: ");
	printList(L);
	while (1){
		printf("Nhap ptu can tim: ");
		int x;
		scanf("%d", &x);
		if (x == 1000) break;
		if (member(x, L)){
			printf("Tim thay phan tu tai vi tri: %d\n", locate(x, L));
			deleteList(locate(x, L), &L);
			printf("Danh sach sau khi xoa: ");
			printList(L);
		}
		else {
			printf("Khong ton tai trong L!\n");
		}
	}
	return 0;
}













