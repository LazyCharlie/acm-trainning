#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100000 + 5;
int C[maxn];
struct frac {
	LL x, v;
	frac(LL xx = 0, LL vv = 0) :x(xx), v(vv) {}
	bool operator<(const frac &rhs)const {
		return x*rhs.v < rhs.x*v;
	}
	bool operator==(const frac &rhs)const {
		return x*rhs.v == rhs.x*v;
	}
}q[maxn];
pair<frac, frac>p[maxn];
int n, w;
LL x[maxn], v[maxn];
int lowbit(long long x)
{
	return x&-x;
}
int sum(int x)
{
	int ret = 0;
	while (x > 0) {
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}
void add(int x) {
	while (x <= n) {
		C[x]++;
		x += lowbit(x);
	}
}
int main()
{
	scanf("%d%d", &n, &w);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &x[i], &v[i]);
		p[i] = make_pair(frac(abs(x[i]), abs(v[i] - w)), frac(abs(x[i]), abs(v[i] + w)));
		q[i] = p[i].second;
	}
	sort(q, q + n);
	sort(p, p + n);
	long long ans = 0;
	int m = unique(q, q + n) - q;
	for (int i = 0; i < n; i++) {
		int pt = lower_bound(q, q + m, p[i].second) - q + 1;
		ans += sum(n - pt + 1);
		add(n - pt + 1);
	}
	printf("%lld\n", ans);
}
