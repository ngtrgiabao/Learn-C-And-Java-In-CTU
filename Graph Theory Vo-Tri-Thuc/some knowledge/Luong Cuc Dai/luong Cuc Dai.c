#include <stdio.h>

#define max 100
#define inf 9999999
// queue
typedef struct {
	int data[max]; 
	int front, rear; 
} queue;
void makenullQueue(queue *q){
	q->front = 0;
	q->rear = -1;
}
int emptyQueue(queue *q){
	return (q->front > q->rear);
}
int topQueue(queue *q){
	return q->data[q->front];
}
void popQueue(queue *q){
	q->front++;
}
void pushQueue(queue *q, int x){
	q->rear++;
	q->data[q->rear] = x;
}

// graph
typedef struct {
	int c[max][max];
	int f[max][max];
	int n, m;
} graph;
void init(graph* g, int n) {
	g->n = n;
	g->m = 0;
}

// combo thuat toan
typedef struct {
	int dir;
	int pre;
	int sigma;
}label;

label labels[max];
int marks[max];

void initFlow(graph* g){ 
	int i, j;
	for (i = 1; i <= g->n; ++i) {
		for (j = 1; j <= g->n; ++j) {
			g->f[i][j] = 0;
		}
	}
}

int smaller(int a, int b) {
	return (a<=b) ? a : b;
}

int ford(graph *g, int s, int t) {
	initFlow(g);
	queue q;
	int u, v, sumFlow = 0;
	while(1) {
		for (u = 1; u <= g->n; u++) labels[u].dir = 0; // Khoi tao nhanh cho lat cat
		labels[s].dir = 1;
		labels[s].pre = s;
		labels[s].sigma = inf;
		makenullQueue(&q);
		pushQueue(&q, s);
		int found = 0;
		while (!emptyQueue(&q)) {
			u = topQueue(&q);
			popQueue(&q);
			for (v = 1; v <= g->n; v++) {
				if (!labels[v].dir && g->c[u][v] && g->f[u][v] < g->c[u][v]) {
					labels[v].dir = 1;
					labels[v].pre = u;
					labels[v].sigma = smaller(labels[u].sigma, g->c[u][v] - g->f[u][v]);
					pushQueue(&q, v);
				}
				if (!labels[v].dir && g->c[v][u] && g->f[v][u] > 0) {
					labels[v].dir = -1;
					labels[v].pre = u;
					labels[v].sigma = smaller(labels[u].sigma, g->f[u][v]);
					pushQueue(&q, v);
				}
			}
			if (labels[t].dir) {
				found = 1;
				break;
			}
		}
		if (found) {
			int x = t;
			int sigma = labels[t].sigma;
			sumFlow += sigma;
			while (x != s) {
				u = labels[x].pre;
				if (labels[x].dir > 0) g->f[u][x] += sigma;
				else g->f[x][u] -= sigma;
				x = u;
			}
		} else break;
	}
	return sumFlow;
}

int main() {
	graph g;
	int n, m, u, v, i, c;
	freopen("data.txt", "r", stdin); // nop bai tren else bo dong nay
	scanf("%d %d", &n, &m);
	init(&g, n);
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &c);
		g.c[u][v] = c;
	}
	int maxFlow = ford(&g, 1, n);
	printf("Max Flow: %d\n", maxFlow);
	printf("X0: "); //Tap S lat cat
	for (i = 1; i <= n; i++) {
		if (labels[i].dir) printf("%d ", i);
	}
	printf("\nY0: "); //Tap t lat cat
	for (i = 1; i <= n; i++) {
		if (!labels[i].dir) printf("%d ", i);
	}
	return 0;
}
