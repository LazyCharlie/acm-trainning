#include<bits/stdc++.h>
using namespace std;
struct edge {
	int x, y, w;
	edge(int xx = 0, int yy = 0, int ww = 0) {
		x = xx;
		y = yy;
		w = ww;
	}
	bool operator<(const edge &a)const {
		return w < a.w;
	}
};
vector<edge>e;
vector<int>W;
int u, v, w;
int p[105], cnt;
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m;
	while (scanf("%d%d", &n, &m) == 2 && n) {
		e.clear();
		W.clear();
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			e.push_back(edge(u, v, w));
		}
		sort(e.begin(), e.end());
		for (int i = 0; i < m; i++)if (!W.size() || e[W.back()].w != e[i].w)W.push_back(i);
		int ans = 0x3f3f3f3f;
		for (int i = 0; i < W.size(); i++) {
			cnt = n;
			for (int j = 1; j <= n; j++)p[j] = j;
			int cur = W[i];
			while (cnt > 1 && cur < m) {
				int fa = find(e[cur].x);
				int fb = find(e[cur].y);
				if (fa != fb) {
					p[fa] = fb;
					cnt--;
				}
				if (cnt == 1) {
					ans = min(ans, e[cur].w - e[W[i]].w);
				}
				cur++;
			}
		}
		if (ans == 0x3f3f3f3f)ans = -1;
		printf("%d\n", ans);
	}
}
