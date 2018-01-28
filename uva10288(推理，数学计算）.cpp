#include<bits/stdc++.h>
using namespace std;
long long n, k;
long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}
int length(long long num)
{
	int ret = 0;
	while (num)num /= 10, ret++;
	return ret;
}
int main()
{
	while (scanf("%lld", &n) == 1) {
		long long mom = 1, son = 0;
		for (int k = 0; k < n; k++) {
			son = son*(n - k) + mom*n;
			mom = mom*(n - k);
			long long g = gcd(son, mom);
			mom /= g;
			son /= g;
		}
		if (mom == 1)printf("%lld\n", son);
		else {
			long long num = son / mom;
			son -= num*mom;
			int n = length(num);
			int m = length(mom);
			for (int i = 0; i <= n; i++)printf(" ");
			printf("%lld\n", son);
			printf("%lld ", num);
			for (int i = 0; i < m; i++)printf("-");
			printf("\n");
			for (int i = 0; i <= n; i++)printf(" ");
			printf("%lld\n", mom);
		}
	}
}
