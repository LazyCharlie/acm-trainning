#include<bits/stdc++.h>
using namespace std;
const long long maxn = 1e12;
int T, vis[1000006];
vector<long long>prime, S;
long long L, U;
void seive(int l)
{
	vis[1] = 1;
	for (int i = 2; i <= l; i++) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size(); j++) {
			if (i*prime[j] > l)break;
			vis[i*prime[j]] = 1;
			if (i%prime[j] == 0)break;
		}
	}
}
void init()
{
	seive(1000000);
	for (int i = 0; i < prime.size(); i++) {
		long long base = prime[i] * prime[i];
		while (base <= maxn) {
			S.push_back(base);
			base *= prime[i];
		}
	}
	sort(S.begin(), S.end());
}
int main()
{
	init();
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &L, &U);
		int p1 = lower_bound(S.begin(), S.end(), L) - S.begin();
		int p2 = lower_bound(S.begin(), S.end(), U) - S.begin();
		printf("%d\n", p2 - p1);
	}
}
