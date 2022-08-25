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

// List (Danh Sach Dac -11 Ham Co Ban)-------------------------
#include<stdio.h>

// Dinh nghia List
#define MaxLength 100

typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[MaxLength];
	Position Last;
} List;

// Cac ham bo tro
	// 1. Khoi tao List
	void makenullList(List *pL){
		pL->Last = 0;
	}
	// 2. Kiem tra List rong hay khong
	int emptyList(List L){
		return L.Last == 0;
	}
	// 3. Kiem tra List day hay khong
	int fullList(List L){
		return L.Last == MaxLength;
	}
	// 4. Tra ve vi tri dau tien cua List
	Position firstList(List L){
		return 1;
	}
	// 5. Tra ve vi tri cuoi cung trong List
	Position endList(List L){
		return L.Last + 1;
	}
	// 6. Xac dinh noi dung phan tu tai vi tri p trong List
	ElementType retrieve(Position p, List L){
		return L.Elements[p-1];
	}
	
// 7. Them phan tu vao vi tri p trong List
	void insertList(ElementType x, Position p, List *pL){
		if (pL->Last == MaxLength){
			printf("Danh sach day");
		}
		else if (p<1 || p> (pL->Last+1)){
			printf("Vi tri khong hop le");
		} 
		else{
			Position q;
			for (q = pL->Last; q > p-1; q--){
				pL->Elements[q]=pL->Elements[q-1];	
			}
			pL->Elements[p-1] = x;
			pL->Last++;
		}
	}

// 8. Xoa phan tu vi tri p trong List
	void deleteList(Position p, List *pL){
		if (p<1 || p>pL->Last){
			printf("Vi tri khong hop le");
		}
		else if (pL->Last == 0){
			printf("Danh sach rong!");
		}
		else{
			Position q;
			for(q = p-1; q< pL->Last - 1; q++){
				pL->Elements[q]=pL->Elements[q+1];
			}	
			pL->Last--;
		}
	}


// 9. Tra ve vi tri cua x trong List
Position locate(ElementType X, List L){
	Position p = 1;
	while (p < L.Last + 1){
		if (L.Elements[p-1] == X){
			return p;
		} 
		p++;
	}
	return L.Last +1;
}

// 10. Kiem tra su ton tai cua x trong List
int member(ElementType X, List L){
	Position p = 0;
	while (p < L.Last){
		if (L.Elements[p] == X){
			return 1;
		} 
		p++;
	}
	return 0;
}

// 11. In noi dung cac phan tu cua List
void printList(List L){
	Position p = 0;
	while (p < L.Last){
		printf("%d ", L.Elements[p]);
		p++;
	}
	printf("\n"); //  Xuong dong cho de nhin!
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
		insertList(temp, i, &L);
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













