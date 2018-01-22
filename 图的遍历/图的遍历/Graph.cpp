#include<iostream>
#define MAX_VERTEX_NUM 10
int visited[MAX_VERTEX_NUM] = { 0,0,0,0,0,0,0,0,0,0 };
using namespace std;
typedef struct edgenode {
	int adjvex;
	float weight;
	struct edgenode *next;
}*edgeptr;
typedef struct {
	int vertex;
	edgeptr link;
}vexnode;
typedef vexnode Adj_List[MAX_VERTEX_NUM];
void build_adjlist(Adj_List ga) {
	int n,e;
	cout << "请输入顶点数：" << endl;
	cin >> n;
	cout << "请输入边数：" << endl;
	cin >> e;
	for (int i = 0; i < n; i++) {
		ga[i].vertex = i;
		ga[i].link = NULL;
	}
	for (int i = 0; i <e; i++) {
		cout << "请输入顶点对：" << endl;
		int j, k;
		cin >> j >> k;
		edgeptr p = new edgenode;
		edgeptr q = new edgenode;
		p->adjvex = k;
		q->adjvex = j;
		p->next = ga[j].link;
		q->next = ga[k].link;
		ga[j].link = p;
		ga[n].link = q;
	}
}
void dfs(Adj_List g, int v0) {
	cout << v0 << "  ";
	visited[v0] = 1;
	edgeptr p;
	p = g[v0].link;
	while (p != NULL) {
		if (visited[p->adjvex] == 0) {
			dfs(g, p->adjvex);
		}
		p = p->next;
	}
}
void dfs2(Adj_List g, int n) {
	
	//visited[v0] = 1;
	edgeptr p;
	
	for (int i = 0; i < n;i++) {
		p = g[i].link;
		cout << p->adjvex << "  ";
		while (p != NULL) {
		//if (visited[p->adjvex] == 0) {
		//	dfs(g, p->adjvex);
		//}
		cout << p->adjvex<<"";
		p = p->next;
		}
		cout << endl;
	}
	
}
int count_component(Adj_List g, int n) {
	int count,v;
	for ( v = 0; v < n; v++) {
		visited[v] = 0;
	}
	count = 0;
	for (v = 0; v < n; v++) {
		if (visited[v] == 0) {
			count++;
			dfs(g, v);
		}
	}
	return count;
}
void bfs(Adj_List g,int v0) {
	int q[10];
	int visited[10] = { 0,0,0,0,0,0,0,0,0,0 };
	visited[v0] = 1;
	cout << v0<<"  ";
	int f = 0, r = 0,v;
	edgeptr p;
	p = g[v0].link;
	do {
		while(p!=NULL){
			v = p->adjvex;
			if (visited[v] == 0) {
				r++;
				q[r] = v;
				cout << v << "  ";
				visited[v] = 1;
			}
			p = p->next;
		}
		if (f != r) {
			f++;
			v = q[f];
			p = g[v].link;
		}
	} while ((p != NULL) || (f != r));
}
void main(){
	Adj_List ga;
	build_adjlist(ga);
	cout << "深度优先算法：" << endl;
	//count_component(ga, 6);
	dfs2(ga, 6);
	cout << endl;
	cout << "广度优先算法：" << endl;
	bfs(ga, 1);
	system("pause");
}