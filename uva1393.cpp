#include<bits/stdc++.h>
using namespace std;
int n, m;
int vis[305][305], g[305][305];
int res[305][305];
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}
int main()
{
	for (int i = 1; i <= 300; i++) {
		for (int j = 1; j <= 300; j++) {
			g[i][j] = gcd(i, j);
		}
	}
	while (scanf("%d%d", &n, &m) == 2 && n) {
		if (res[n][m]) {
			printf("%d\n", res[n][m]);
			continue;
		}
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= m; b++) {//枚举包围盒大小
				if (g[a][b] > 1)continue;
				res[n][m] += (n - a)*(m - b) - max(n - 2 * a, 0)*max(m - 2 * b, 0);
			}
		}
		res[n][m]*=2;
		printf("%d\n", res[n][m]);
	}
}
