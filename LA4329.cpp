#include<bits/stdc++.h>
using namespace std;
int a[100006], n;
int C[100006], L[100006], R[100006];
int lowbit(int x) { return x&-x; }
void add(int x,int d) {
	while (x <= 100005) {
		C[x] += d;
		x += lowbit(x);
	}
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
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(C, 0, sizeof(C));
		for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) {
			L[i] = sum(a[i]-1);
			add(a[i], 1);
		}
		memset(C, 0, sizeof(C));
		for (int i = n; i >= 1; i--) {
			R[i] = sum(a[i]-1);
			add(a[i], 1);
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += L[i] * (n - i - R[i]) + R[i] * (i - 1 - L[i]);
		}
		printf("%lld\n", ans);
	}
}
