#include<bits/stdc++.h>
using namespace std;
int T, N, K, kase;
//����һ��ѡk���㣬���Ǽ����i��������ǶΣ�һ����k+1�Ρ����Ե�Ч��һ��Բ����k+1�������Բ������1/2
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
