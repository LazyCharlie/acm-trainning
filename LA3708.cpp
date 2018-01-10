#include<bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
	while (scanf("%d%d", &n, &m) == 2) {
		double ans = 0;
		for (int i = 1; i < n; i++) {
			double p = (double)i * (n + m) / n;
			ans += fabs(p - floor(p + 0.5)) / (n+m)*1e4;
		}
		printf("%.4f\n", ans);
	}
}
