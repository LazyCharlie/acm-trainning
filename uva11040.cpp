#include<bits/stdc++.h>
using namespace std;
int T;
int a[10][10];
void dfs(int x, int y)
{
	a[x + 2][y + 1] = (a[x][y] - a[x + 2][y] - a[x + 2][y + 2]) / 2;
	a[x + 1][y] = a[x + 2][y] + a[x + 2][y + 1];
	a[x + 1][y + 1] = a[x + 2][y + 1] + a[x + 2][y + 2];
	if (x < 9) {
		dfs(x + 2, y);
		dfs(x + 2, y + 2);
	}
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		for (int i = 1; i <= 9; i += 2) {
			for (int j = 1; j <= i; j += 2) {
				scanf("%d", &a[i][j]);
			}
		}
		dfs(1, 1);
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= i; j++) {
				printf("%d%c", a[i][j], i == j ? '\n' : ' ');
			}
		}
	}
}
