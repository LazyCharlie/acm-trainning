#include<bits/stdc++.h>
using namespace std;
int p, q, r, s;
int main()
{
	while (scanf("%d%d%d%d", &p, &q, &r, &s) == 4) {
		double ans = 1;
		int maxn = max(s, q);
		for (int i = 1; i <= maxn; i++) {
			if (i <= q)ans = ans*(p - i + 1) / i;
			if (i <= s)ans = ans*i / (r - i + 1);
		}
		printf("%.5lf\n", ans);
	}
}
