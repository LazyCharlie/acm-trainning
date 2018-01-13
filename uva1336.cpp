#include<bits/stdc++.h>
using namespace std;
struct bad {
	long long x, c, d;
	bool operator<(const bad&a)const {
		return x < a.x;
	}
	bad(long long x = 0) :x(x) {}
}p[1005];
double d[1005][1005][2];
long long cost[1005][1005];
long long n, v, pos, sum, tot;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%lld%lld%lld", &n, &v, &pos) == 3 && n) {
		sum = tot = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld%lld%lld", &p[i].x, &p[i].c, &p[i].d);
			sum += p[i].d;
			tot += p[i].c;
		}
		sort(p, p + n);
		long long cur;
		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)d[i][j][0] = d[i][j][1] = 1e10;
		for (int i = 0; i < n; i++) {
			cur = 0;
			for (int j = i; j < n; j++) {
				cur += p[j].d;
				cost[i][j] = sum - cur;
			}
		}
		int pt = lower_bound(p, p + n, bad(pos)) - p - 1;
		if (pt < 0) {
			d[0][0][0] = d[0][0][1] = 1.0*(p[0].x - pos) / v*sum;
		}
		else if (pt == n - 1) {
			d[n - 1][n - 1][0] = d[n - 1][n - 1][1] = 1.0*(pos - p[n - 1].x) / v*sum;
		}
		else {
			d[pt][pt][0] = d[pt][pt][1] = 1.0*(pos - p[pt].x) / v*sum;
			d[pt + 1][pt + 1][0] = d[pt + 1][pt + 1][0] = 1.0*(p[pt + 1].x - pos) / v*sum;
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (j < n - 1)d[i][j + 1][1] = min(d[i][j][0] + 1.0*(p[j + 1].x - p[i].x) / v*cost[i][j], d[i][j + 1][1]);
				if (i)d[i - 1][j][0] = min(d[i - 1][j][0], d[i][j][0] + 1.0*(p[i].x - p[i - 1].x) / v*cost[i][j]);
				if (j < n - 1)d[i][j + 1][1] = min(d[i][j][1] + 1.0*(p[j + 1].x - p[j].x) / v*cost[i][j], d[i][j + 1][1]);
				if (i)d[i - 1][j][0] = min(d[i - 1][j][0], d[i][j][1] + 1.0*(p[j].x - p[i - 1].x) / v*cost[i][j]);
			}
		}
		printf("%lld\n", (long long)min(d[0][n - 1][0], d[0][n - 1][1]) + tot);
	}
}
