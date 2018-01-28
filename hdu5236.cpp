#include<bits/stdc++.h>
using namespace std;
int T, n, x, kase;
double p;
double F[100006];
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lf%d", &n, &p, &x);
		for (int i = 1; i <= n; i++) {
			F[i] = (F[i - 1] + 1) / (1 - p);
		}
		double ans = 1e9;
		for (int i = 1; i <= n; i++) {//Ã¶¾Ù¼¸¶Î±£´æ
			int a = n / i;
			int b = n%i;
			ans = min(ans, F[a + 1] * b + F[a] * (i - b) + i*x);
		}
		printf("Case #%d: %.6lf\n", ++kase, ans);
	}
}
