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
    G->a[x][y] = G->a[y][x] = 1;
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

// Khai bao cau truc Queue (Mang Vong)
typedef struct {
	int a[MAX];
	int front, rear; // Front: Dau hang | Rear: Cuoi hang
} Queue;

void makenullQueue(Queue *Q){
	Q->front = -1;
	Q->rear = -1;
}
int emptyQueue(Queue *Q){
	return Q->front == -1;
}
int topQueue(Queue *Q){
	return Q->a[Q->front];
}
void popQueue(Queue *Q){
	if (Q->front == Q->rear){
		makenullQueue(Q);
	}
	else{
		Q->front = (Q->front+1) % MAX;
	}
}
void pushQueue(Queue *Q, int x){
	if (Q->front == -1){
		Q->front=0;
	}
	Q->rear = (Q->rear +1) % MAX; 
	Q->a[Q->rear] = x;
} 

// THuat toan duyet rong
int mark[MAX];
int parent[MAX];
// Ham nay gom x, và parent, khi can co the chinh sua de phu hop voi yeu cau cua bai
void breatFirstSearch(Graph G, int x, int parent[]) {
	Queue Q;
	makenullQueue(&Q);
	pushQueue(&Q, x);
	parent[x] = 0;
	int connected[MAX], i;
	for (i = 1; i <= G.n; i++){
		connected[i] = 0;
	}
	printf("Duyet %d\n", x);
	connected[x] = 1;
	while (!emptyQueue(&Q)){
		int u = topQueue(&Q); popQueue(&Q);
		List L = neightbors(&G, u);
		for (i = 1; i <= L.size; i++){ 
			int v = elementAt(&L, i);
			if (!connected[v]) {
				printf("Duyet %d\n", v);
				pushQueue(&Q, v);
				connected[v] = 1; // danh dau dinh trong BPLT da duoc duyet
				mark[v] = 1; // danh dau dinh trong do thi da duoc duyet
				parent[v] = u;
			}
		}	
	}
}

int main(){
    Graph G;
	int n, m, u, v;
 	freopen("graph_data.txt", "r", stdin); // nop bai tren else thi bo dong nay
	scanf("%d%d", &n, &m); 
	init(&G, n, m);
	int i;
	for (i = 1 ; i <= m; i++){
		scanf("%d%d", &u, &v); 
		add(&G, u, v);
	} 
	for (i = 1; i <= G.n; i++){ 
		mark[i] = 0;
		parent[i] = -1;
	}
	for (i = 1; i <= n; i++){ 
		if (!mark[i]){
			breatFirstSearch(G, i, parent);
		}
	}
	for (i = 1; i <= n; i++){ 
		printf("%d %d\n", i, parent[i]);
	}
    return 0;
}




