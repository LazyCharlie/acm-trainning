#include<bits/stdc++.h>
using namespace std;
int h[10] = { 6,2,5,5,4,5,6,3,7,6 };
int d[102][3005];//d[i][j]表示%m余j的i位数至少用多少根火柴
int n, m, kase;
int mod[100] = { 1 };
int ans[100], maxi;
bool dfs(int size, int Mod, int n)
{
	if (size == 0) {
		if (ans[0] == 0)return printf("0\n"), 1;
		for (int i = 0; i < maxi; i++) {
			printf("%d", ans[i]);
		}
		printf("\n");
		return true;
	}
	for (int i = 9; i >= 0; i--) {
		ans[maxi - size] = i;
		int M = mod[size - 1] * i%m;
		int r = (Mod - M + m) % m;
		if (d[size - 1][r] + h[i] <= n && dfs(size - 1, r, n - h[i])) {
			return true;
		}
	}
	return false;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d", &n) == 1 && n) {
		printf("Case %d: ", ++kase);
		scanf("%d", &m);
		memset(d, 0x3f, sizeof(d));
		d[0][0] = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < m; j++) {
				if (d[i][j] == 0x3f3f3f3f)continue;
				for (int k = 0; k < 10; k++) {
					if (d[i + 1][(j * 10 + k) % m] > d[i][j] + h[k]) {
						d[i + 1][(j * 10 + k) % m] = d[i][j] + h[k];
					}
				}
			}
		}
		for (int i = 1; i <= n / 2; i++) {
			mod[i] = mod[i - 1] * 10 % m;
		}
		maxi = -1;
		for (int i = n / 2; i >= 0; i--) {
			if (d[i][0] <= n) {
				maxi = i;
				break;
			}
		}
		if (maxi == 0)printf("-1\n");
		else dfs(maxi, 0, n);
	}
}
