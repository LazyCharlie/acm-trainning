#include<bits/stdc++.h>
using namespace std;
int T;
long long n, k;
int main()
{
	freopen("chess.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &n, &k);
		long long mod = n % (k + 1);
		if (mod == 0)mod = k + 1;
		long long base = (n - mod) / (k + 1) + 1;
		printf("%lld\n", n*n - ((mod + n)*base - n));
	}
}
