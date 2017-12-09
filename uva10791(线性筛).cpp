#include<bits/stdc++.h>
using namespace std;
long long n;
int cnt;
vector<int>prime;
int vis[65540];
void Prime(int n)
{
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i<n; i++)
	{
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j<prime.size()&&i*prime[j]<n; j++)
		{
			vis[i*prime[j]] = 1;
			if (i%prime[j] == 0) break;
		}
	}
}
long long solve(long long n)
{
	if (n == 1LL)return 2;
	int cnt = 0;
	long long ret = 0;
	for (int i = 0; i < prime.size(); i++) {
		long long ans = 1;
		int flag = 0;
		while (n%prime[i] == 0) {
			n /= prime[i];
			ans *= prime[i];
			if (!flag)flag = 1, cnt++;
		}
		if (flag)ret += ans;
		if (n == 1)break;
	}
	if (n > 1)ret += n;
	if (cnt <= 1)ret++;
	return ret;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	Prime(65537);
	while (scanf("%lld", &n) == 1 && n) {
		printf("Case %d: %lld\n", ++cnt, solve(n));
	}
}
