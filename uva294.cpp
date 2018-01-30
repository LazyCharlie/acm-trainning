#include<bits/stdc++.h>
using namespace std;
long long L, U;
int vis[100000];
vector<int>prime;
int T;
void seive(int l)
{
	vis[1] = 1;
	for (int i = 2; i <= l; i++) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size(); j++) {
			if (prime[j] * i > l)break;
			vis[i*prime[j]] = 1;
			if (i%prime[j] == 0)break;
		}
	}
}
int main()
{
	seive(32000);
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &L, &U);
		int ans=0, ct = 0;
		for (int i = L; i <= U; i++) {
			int cur = i;
			int div = 1;
			for (int j = 0; j < prime.size() && cur>1; j++) {
				if (cur%prime[j] == 0) {
					int cnt = 0;
					while (cur%prime[j] == 0) {
						cur /= prime[j];
						cnt++;
					}
					div *= cnt + 1;
				}
			}
			if (div > ct) {
				ans = i;
				ct = div;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, ans, ct);
	}
}
