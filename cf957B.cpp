#include<bits/stdc++.h>
using namespace std;
int n, m;
char s[105][105];
int col[56], row[56];
int vis[56][56];
vector<int>c, r;
bool solve()
{
	for (int i = 0; i < n; i++) {
		if (!row[i]) {
			c.clear(); r.clear();
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '#')c.push_back(j);
			}
			if (c.size()) {
				for (int j = 0; j < c.size(); j++) {
					for (int k = 0; k < n; k++) {
						if (s[k][c[j]] == '#')r.push_back(k);
					}
				}
			}
			memset(vis, 0, sizeof(vis));
			for (int j = 0; j < r.size(); j++) {
				for (int k = 0; k < c.size(); k++) {
					vis[r[j]][c[k]] = 1;
					if (s[r[j]][c[k]] != '#')return false;
				}
			}
			for (int j = 0; j < r.size(); j++) {
				for (int k = 0; k < m; k++) {
					if (!vis[r[j]][k] && s[r[j]][k] == '#')return false;
					row[r[j]] = 1;
				}
			}
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < c.size(); k++) {
					if (!vis[j][c[k]] && s[j][c[k]] == '#')return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%s", s[i]);
	printf(solve() ? "Yes" : "No");
}
