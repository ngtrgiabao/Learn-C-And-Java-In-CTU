#include<stdio.h>

#define max 100
#define inf 9999
typedef struct{
	int u, v, w; // Hai ??nh c?a m?t c?nh
} edge;
typedef struct{
	edge edges[max]; // Danh sách cung
	int n; // S? ??nh
	int m; // S? cung
} graph;
void init(graph *g, int n){
	g->n = n; // ?? th? có n ??nh
	g->m = 0; // Ch?a thêm cung nào
}
void add(graph *g, int x, int y, int w){
	g->edges[g->m].u = x; 
     // gán 1 ??u
	g->edges[g->m].v = y; 
     // gán 1 ??u
	g->edges[g->m].w = w; 
	g->m++; // like size in list
} 

// combo thuat toan
int pi[max], p[max];
void bellmanFord(graph *g, int s, int e){
	int u, v, w, it, k;
	for (u=1; u<=g->n; u++) pi[u] = inf;
	pi[s] = 0; // di tu dinh s, ve den dinh s -> = 0
	p[s] = -1; // dinh bat dau khong co parent -> = -1
	for (it=1; it<g->n; it++){ // duyet n -1 lan
		for (k = 0; k<g->m; k++){ // k = 0 do cau truc graph-List-edge
			u = g->edges[k].u;
			v = g->edges[k].v;
			w = g->edges[k].w;
			if (pi[u] + w < pi[v]){  // cap nhap lai pi, p cho các ??nh
				pi[v] = pi[u] + w;
				p[v] = u;
			}
			if (pi[v] + w < pi[u]){  // cap nhap lai pi, p cho các ??nh
				pi[u] = pi[v] + w;
				p[u] = v;
			}
		}
	}
	printf("%d\n", pi[e]);
	int t = e, j = 0, i, tree[max];
	while(t != s){
	    tree[j] = t;
	    t = p[t];
	    j++;
	}
	tree[j] = s;
	for (i = j; i >= 0; i--){
	    printf("%d ", tree[i]);
	}
}

int checkCycleNegative(graph *g){  // Ki?m tra chu trình âm
	int k, u, v, w;
	for (k = 0; k<g->m; k++){ 
		u = g->edges[k].u;
		v = g->edges[k].v;
		w = g->edges[k].w;
		if (pi[u] != inf && pi[u] + w < pi[v]){ //Phát hi?n chu trình âm
			return 1;
		}
	}
	return 0;
}

void answer(graph *g){
	int i;
	for (i = 1; i<= g->n; i++){
		printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
	}
}


int main(){
	int n, m, u, v, w, e, s;
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	graph g;
	init(&g, n);
	for (e=1; e<=m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add(&g, u, v, w);
	}
	scanf("%d%d", &s, &e);
	bellmanFord(&g, s, e);
//	answer(&g);
	if (checkCycleNegative(&g)) printf("YES");
	else printf("NO");
	return 0;
}

