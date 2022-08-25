
#include<stdio.h>
#define MAX 100

typedef struct{
	int a[MAX][MAX];
	int n, m;
} Graph;

void init(Graph *G, int n, int m){ // khoi tao do thi
	int i, j;
	G->n = n;
	G->m = m;
	for (i = 1; i <= n ; i++){
		for (j = 1; j <= n; j++){
			G->a[i][j] = 0;
		}
	}
}

void add(Graph *G, int x, int y){ 
	G->a[x][y] = 1; // do thi co huong
}

int adjacent(Graph *G, int x, int y){ // kiem tra co phai lang gieng khong
	return G->a[x][y] == 1;
}

int degree(Graph *G, int x){ // tinh bac cua dinh x
	int i, deg = 0;
	for (i = 1; i <= G->n; i++){
		if (G->a[x][i] == 1) deg++;
	}
	return deg;
}

//List-----------------------------------------------
typedef struct{
	int data[MAX];
	int size;
} List;

void makeNull(List *L){ 
	L->size = 0;
}

int empty(List *L){
	return L->size == 0;
}

void pop(List *L){
	L->size--;
}

void push(List *L, int x){
	L->data[L->size] = x;
	L->size++;
}

int top(List *L){
	return L->data[L->size - 1];
}

int elementAt(List *L, int p){ 
	return L->data[p - 1];
}

List neightbors(Graph *G, int x){
	List L;
	makeNull(&L);
	int i;
	for (i = 1; i <= G->n; i++){
		if (G->a[x][i] == 1){
			push(&L, i);
		}
	}
	return L;
}

#define white 0 // dinh chua duoc duyet
#define black 1 // dinh da duyet (gom dinh do va cac hang xom cua no)
#define gray 2 // dinh dang duoc duyet
#define UNVISITED 0 // chua den
#define VISITED 1 // da den
#define POPPED -1 // da xet xong

int checkCycle(Graph *G, int u) { // do thi co huong (khu de quy)
    List S;
    makeNull(&S);
    push(&S, u);
    int status[MAX];
    int i;
    for (i = 1; i <= G->n; i++) {
        status[i] = UNVISITED;
    }
    while (!empty(&S)) {
        int y = top(&S);
        List L = neightbors(G, y);
        if (status[y] == UNVISITED) {
            status[y] = VISITED;
            for (i = 0; i < L.size; i++) {
                if (status[L.data[i]] == VISITED) return 1;
                else if (status[L.data[i]] == UNVISITED) push(&S, L.data[i]);
            }
        }
        else {
            pop(&S);
            status[y] = POPPED;
        }
    }
    return 0;
}

//int color[MAX];
//int cycle;

//void coloring(Graph *G, int x, int parent){ // danh cho do thi vo huong 
//    color[x] = gray;
//	int i;
//	List list = neightbors(G, x);
//	for (i = 1; i <= list.size; i++){ 
//		int y = elementAt(&list, i);
//		if (y==parent) continue;
//		if (color[y]==gray){
//		    cycle = 1;
//		    return;
//		}
//		if (color[y] == white) coloring(G, y, x);
//	}
//	color[x] = black;
//}
//
//int checkCycle(Graph *G){
//    int i;
//    for(i=1; i<=G->n; i++){
//        color[i] = white; // khoi tao mang chua duyet
//    }
//    cycle = 0;
//    for(i=1; i<=G->n; i++){
//        if (color[i] == white) coloring(G, i, 0);
//    }
//    return cycle;
//}

//void coloring(Graph *G, int u){ // danh cho do thi co huong 
//	color[u] = gray;
//    int i;
// 	List list = neightbors(G, u);
//    for (i = 1; i <= list.size; i++){ 
// 		int v = elementAt(&list, i);
// 		if (color[v]==gray){
//    		cycle = 1;
// 		    return;
// 		}
// 		if (color[v] == white){
//    		coloring(G, v);
//		}
//	}
// 	color[u] = black;
//}
//
// int checkCycle(Graph *G){
//    int i;
//    for(i=1; i<=G->n; i++){
//        color[i] = white; // khoi tao mang chua duyet
//    }
//    cycle = 0;
//	coloring(G, 1);
//    return cycle;
//}


// Thu thuat code tay
//void tab(int n){
//	int i;
//	for (i = 1; i<= n; i++){
//		printf("   ");
//	}
//}
//int idx = 1, count = 1;
//void coloring(Graph *G, int u){ // danh cho do thi co huong 
//	if (cycle) return;
//	idx++;
//    color[u] = gray;
//    tab(idx); printf("(1) u = %d, to mau GRAY cho dinh %d\n", u, u);
// 	int i;
// 	List list = neightbors(G, u);
//    tab(idx); printf("(2) xet cac dinh ke cua %d\n", u);
// 	for (i = 1; i <= list.size; i++){ 
// 		int v = elementAt(&list, i);
// 		if (color[v]==gray){
//    		tab(idx); printf("v = %d co mau GRAY\n", v);
//    		tab(idx +1); printf("phat hien chu trinh, cycle = 1\n");
//    		tab(idx +1); printf("return\n");
// 		    cycle = 1;
// 		    return;
// 		}
// 		else if (color[v] == white && cycle == 0){
//    		tab(idx); printf("v = %d, co mau WHITE, goi de quy duyet %d\n", v, v);
//    		coloring(G, v);
//			count++;
//		}
//		else {
//			tab(idx - count +1); printf("v = %d, co mau BLACK, khong lam gi ca\n", v);
//		}
//	}
// 	color[u] = black;
//    tab(idx - count +1); printf("To mau BLACK cho %d\n", u);
//}
//
// int checkCycle(Graph *G){
//    int i;
//    for(i=1; i<=G->n; i++){
//        color[i] = white; // khoi tao mang chua duyet
//    }
//    cycle = 0;
//	coloring(G, 1);
//    return cycle;
//}

int main(){
	Graph G;
	int n, m, i, u, v;
  	freopen("graph_data.txt", "r", stdin); // nop bai tren else thi bo dong nay
	scanf("%d%d", &n, &m); 
	init(&G, n, m);
	for (i = 1 ; i <= m; i++){
		scanf("%d%d", &u, &v); 
		add(&G, u, v);
	} 
	if (visit(&G, 1)) printf("Do thi co chua chu trinh");
	else printf("Do thi khong chua chu trinh");
	return 0;
}
