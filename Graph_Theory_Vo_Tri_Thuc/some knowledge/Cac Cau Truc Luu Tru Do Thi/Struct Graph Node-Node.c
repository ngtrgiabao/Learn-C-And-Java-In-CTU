#include<stdio.h>

#define MAX_N 100 // so cung max

typedef struct{
	int A[MAX_N][MAX_N]; // ma tran dinh dinh 2 chieu
	int n; // so dinh
	int m; // co the khong can vi tu ma tran A co the suy ra duoc so cung (them cho tien truy suat)
} Graph;

// CAC HAM THAO TAC TREN DO THI VO HUONG
// 1. khoi tao do thi
void init_graph(Graph *pG, int n){
	int i, j;
	pG->n = n;
	for (i=1; i<=n; i++){
		for (j=1; j<=n; j++){
			pG->A[i][j] = 0;
		}
	}
}
// 2. them cung vao do thi
void add_edge(Graph *pG, int x, int y){
	pG->A[x][y] = 1;
	pG->A[y][x] = 1;
} 
// 3. tinh bac cua dinh x
int degree(Graph *pG, int x){
	int i, deg = 0;
	for (i=1; i<=pG->n; i++){
		if (pG->A[i][x] == 1) deg++;
	}
	return deg;
}
// 4. kiem tra dinh x co ke dinh y hay khong?
int adjacent(Graph *pG, int x, int y){
	return pG->A[x][y] == 1; // <=> return pG->A[y][x] == 1;
} 
// xac dinh cac dinh ke quanh dinh x
void neighbours(Graph *pG, int x){
	int i;
	for (i=1; i<=pG->n; i++){
		// <=> if (pG->A[x][i] == 1){}
		if (adjacent(pG, x, i)){ 
			printf("%d ", i);			
		} 
	}
	printf("\n");
}

// Cac ham bo tro khac
// 1. in thong tin do thi
void print_graph(Graph G){
	printf("Thong tin do thi:\nMa tran Dinh-Dinh\n");
	int i, j;
	for (i=1; i<=G.n; i++){
		for (j=1; j<=G.n; j++){
			printf("%d ", G.A[i][j]);	
		}
		printf("\n");
	}
	printf("So dinh: %d\nSo canh: %d gom: ", G.n, G.m);
	for (i=1; i<=G.n; i++){
		for (j=1; j<=i; j++){
			// do khi them vao ma tran doi xung nen chi can kiem tra 1/2 ma tran
			if (G.A[i][j] == 1){ 
				printf("[%d %d] ", j, i);	
			}
		}
	}
	printf("\nThong tin tung dinh:\n");
	for (i=1; i<=G.n; i++){
		printf("Degree(%d): %d - Neighbours(%d): ", i, degree(&G, i), i);
		neighbours(&G, i);
		// Nhan xet: co ve neighbours da duoc sort!
	}
}

int main(){
	int n, m, u, v, e, i, j;
	freopen("graph_data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (e=1; e<=m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	print_graph(G);
	printf("Kiem tra cac dinh ke dinh 4:\n");
	for (i=1; i<=G.n; i++){	
		// adjacent(&G, i, 4) <=> adjacent(&G, 4, i)
		if (adjacent(&G, i, 4)) printf("4 ke %d\n", i);
		else printf("4 khong ke %d\n", i);
	}
	return 0;
}

