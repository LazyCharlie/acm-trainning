#include<bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%lld", &n) == 1 && n) {
		int ans = 1;
		int sign = n < 0;
		n = abs(n);
		int q = sqrt(n + 0.5);
		for (int i = 2; i <= q; i++) {
			long long base = i*i;
			int cnt = 2;
			while (base < n)base *= i, cnt++;
			if (base == n && (sign&&cnt%2 || sign == 0)) {
				ans = cnt;
				break;
			}
		}
		printf("%d\n", ans);
	}
}
