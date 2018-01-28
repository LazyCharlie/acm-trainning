#include<bits/stdc++.h>
using namespace std;
int n;
double d[40], t;
double p, p0;
int main()
{
	while (scanf("%d%lf", &n, &t) == 2 && n) {
		d[n] = 1 << n;
		p = (1 + t)*0.5;
		for (int i = n - 1; i >= 0; i--) {
			p0 = max(t, (1 << i) / d[i + 1]);
			d[i] = (1 << i)*(p0 - t) / (1 - t) + d[i + 1] * (1 + p0)*0.5*(1 - p0) / (1 - t);
		}
		printf("%.3lf\n", d[0]);
	}
}
