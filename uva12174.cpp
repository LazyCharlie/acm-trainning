#include<bits/stdc++.h>
using namespace std;
int ok[100006], s[100006], n, m;
int vis[100006];
int main()
{
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		int err = 0;
		for (int i = 0; i < m; i++)scanf("%d", &s[i]);
		for (int i = 0; i <= n; i++)ok[i] = 1, vis[i] = 0;
		for (int i = 0; i < m + n; i++) {
			if (i < m) {
				vis[s[i]]++;
				if (vis[s[i]] == 2)err++;
			}
			if (i >= n) {
				vis[s[i - n]]--;
				if (vis[s[i - n]] == 1)err--;
			}
			if (err) {
				ok[i%n] = 0;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)if (ok[i])ans++;
		printf("%d\n", ans);
	}
}

