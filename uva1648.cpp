#include<bits/stdc++.h>
using namespace std;
int n, m;
int u, d;
int ans;
int main()
{
	while (scanf("%d%d", &n, &m) == 2 && n) {
		ans = 0x3f3f3f3f;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u, &d);
			int x = (n*d / (u + d)) + 1;
			ans = min(ans, x*(u + d) - n*d);
		}
		printf("%d\n", ans);
	}
}
