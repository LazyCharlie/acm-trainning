#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n, kase;
long long d[1005];
void init()
{
	d[1] = 1;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; i*j + 1 <= 1000; j++) {
			d[i*j + 1] += d[i];
			d[i*j + 1] %= mod;
		}
	}
}
int main()
{
	init();
	while (scanf("%d", &n) == 1 && n) {
		printf("Case %d: %lld\n", ++kase, d[n]);
	}
}
