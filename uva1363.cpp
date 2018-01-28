#include<bits/stdc++.h>
using namespace std;
int n, k;
long long ans;
int main()
{
	while (scanf("%d%d", &n, &k) == 2) {
		ans = 0;
		for (int i = 1; i <= n;) {
			int tmp = k / i;
			int to = n; 
			if (tmp&&k / tmp < n)to = k / tmp;
			long long maxn = k%i;
			long long minn = maxn - (to - i)*tmp;
			ans += (maxn + minn)*(to - i + 1) / 2;
			i = to + 1;
		}
		printf("%lld\n", ans);
	}
}

