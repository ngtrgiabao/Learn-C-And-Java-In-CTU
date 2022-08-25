#include<stdio.h>

#define max 100
#define inf 9999
typedef struct{
	int a[max][max];
	int n, m;
} graph;
void init(graph *g , int n, int m){
	int i, j;
	g->n = n; // s? ??nh ??u vào
	g->m = m; // s? cung ??u vào
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			g->a[i][j] = 0;
		}
	}
}
void add(graph *g , int x, int y){ 
	g->a[x][y] = g->a[y][x]  = 1; 
}

// Thuat toan kiem tra lien thong
int mark[max];
void connect(graph *g, int x){
    if (mark[x]) return; 
    mark[x] = 1; // danh dau dinh (hang xom) da duyet
    int i;
    for(i=1; i<=g->n; i++){
        if (g->a[x][i]){ // kiem tra hang xom cua dinh x
            connect(g, i); // goi de quy cho cac dinh hang xom
        }
    }
}

int checkConnect(graph *g){
    int i, check = 1;
    for(i=1; i<=g->n; i++){
        mark[i] = 0;
    }
    connect(g, 1);
    for(i=1;i<=g->n; i++){
        if (!mark[i]){
            check = 0;
            break;
        }
    }
    return check;
}

int main(){
    graph g;
	int n, m, u, v;
 	freopen("data.txt", "r", stdin); // nop bai tren else thi bo dong nay
	scanf("%d%d", &n, &m); 
	init(&g, n, m);
	int i;
	for (i = 1 ; i <= m; i++){
		scanf("%d%d", &u, &v); 
		add(&g, u, v);
	} 
    if (checkConnect(&g)) printf("Do thi lien thong");
    else printf("NO");
    return 0;
}
