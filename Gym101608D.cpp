#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[5006];
int vis[1000006];
int num[1000006];
int d[5005][5005];
int kase;
int main()
{
	freopen("cases.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		++kase;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
		int odd, even;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			even = 0;
			for (int j = i; j <= n; j++) {
				if (vis[a[j]] == i)even--, vis[a[j]] = 0;
				else even++, vis[a[j]] = i;
				if (even == 1)ans++;
			}
		}
		printf("%d\n", ans);
	}
}

