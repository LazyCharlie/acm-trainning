#include<bits/stdc++.h>
using namespace std;
int n, D, p, L, v;
int kase;
int main()
{
	while (scanf("%d%d", &n, &D) == 2 && D) {
		double ans = D;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &p, &L, &v);
			ans -= L;
			ans += 1.0 * 2 * L / v;
		}
		printf("Case %d: %.3f\n\n", ++kase, ans);
	}
}
