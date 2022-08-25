#include<stdio.h>

#define max 100
#define inf 9999
typedef struct{
	int a[max][max];
	int n, m;
} graph;
void init(graph *g, int n, int m){
	int i, j;
	g->n = n; // s? ??nh ??u vào
	g->m = m; // s? cung ??u vào
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			g->a[i][j] = 0;
		}
	}
}
void add(graph *g , int x, int y, int w){ 
	g->a[x][y] = g->a[y][x] = w; // vo huong trong so
}

// Combo thuat toan

int mark[max], pi[max], p[max];
void moore(graph *g, int s){
	int u, v, i;
	for (u=1; u<=g->n; u++){ // Kh?i t?o các m?ng
		pi[u] = inf; 
		mark[u] = 0;
	}
	pi[s] = 0; // di tu dinh s, ve den dinh s -> = 0
	p[s] = -1; // dinh bat dau khong co parent -> = -1
	for (i=1; i<g->n; i++){ // Duy?t n - 1 lan
		int j, min_pi = inf;
		for (j=1; j<=g->n; j++){ 
          // Tìm ??nh ch?a duy?t có giá tr? min_pi
			if (!mark[j] && pi[j] < min_pi){ 
				min_pi = pi[j];
				u = j;
			}
		}
		mark[u] = 1; // ?ánh d?u ?ã duy?t xong ??nh ?ó
		for (v = 1; v<=g->n; v++){	
            if (g->a[u][v] && !mark[v]){ 
				if (pi[u] + g->a[u][v] < pi[v]){
                         // cap nhap lai pi va p cho tung dinh
					pi[v] = pi[u] + g->a[u][v];
					p[v] = u;
				}
			}
		}
	}
}
void answer(graph *g){
	int i;
	for (i = 1; i<=g->n; i++){
		printf("Dinh: %d - parent: %d - Chi phi: %d\n", i, p[i], pi[i]);
	}
}
int t = 0, k[max];
void parent(graph *g, int x){
	t++;
	if (p[x] == -1){
		k[t] = x;
		return;
	}
	else{
		k[t] = x;
		parent(g, p[x]);
	}
}

int main(){
	graph g;
	int n, m, u, v, w, e;
 	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init(&g, n, m);
	for (e=1; e<=m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add(&g, u, v, w);
	}
	int start, end;
	scanf("%d %d", &start, &end);
	moore(&g, start);
	int check = 1;
	for (e = 1; e<=n; e++){
		if (pi[e] == inf) { // Kiem tra lien thong
		    check = 0;
		    break;
		}
	}
	if (check){
		int i;
	    printf("%d \n", pi[end]);
	    parent(&g, end);
	    for (i = t; i >= 1; i--) printf("%d ", k[i]);
	}  
	else printf("-1"); // khong lien thong
	return 0;
}





