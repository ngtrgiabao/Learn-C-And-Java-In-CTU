#include<stdio.h>

#define MAX_N 100 // so dinh max
#define MAX_M 500 // so cung max

// Cai dac bang Mang
typedef struct{
	int data[MAX_N];
	int size;  // so dinh lien thuoc tung dinh
} List; 
typedef struct{
	List adj[MAX_N];
	int n; // so dinh
	int m; // tac dung?
} Graph;

// Cac ham co san cho truoc (remake by me)
void make_null(List *pL){
	pL->size = 0;
}
void push_back(List *pL, int x){
	if (pL->size != MAX_N -1){
		pL->data[pL->size] = x;
		pL->size++;
	}
	else{
		printf("List day khong the them!\n");
	}
}
int element_at(List *pL, int p){
	if (p >= 1 || p <= pL->size +1){
		return pL->data[p -1];
	}
	else{
		printf("Vi tri khong hop le!\n");
	}
	return -1; // truy xuat that bai
}
int size(List *pL){
	return pL->size;
}

// CAC HAM THAO TAC TREN DO THI VO HUONG
// 1. khoi tao do thi
void init_graph(Graph *pG, int n, int m){
	pG->n = n;
	pG->m = m;
	int i;
	for (i=1; i<=n; i++){
		make_null(&pG->adj[i]); // khoi tao mang adj List rong
	}
}
// 2. them cung vao do thi
void add_edge(Graph *pG, int x, int y){
	push_back(&pG->adj[x], y); // them dinh x vao ds adj[y]
	push_back(&pG->adj[y], x); // them dinh y vao ds adj[x]
} 
// 3. tinh bac cua dinh x
int degree(Graph *pG, int x){
	return pG->adj[x].size;
}
// 4. kiem tra dinh x co ke dinh y hay khong?
int adjacent(Graph *pG, int x, int y){
	int i;
	for (i=1; i<=pG->adj[x].size; i++){
		if (pG->adj[x].data[i -1] == y) return 1;
	}
	return 0;
} 
// xac dinh cac dinh ke quanh dinh x
void neighbours(Graph *pG, int x){
	int i;
	for (i=1; i<=pG->adj[x].size; i++){
		printf("%d ", pG->adj[x].data[i -1]);			
	}
	printf("\n");
}

// Cac ham bo tro khac
// 1. in thong tin do thi
void print_graph(Graph G){
	printf("Thong tin do thi:\n");
	printf("So dinh: %d\nSo canh: %d gom: ", G.n, G.m);
	int i, j;
	for (i=1; i<=G.n; i++){
		for (j=1; j<=G.adj[i].size; j++){
			printf("[%d %d]", i, G.adj[i].data[j -1]);
		}
	}
	printf("\nThong tin tung dinh:\n");
	for (i=1; i<=G.n; i++){
		printf("Degree(%d): %d - Neighbours(%d): ", i, degree(&G, i), i);
		neighbours(&G, i);
	}
}



// Cai dac bang Pointer

int main(){
	int n, m, u, v, e, i;
	freopen("graph_data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	Graph G;
	init_graph(&G, n, m);
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

