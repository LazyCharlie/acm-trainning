#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
struct node {
	long long x, c, dt;
	bool operator<(const node &rhs)const {
		return x < rhs.x;
	}
}p[maxn];
long long n, v, x, sumc, sumd, cnt;
double d[maxn][maxn][2];
int vis[maxn][maxn][2];
long long cost[maxn][maxn];
double dp(int l, int r, int st)
{
	if (l == 1 && r == n)return 0;
	if (vis[l][r][st] == cnt)return d[l][r][st];
	d[l][r][st] = 1e10;
	vis[l][r][st] = cnt;
	double posx;
	if (st)posx = p[r].x;
	else posx = p[l].x;
	if (l > 1)d[l][r][st] = min(d[l][r][st], dp(l - 1, r, 0) + (posx - p[l - 1].x) / v*cost[l][r]);
	if (r < n)d[l][r][st] = min(d[l][r][st], dp(l, r + 1, 1) + (p[r + 1].x - posx) / v*cost[l][r]);
	return d[l][r][st];
}
int main()
{
	while (scanf("%lld%lld%lld", &n, &v, &x) == 3 && n) {
		++cnt;
		sumc = sumd = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &p[i].x, &p[i].c, &p[i].dt);
			sumd += p[i].dt;
			sumc += p[i].c;
		}
		sort(p + 1, p + n + 1);
		for (int i = 1; i <= n; i++) {
			long long cur = 0;
			for (int j = i; j <= n; j++) {
				cur += p[j].dt;
				cost[i][j] = sumd - cur;
			}
		}
		p[0].x = -1000000000;
		p[n + 1].x = 10000000000;
		double ans = 1e10;
		for (int i = 0; i <= n + 1; i++) {
			if (p[i].x<x&&p[i + 1].x>x) {
				if (i > 0) {
					ans = min(ans, sumc + (x - p[i].x + 0.0) / v*sumd + dp(i, i, 0));
				}
				if (i < n) {
					ans = min(ans, sumc + (p[i + 1].x - x + 0.0) / v*sumd + dp(i + 1, i + 1, 0));
				}
				break;
			}
		}
		printf("%.0f\n", floor(ans));
	}
}
