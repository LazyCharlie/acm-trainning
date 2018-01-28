#include<bits/stdc++.h>
using namespace std;
char g[105][105], n, m;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (~scanf("%d%d", &n, &m)) {
		int tot = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", g[i]);
			int flag = 0;
			for (int j = 0; j < m; j++) {
				if (g[i][j] == '.') tot += flag * 2;
				else tot++, flag = 1 ^ flag;
			}
		}
		printf("%d\n", tot / 2);
	}
}

