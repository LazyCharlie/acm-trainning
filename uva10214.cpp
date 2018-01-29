#include<bits/stdc++.h>
using namespace std;
long long tot;
long long phi[2005];
long long a, b;
void phi_table(int n)
{
	phi[1] = 1;
	for (int i = 2; i <= n; i++)if (!phi[i]) {
		for (int j = i; j <= n; j+=i) {
			if (!phi[j])phi[j] = j;
			phi[j] = phi[j] / i*(i - 1);
		}
	}
}
long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}
int main()
{
	phi_table(2000);
	while (scanf("%lld%lld", &a, &b) == 2 && a) {
		tot = 1;
		for (int i = 1; i <= a; i++) {
			long long t = b / i;
			tot += t*phi[i];
			int r = b%i;
			for (int j = 1; j <= r; j++) {
				if (gcd(i, j) == 1)tot++;
			}
		}
		long long sum = (a * 2 + 1)*(b * 2 + 1) - 1;
		printf("%.8lf\n", 1.0*tot * 4 / sum);
	}
}
