#include<bits/stdc++.h>
using namespace std;
int n, kase;
double p;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d%lf", &n, &p) == 2) {
		double pos = 0;
		long double C = 0;
		for (int i = 0; i <= n; i++) {
			long double I = i;
			long double v1 = C + i*log(p) + (n + 1)*log(1 - p);
			long double v2 = C + (n + 1)*log(p) + i*log(1 - p);
			pos += (exp(v1)+exp(v2))*(n - i);
			C += log(n + I + 1) - log(I + 1);
		}
		printf("Case %d: %.6f\n", ++kase, pos);
	}
}
