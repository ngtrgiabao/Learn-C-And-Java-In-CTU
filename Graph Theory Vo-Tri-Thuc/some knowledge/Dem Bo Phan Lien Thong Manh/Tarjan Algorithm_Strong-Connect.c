#include<stdio.h>

#define MAX 100
typedef struct{
    int a[MAX];
    int size;
} List;

void makenull(List *L){
    L->size = 0;
}

int empty(List *L){
   return L->size == 0; 
}

void push(List *L, int x){
    L->a[L->size] = x;
    L->size++;
}

void pop(List *L){
    L->size--;
}

int top(List *L){ // Them ham de su dung Stack
    return L->a[L->size -1];
}

int elementAt(List *L, int p){
    if (p<1 || p>L->size){
        printf("\nVi tri khong hop le!\n");
        return -1;
    }
	return L->a[p -1];
}

// khoi tao Graph (Ðinh - Ð?nh)
typedef struct{
    int a[MAX][MAX];
    int n, m;
}Graph;

void init(Graph *G, int n, int m){
    int i, j;
    G->n = n;
    G->m = m;
    for (i = 1; i<=G->n; i++){
        for (j = 1; j<=G->n; j++){
            G->a[i][j] = 0; // khoi tao matran 0
        }
    }
}

void add(Graph *G, int x, int y){ // do thi vo huong
    G->a[x][y] = 1;
}

int degree(Graph *G, int x){
    if (x < 1 || x > G->n){
        printf("\nDinh khong hop le hoac khong ton tai trong Graph\n");
        return -1;
    }
    int i, deg = 0;
    for (i = 1; i<=G->n; i++){
        if (G->a[x][i] == 1) deg++;
    }
    return deg;
}

int adjacent(Graph *G, int x, int y){
	return (G->a[x][y] == 1); 
} 

List neightbors(Graph *G, int x){
	List L;
	makenull(&L);
	int i;
	for (i = 1; i <= G->n; i++){
		if (G->a[x][i] == 1){ // co duong di tu x den i
			push(&L, i);
		}
	}
	return L;
}

// Combo thuat toan
int num[MAX], min_num[MAX], on_stack[MAX], idx = 1, count = 1;
List S;
int min(int a, int b){ 
	if (a<=b) return a;
	return b;
}

int initAlm(int n, int m){
	int i, j;
	for (i = 1; i<= n; i++){
		num[i] = min_num[i] = on_stack[i] = -1;
	}
	makenull(&S);
}
void strong_connect(Graph *G, int x) {
  	num[x] = min_num[x] = idx; idx++;
  	push(&S, x);
  	on_stack[x] = 1;
	List list = neightbors(G, x);
  	int j;
  	for (j = 1; j <= list.size; j++) {
    	int y = elementAt(&list, j);
    	if (num[y] < 0){
      		strong_connect(G, y);
      		count++;
      		min_num[x] = min(min_num[x], min_num[y]);
      	}
		else if (on_stack[y]){
      		min_num[x] = min(min_num[x], num[y]);
  		}
	}
	
  	if (num[x] == min_num[x]) {
    	int w;
    	printf("%d la dinh Khop\nBo phan lien thong manh gom: ", x);
		do {
	       	w = top(&S);
	       	printf("%d ", w);
	      	pop(&S);
	      	on_stack[w] = 0;
	    } while (w != x);
	    printf("\n\n");
  	}
}
/* Nay thi code tay :))) */
//int num[MAX_N], min_num[MAX_N], on_stack[MAX_N], idx = 1, count = 1;
//List S;
//int min(int a, int b){ 
//	if (a<=b) return a;
//	return b;
//}
//
//int init(int n, int m){
//	int i, j;
//	for (i = 1; i<= n; i++){
//		num[i] = min_num[i] = on_stack[i] = -1;
//	}
//	makeNullList(&S);
//}
//void tab(int n){
//	int i;
//	for (i = 1; i<= n; i++){
//		printf("  ");
//	}
//}
//void strong_connect(Graph *G, int x) {
//  	num[x] = min_num[x] = idx; idx++;
//  	tab(idx); printf("num[%d] = min_num[%d] = %d, idx = %d\n", x, x, idx -1, idx);
//  	push(&S, x);
//  	tab(idx); printf("Them %d vao Stack S\n", x);
//  	on_stack[x] = 1;
//    tab(idx); printf("on_stack[%d] = 1\n", x);
//	List list = neightbors(G, x);
//	tab(idx); printf("Hang som cua %d gom: ", x);
//  	int j;
//	for (j = 1; j <= list.size; j++) {
//    	printf("%d ", element_at(&list, j));
//	}
//	printf("\n");
//  	for (j = 1; j <= list.size; j++) {
//    	int y = element_at(&list, j);
//    	tab(idx - count +1); printf("j = %d, y = %d\n", j, y);
//    	if (num[y] < 0){
//    		tab(idx); printf("num[%d] = %d -> Goi de quy lan %d cho %d:\n\n", y, num[y], idx -1, y);
//      		strong_connect(G, y);
//      		count++;
//      		min_num[x] = min(min_num[x], min_num[y]);
//      		tab(idx - count); printf("Thoat khoi de quy lan %d\n", idx - count);
//			tab(idx - count); printf("min_num[%d] = %d\n", x, min_num[x]);
//      	}
//		else if (on_stack[y]){
//      		tab(idx - count); printf("on_stack[%d] = %d\n", y, on_stack[y]);
//      		min_num[x] = min(min_num[x], num[y]);
//      		tab(idx - count); printf("min_num[%d] = %d\n", x, min_num[x]);
//  		}
//	}
//	
//  	if (num[x] == min_num[x]) {
//  		printf("\n");
//  		tab(idx - count); printf("Ta co num[%d] = min_num[%d] = %d nen %d la dinh khop\n", x, x, num[x], x);
//    	tab(idx - count); printf("Danh sach dinh thuoc bo phan lien thong manh gom: ");
//    	int w;
//		do {
//	       	w = top(&S);
//	       	printf("%d ", w);
//	      	pop(&S);
//	      	on_stack[w] = 0;
//	    } while (w != x);
//  	}
//  	printf("\n");
//}

int main(){
	int n, m, u, v, e, i, j;
	freopen("graph_data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	Graph G;
	init(&G, n, m);
	for (e=1; e<=m; e++){
		scanf("%d%d", &u, &v);
		add(&G, u, v);
	}
	initAlm(n, m);
	strong_connect(&G, 1);
	return 0;
}


