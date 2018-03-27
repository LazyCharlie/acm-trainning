#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 5;
vector<int>e[maxn];
int n, m, tmp, k, v;
int main()
{
	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 0; i < maxn; i++)e[i].clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &tmp);
			e[tmp].push_back(i);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &k, &v);
			if (k > e[v].size())printf("0\n");
			else printf("%d\n", e[v][k - 1]);
		}
	}
}
