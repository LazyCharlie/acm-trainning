#include<bits/stdc++.h>
using namespace std;
vector<int>e[200006];
int n, m, a, b, L[200006], R[200006];
int ans[200006], cnt, vis[200006], use[200006];
void del(int x)
{
	L[R[x]] = L[x];
	R[L[x]] = R[x];
}
void bfs()
{
	while (R[0]) {
		int t = R[0], tot = 1;
		del(t);
		queue<int>q;
		q.push(t);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < e[u].size(); i++)vis[e[u][i]] = 1;
			for (int i = R[0]; i; i = R[i]) {
				if (!vis[i] && !use[i]) {
					use[i] = 1;
					del(i);
					tot++;
					q.push(i);
				}
			}
			for (int i = 0; i < e[u].size(); i++)vis[e[u][i]] = 0;
		}
		ans[cnt++] = tot;
	}
	sort(ans, ans + cnt);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		L[i + 1] = i;
		R[i] = i + 1;
	}
	bfs();
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d%c", ans[i], i + 1 == cnt ? '\n' : ' ');
	}
}
