#include<bits/stdc++.h>
using namespace std;
int n, r;
double p[25];
int vis[25], cnt;
double dfs(int k, int cur, int b)
{
	if (cur == n) {
		return 1.0;
	}
	double a1 = 0, a2 = 0;
	if (k)a1 = p[cur] * dfs(k - 1, cur + 1, b);
	if (b != cur&&cur + k < n)a2 = (1 - p[cur])*dfs(k, cur + 1, b);
	return a1 + a2;
}
int main()
{
	while (scanf("%d%d", &n, &r) == 2 && n) {
		printf("Case %d:\n", ++cnt);
		for (int i = 0; i < n; i++) {
			scanf("%lf", &p[i]);
		}
		for (int i = 0; i < n; i++) {
			double p1 = dfs(r, 0, i);
			double p2 = dfs(r, 0, -1);
			printf("%.7f\n", p1 / p2);
		}
	}
}
