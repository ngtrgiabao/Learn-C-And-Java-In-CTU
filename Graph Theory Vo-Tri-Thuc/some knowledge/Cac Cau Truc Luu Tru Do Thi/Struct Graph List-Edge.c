#include<stdio.h>

#define MAX_M 500 // so cung max

typedef struct{
	int u, v; // hai dinh cua 1 canh bac ki
} Edge;
typedef struct{
	Edge edges[MAX_M];
	int n; // so dinh
	int m; // so cung
} Graph;

// CAC HAM THAO TAC TREN DO THI VO HUONG
// 1. khoi tao do thi
void init_graph(Graph *pG, int n){
	pG->n = n; // do thi co n dinh
	pG->m = 0; // hien tai chua co dinh nao
}
// 2. them cung vao do thi
void add_edge(Graph *pG, int x, int y){
	pG->edges[pG->m].u = x; // gan gia tri cho cung
	pG->edges[pG->m].v = y; // gan gia tri cho cung
	pG->m++; // cho m bac dau tu 1 cho tien thao tac
} 
// 3. tinh bac cua dinh x
int degree(Graph *pG, int x){
	int i, deg = 0;
	for (i=0; i<pG->m; i++){
		if (pG->edges[i].u==x || pG->edges[i].v==x){ // u || v == x thi co edge tro den x
			deg++;
		}
	}
	return deg;
}
// 4. kiem tra dinh x co ke dinh y hay khong?
int adjacent(Graph *pG, int x, int y){
	int i;
	for (i=0; i<pG->m; i++){
		Edge temp = pG->edges[i]; // luu bien lai cho de nhin
		if ((temp.u==x && temp.v==y) || (temp.u==y && temp.v==x)){
			return 1;
		}
	}
	return 0;
} 
// xac dinh cac dinh ke quanh dinh x
void neighbours(Graph *pG, int x){
	int i;
	for (i=0; i<pG->m; i++){
		// neu cung nao chua 1 dau la x thi dau con lai chinh la neightbours cua no
		if (pG->edges[i].u == x){ 
			printf("%d ", pG->edges[i].v);			
		} 
		else if (pG->edges[i].v == x){ 
			printf("%d ", pG->edges[i].u);			
		}
	}
	printf("\n");
}

// Cac ham bo tro khac
// 1. in thong tin do thi
void print_graph(Graph G){
	printf("Thong tin do thi:\n");
	printf("So dinh: %d\nSo canh: %d gom: ", G.n, G.m);
	int i;
	for (i=0; i<G.m; i++){
		printf("[%d %d] ", G.edges[i].u, G.edges[i].v);
	}
	printf("\nThong tin tung dinh:\n");
	for (i=0; i<G.n; i++){
		printf("Degree(%d): %d - Neighbours(%d): ", i +1, degree(&G, i+1), i +1);
		neighbours(&G, i+1);
	}
}

int main(){
	int n, m, u, v, e, i;
	freopen("graph_data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (e=0; e<m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	print_graph(G);
	printf("Kiem tra cac dinh ke dinh 4:\n");
	for (i=0; i<G.n; i++){	
		// adjacent(&G, i, 4) <=> adjacent(&G, 4, i)
		if (adjacent(&G, i +1, 4)) printf("4 ke %d\n", i +1);
		else printf("4 khong ke %d\n", i +1);
	}
	return 0;
}

