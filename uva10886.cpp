#include<bits/stdc++.h>
using namespace std;
unsigned long long seed;
int T, kase, n;
double y, x2, x;
long double gen()
{
	static const long double Z = (long double)1.0 / (1LL << 32);
	seed >>= 16;
	seed &= (1ULL << 32) - 1;
	seed *= seed;
	return seed*Z;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++kase);
		scanf("%d%llu", &n, &seed);
		x2 = x = 0;
		for (int i = 0; i < n; i++) {
			y = gen();
			x2 += y*y;
			x += y;
		}
		printf("%.5lf\n", sqrt(x2 / n - (x / n)*(x / n)));
	}
}
