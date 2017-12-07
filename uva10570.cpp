#include<bits/stdc++.h>
using namespace std;
int n, a[506], b[506], ans;
void solve()
{
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		memcpy(a, b, sizeof(b));
		for (int j = 0; j < n; j++) {
			while (a[j] != (i + j - 1) % n + 1) {
				swap(a[j], a[(a[j] - i + n) % n]);
				cnt++;
			}
		}
		ans = min(ans, cnt);
	}
}
int main()
{
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++)scanf("%d", &b[i]);
		ans = 0x3f3f3f3f;
		solve();
		reverse(b, b + n);
		solve();
		printf("%d\n", ans);
	}
}
