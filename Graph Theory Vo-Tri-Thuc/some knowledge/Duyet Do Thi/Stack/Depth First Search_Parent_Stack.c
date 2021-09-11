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

void add(Graph *G, int x, int y){ // them mot cung
	G->a[x][y] = G->a[y][x] = 1; 
}

int adjacent(Graph *G, int x, int y){ // kiem tra co phai lang gieng khong
	return G->a[x][y] == 1;
}

int degree(Graph *G, int x){ // tinh bac cua dinh x
	int i, deg = 0;
	for (i = 1; i <= G->n; i++){
		if (G->a[i][x] == 1) deg++;
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
		if (G->a[i][x] == 1){
			push(&L, i);
		}
	}
	return L;
}
/*
	Ham nay bao gom parent: phuc vu ve cay do thi
			duyet tu dinh x bac ki: phong th do thi khong lien thong
	-> Neu chi duyet thi chinh sua lai
*/
int mark[MAX], parent[MAX];
void depthFirstSearch(Graph G, int x, int parent[]){ 
	List S;
	makeNull(&S);
	push(&S, x); // them dinh x vao Stack
	parent[x] = 0; // neu khong co parent thi cho parent = 0
	int connected[MAX], i;
	for (i = 1; i <= G.n; i++){ 
		connected[i] = 0; // danh dau dinh chua duyet
	}
	while (!empty(&S)){
		int u = top(&S);
		pop(&S);
		if (connected[u]) continue;
		printf("Duyet %d\n", u); // thu tu duyet
		connected[u] = 1;// dinh trong bo phan lien thong da duoc duyet
		mark[u] = 1; // dinh trong do thi da duoc duyet
		List L = neightbors(&G, u);
		for (i = 1; i <= L.size; i++){ 
			int v = elementAt(&L, i);
			if (!connected[v]) {
				push(&S, v);
				parent[v] = u;
			}
		}	
	}
}

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
	for (i = 1; i <= n; i++){ // khoi tao mang
		mark[i] = 0; // mang chua dinh da duoc duyet trong toan do thi
		parent[i] = -1; // mang chua parent cua tung dinh
	}
	for (i = 1; i <= n; i++){ 
		if (!mark[i]){ // neu dinh chua duoc duyet thi duyet dinh do
			depthFirstSearch(G, i, parent);
		}
	}
	for (i = 1; i <= n; i++){ 
		printf("%d %d\n", i, parent[i]); // in node child - parent
	}
	return 0;
}
