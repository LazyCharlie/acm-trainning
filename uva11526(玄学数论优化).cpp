#include<bits/stdc++.h>
using namespace std;
int T, n;
long long H(int n)
{
	long long res = 0;
	int q = sqrt(n + 0.5);
	for (int i = 1; i <= q; i++) {
		res += n / i;
	}
	return res * 2 - q*q;
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("%lld\n",H(n));
	}
}
