#include<bits/stdc++.h>
int T, N, M, K, vis[1006], cnt, a[1000006] = { 1,2,3 };
using std::min;
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &M, &K);
		memset(vis, 0, sizeof(vis));
		for (int i = 3; i < N; i++)a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % M + 1;
		int num = 0, ans = 0x3f3f3f3f, L = 0;
		for (int i = 0; i < N; i++) {
			if (!vis[a[i]] && a[i] <= K)num++;
			vis[a[i]]++;
			while (num == K) {
				ans = min(i - L + 1, ans);
				vis[a[L]]--;
				if (vis[a[L]] == 0 && a[L] <= K)num--;
				L++;
			}
		}
		printf("Case %d: ", ++cnt);
		if (ans > N)printf("sequence nai\n");
		else printf("%d\n", ans);
	}
}
