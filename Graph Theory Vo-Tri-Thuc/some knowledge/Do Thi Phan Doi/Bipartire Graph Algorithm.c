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
	G->a[x][y] = G->a[y][x] = 1; // do thi vo huong
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

#define WHITE -1
#define BLUE 0
#define RED 1
//int color[MAX];
int conflict;

int colorize(Graph *G) {
    List S;
    makeNull(&S);
    push(&S, 1);
    int color[MAX], i;
    for (i = 1; i <= G->n; ++i) {
        color[i] = WHITE;
    }
    color[1] = BLUE;
    while (!empty(&S)) {
        int y = top(&S); pop(&S);
        List L = neightbors(G, y);
        for (i = 0; i < L.size; ++i) {
            if (color[L.data[i]] == WHITE) {
                color[L.data[i]] = !color[y];
                push(&S, L.data[i]);
            }
            else if (color[L.data[i]] == color[y]) return 0;
        }
    }
    return 1;
}

//void colorize(Graph *G, int u, int c) { //do thi vo huong
//	color[u] = c;
//    int i;
// 	List list = neightbors(G, u);
//    for (i = 1; i <= list.size; i++){ 
// 		int v = elementAt(&list, i);
//		if (color[v] == WHITE) colorize(G, v, !c); // RED
//		else if (color[v] == c) {
//			conflict = 1; //Dung do: 2 dinh ke to cung mau
//			return;
//		}
//	}
//}
//
//int checkBipartite(Graph *G){
//    int i;
//    for(i=1; i<=G->n; i++){
//        color[i] = WHITE; // khoi tao mang chua duyet
//    }
//    conflict = 0;
//	colorize(G, 1, BLUE);
//    return conflict;
//}


////  Thu thuat code tay
//void tab(int n){
//	int i;
//	for (i = 1; i<= n; i++){
//		printf("   ");
//	}
//}
//int idx = 1, count = 1;
//void colorize(Graph *G, int u, int c) { //do thi vo huong
//	color[u] = c;
//	idx++;
//	tab(idx); printf("(1) u = %d, c = %d, to mau %d cho dinh %d\n", u, c, c, u);
// 	List list = neightbors(G, u);
//	tab(idx); printf("(2) xet cac dinh ke cua %d\n", u);
//    int i;
//    for (i = 1; i <= list.size; i++){ 
// 		int v = elementAt(&list, i);
//		if (color[v] == WHITE){
//			tab(idx - count +1); printf("v = %d, co mau WHITE, goi de quy duyet %d voi mau !%d = %d\n\n", v, v, c, !c);
//			colorize(G, v, !c); 
//			count++;
//		} 
//		else if (color[v] == c) {
//			tab(idx - count +1); printf("v = %d, co mau %d trung voi mau cua c\n", v, color[v]);
//			tab(idx- count +1); printf("Dung do, conflict = 1\n");
//			tab(idx- count +1); printf("return\n");
//			conflict = 1; //Dung do: 2 dinh ke to cung mau
//			return;
//		}
//		else {
//			tab(idx- count +1); printf("v = %d, co mau %d khac voi c, khong lam gi ca\n", v, color[v]);
//		}
//	}
//}
//
//int checkBipartite(Graph *G){
//    int i;
//    for(i=1; i<=G->n; i++){
//        color[i] = WHITE; // khoi tao mang chua duyet
//    }
//    conflict = 0;
//	colorize(G, 1, BLUE);
//    return conflict;
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
	if (colorize(&G)) printf("Do thi co the phan doi");
	else printf("Do thi khong the phan doi");
	return 0;
}
