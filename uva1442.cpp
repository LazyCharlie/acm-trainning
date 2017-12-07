#include<bits/stdc++.h>
using namespace std;
int T, n,s[1000006], p[1000006],h[1000006];
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)scanf("%d", &p[i]);
		for (int i = 0; i < n; i++)scanf("%d", &s[i]);
		int level = h[0] = s[0];
		for (int i = 1; i < n; i++) {
			if (level > s[i]) level = s[i];
			if (level < p[i])level = p[i];
			h[i] = level;
		}
		level = s[n - 1];
		int ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (level > s[i]) {
				level = s[i];
			}
			if (level < p[i]) {
				level = p[i];
			}
			ans += min(h[i], level)- p[i];
		}
		printf("%d\n", ans);
	}
}
