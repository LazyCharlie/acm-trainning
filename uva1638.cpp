#include<bits/stdc++.h>
using namespace std;
int n, l, r, T;
long long d[32][32][32];
void init()
{
	d[1][1][1] = 1;
	for (int i = 2; i <= 30; i++) {
		for (int l = 1; l <= i; l++) {
			for (int r = 1; r <= i; r++) {
				d[i][l][r] = (i > 1 ? d[i - 1][l - 1][r] : 0) + (r > 1 ? d[i - 1][l][r - 1] : 0) + (i - 2)*d[i - 1][l][r];
			}
		}
	}
}
int main()
{
	init();
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &l, &r);
		printf("%lld\n", d[n][l][r]);
	}
}
