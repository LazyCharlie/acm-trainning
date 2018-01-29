#include<bits/stdc++.h>
using namespace std;
const int N = 305;
int ans[N][N], d[N][N];
int n, m;
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}
void init()
{
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + (gcd(i, j) == 1);//在大小为i,j的长方体中，经过左下角的线有几根
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + d[i][j] - d[i / 2][j / 2];
		}
	}
}
int main()
{
	init();
	while (scanf("%d%d", &n, &m) == 2&&n) {
		printf("%d\n", ans[n-1][m-1] * 2);
	}
}
