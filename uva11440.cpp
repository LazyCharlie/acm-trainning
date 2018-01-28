#include<bits/stdc++.h>
using namespace std;
const long long mod = 100000007;
int N, M, vis[10000006];
long long phifact[10000006];
vector<int>prime;
void seive(int len)
{
	vis[1] = 1;
	for (int i = 2; i <= len; i++) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size(); j++) {
			if (1LL * prime[j] * i > len)break;
			vis[prime[j] * i] = 1;
			if (i%prime[j] == 0)break;
		}
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	seive(10000001);
	phifact[1] = 1;
	for (int i = 2; i <= 10000000; i++) {
		phifact[i] = phifact[i - 1] * (vis[i] ? i : i - 1) % mod;
	}
	while (scanf("%d%d", &N, &M) == 2 && N) {
		//计算出(2~M!有多少个与M!互素的数)
		long long ans = phifact[M];
		for (int i = M + 1; i <= N; i++) {
			ans = ans*i%mod;
		}
		printf("%lld\n", (ans - 1 + mod) % mod);
	}
}
