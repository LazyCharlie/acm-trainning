#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
int cnt;
long long n;
long long solve(long long n)
{
	if (n == 1)return 2;
	long long ret = 0;
	int mid = sqrt(n) + eps;
	int count = 0;
	for (int i = 2; i <= mid; i++) {
		if (n%i == 0) {
			long long ans = 1;
			while (n%i == 0) {
				ans *= i;
				n /= i;
			}
			count++;
			ret += ans;
		}
		if (n == 1)break;
	}
	if (n > 1)ret += n;//n is a primer
	if (count < 1 && n>1 || count == 1 && n == 1)ret++;
	return ret;
}
int main()
{
	while (scanf("%lld", &n) == 1 && n) {
		printf("Case %d: %lld\n", ++cnt,solve(n));
	}
}
