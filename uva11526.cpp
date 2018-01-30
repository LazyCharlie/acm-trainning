#include<bits/stdc++.h>
using namespace std;
int T;
long long n, ans;
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		ans = 0;
		for (long long i = 1; i <= n;) {
			long long q = n / i;
			long long j = n / q;
			ans += (j - i + 1LL)*q;
			i = j + 1;
		}
		printf("%lld\n", ans);
	}
}
