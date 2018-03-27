#include<bits/stdc++.h>
using namespace std;
int n, T;
long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}
struct frac {
	long long m, s;
	frac(long long mom = 1, long long son = 0) {
		m = mom;
		s = son;
	}
	frac operator*(const frac &a)const {
		frac ret = a;
		ret.m *= this->m;
		ret.s *= this->s;
		long long g = max(abs(gcd(ret.m, ret.s)), 1LL);
		ret.m /= g;
		ret.s /= g;
		return ret;
	}
	frac operator+(const frac &a)const {
		frac ret = frac(1, 0);
		long long b = gcd(a.m, this->m);
		ret.m = a.m / b*(this->m);
		ret.s = a.m / b*(this->s) + this->m / b*a.s;
		long long g = max(abs(gcd(ret.m, ret.s)), 1LL);
		ret.m /= g;
		ret.s /= g;
		return ret;
	}
}B[25],ans[25];
long long C(long long a, long long b)
{
	long long ret = 1;
	for (int i = 1; i <= b; i++) {
		ret = ret*(a - i + 1) / i;
	}
	return ret;
}
void init()
{
	B[0] = frac(1, 1);
	for (int i = 1; i < 25; i++) {
		B[i] = frac(1, 0);
		for (int j = 0; j < i; j++) {
			B[i] = B[i] + B[j] * frac(1, C(i + 1, j));
		}
		B[i] = B[i] * frac(i + 1, -1);
	}
	B[1].s = 1;
}
void solve()
{
	for (int i = 0; i <= n + 1; i++)ans[i] = frac(1, 0);
	frac p = frac(n + 1, 1);
	for (int i = 0; i <= n; i++) {
		ans[n + 1 - i] = frac(1, C(n + 1, i))*B[i]*p;
	}
	long long g = 1;
	for (int i = 1; i <= n + 1; i++) {
		g *= ans[i].m / gcd(g, ans[i].m);
	}
	printf("%lld", g);
	for (int i = n + 1; i > 0; i--) {
		printf(" %lld", ans[i].s*g / ans[i].m);
	}
	printf(" 0\n");
	if (T)printf("\n");
}
int main()
{
	init();
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		solve();
	}
}
