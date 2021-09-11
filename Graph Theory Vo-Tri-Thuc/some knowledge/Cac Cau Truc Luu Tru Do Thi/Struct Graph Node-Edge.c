#include<stdio.h>

#define MAX_N 100
#define MAX_M 500

typedef struct{
	int A[MAX_N][MAX_M]; // ma tran dinh-cung 2 chieu
	int n; // so dinh
	int m; // so cung
} Graph;

// CAC HAM THAO TAC TREN DO THI VO HUONG
// 1. khoi tao do thi
void init_graph(Graph *pG, int n, int m){
	int i, j;
	pG->n = n;
	pG->m = m;
	for (i=1; i<=n; i++){
		for (j=1; j<=m; j++){
			pG->A[i][j] = 0;
		}
	}
}
// 2. them cung vao do thi
void add_edge(Graph *pG, int e, int x, int y){
	pG->A[x][e] = 1;
	pG->A[y][e] = 1;
} 
// 3. tinh bac cua dinh x
int degree(Graph *pG, int x){
	int i, deg = 0;
	for (i=1; i<=pG->m; i++){
		if (pG->A[x][i] == 1) deg++; // deg = tong so 1 tren hang x
	}
	return deg;
}
// 4. kiem tra dinh x co ke dinh y hay khong?
int adjacent(Graph *pG, int x, int y){
	int i;
	for (i=1; i<=pG->m; i++){
		// tren tung cot, neu dong thoi x = y = 1 thi hai cung lien ke
		if (pG->A[x][i] == 1 && pG->A[y][i] == 1) return 1; 
	}
	return 0;
} 
// xac dinh cac dinh ke quanh dinh x
void neighbours(Graph *pG, int x){
	int i;
	for (i=1; i<=pG->n; i++){
		// x != i do A[x][x] co gia tri = 1
		if (adjacent(pG, x, i) && x != i){ 
			printf("%d ", i);			
		} 
	}
	printf("\n");
}

// Cac ham bo tro khac
// 1. in thong tin do thi
void print_graph(Graph G){
	printf("Thong tin do thi:\nMa tran Dinh-Cung\n");
	int i, j;
	for (i=1; i<=G.n; i++){
		for (j=1; j<=G.m; j++){
			printf("%d ", G.A[i][j]);	
		}
		printf("\n");
	}
	printf("So dinh: %d\nSo canh: %d gom: ", G.n, G.m);
	int e, check;
	for (e=1; e<=G.m; e++){
		check = 0;
		printf("[");
		for (i=1; i<=G.n; i++){
			if (G.A[i][e] == 1){ 
				printf("%d ",i);
				check++;
			}
			if (check == 2) break; // moi dong chi co 2 so 1, in du thi break
		}
		printf("] ");
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
	init_graph(&G, n, m);
	for (e=1; e<=m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, e, u, v);
	}
	print_graph(G);
	printf("Kiem tra cac dinh ke dinh 4:\n");
	for (i=1; i<=G.n; i++){	
		if (i == 4) {
			printf("4 khong ke %d\n", i);	
			continue;
		} 
		// adjacent(&G, i, 4) <=> adjacent(&G, 4, i)
		if (adjacent(&G, i, 4)) printf("4 ke %d\n", i);
		else printf("4 khong ke %d\n", i);
	}
	return 0;
}

