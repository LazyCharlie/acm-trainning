#include<bits/stdc++.h>
using namespace std;
int n;
int g[32], f[32];
int main()
{
	g[0] = 1, g[1] = 2, g[2] = 4, f[1] = f[2] = 0; f[3] = 1;
	for (int i = 4; i <= 30; i++) {
		for (int k = 1; k <= i - 2; k++) {
			f[i] += (k == 1 ? 1 : g[k - 2]) * (1 << (i - k - 2));
		}
		g[i - 1] = (1 << (i - 1)) - f[i - 1];
	}
	while (scanf("%d", &n) == 1 && n) {
		printf("%d\n", f[n]);
	}
}
