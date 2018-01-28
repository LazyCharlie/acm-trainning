#include<bits/stdc++.h>
using namespace std;
int T, N, K, kase;
//由于一共选k个点，我们假设第i段是最长的那段，一共有k+1段。可以等效成一个圆上切k+1刀，最长的圆弧大于1/2
long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++kase);
		scanf("%d%d", &N, &K);
		long long son = (1LL << K) - (K + 1);
		long long mom = 1LL << K;
		long long g = gcd(son, mom);
		son /= g;
		mom /= g;
		printf("%lld/%lld\n", son, mom);
	}
}
