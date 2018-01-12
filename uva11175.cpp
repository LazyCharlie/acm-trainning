#include<bits/stdc++.h>
using namespace std;
int T, cnt, n, m, a, b;
vector<int>e[400], ce[400];
bool check()
{
	for (int i = 0; i < n; i++) {
		int rb = -1;
		for (int j = 0; j < e[i].size(); j++) {
			int u = e[i][j];
			if (rb < 0 || ce[u].size() == rb)rb = ce[u].size();
			else return false;
		}
	}
	return true;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++cnt);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)e[i].clear(), ce[i].clear();
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			e[a].push_back(b);
			ce[b].push_back(a);
		}
		printf(check() ? "Yes\n" : "No\n");
	}
}
