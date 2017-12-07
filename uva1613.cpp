#include<bits/stdc++.h>
using namespace std;
int n, m, u, v;
vector<int>e[10000];
int c[10000];
int vis[10000];
int vis2[10000];
int k;
void bfs(int p)
{
	queue<int>q;
	q.push(p);
	while (q.size()) {
		int v = q.front(); q.pop();
		for (int i = 1; i <= k; i++)vis[i] = 0;
		for (int i = 0; i < e[v].size(); i++) {
			int u = e[v][i];
			if (c[u])vis[c[u]] = 1;
			else if (!vis2[u])q.push(u), vis2[u] = 1;
		}
		for (int i = 1; i <= k; i++) {
			if (!vis[i]) {
				c[v] = i;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)printf("%d\n", c[i]);
	printf("\n");
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d%d", &n, &m) == 2) {
		k = 0;
		memset(c, 0, sizeof(c));
		memset(vis2, 0, sizeof(vis2));
		for (int i = 1; i <= n; i++)e[i].clear();
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
			k = max(k, (int)e[u].size());
			k = max(k, (int)e[v].size());
		}
		k = k / 2 * 2 + 1;
		printf("%d\n", k);
		bfs(1);
	}
}
