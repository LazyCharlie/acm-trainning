#include<bits/stdc++.h>
using namespace std;
int n, q;
int a[100006];
int L[100006], R[100006], num[100006];
int d[100006][40];
int cnt = 0;
void init_RMQ()
{
	for (int i = 0; i < cnt; i++)d[i][0] = num[i];
	for (int j = 1; (1 << j) <= cnt; j++) {
		for (int i = 0; i + (1 << j) - 1 < cnt; i++) {
			d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int RMQ(int L, int R) {
	int len = 0;
	while (1 << (len + 1) <= R - L + 1)len++;
	return max(d[L][len], d[R - (1 << len) + 1][len]);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d", &n) == 1 && n) {
		scanf("%d", &q);
		cnt = 0;
		for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) {
			L[cnt] = i, num[cnt] = 1;
			while (a[i + 1] == a[i] && i + 1 <= n)i++, num[cnt]++;
			//num[cnt] = a[i];
			R[cnt++] = i;
		}
		init_RMQ();
		while (q--) {
			int a, b;
			scanf("%d%d", &a, &b);
			int pL = upper_bound(L, L + cnt, a) - L - 1;
			int pR = lower_bound(R, R + cnt, b) - R;
			int ans;
			if (pL == pR)ans = b - a + 1;
			else ans = max(R[pL] - a + 1, b - L[pR] + 1);
			if (pL + 1 <= pR - 1)ans = max(ans, RMQ(pL + 1, pR - 1));
			printf("%d\n", ans);
		}
	}
}
