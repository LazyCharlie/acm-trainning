#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e8;
int n, kase;
int vis[maxn + 5];
int ans, use[30];
vector<int>prime, add;
void seive(int len)
{
	vis[1] = 1;
	for (int i = 2; i <= len; i++) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size(); j++) {
			if (prime[j] * i > len)break;
			vis[prime[j] * i] = 1;
			if (i%prime[j] == 0)break;
		}
	}
}
void dfs(int cur, int r, int tot)
{
	if (r == 1) {
		ans = min(ans, tot);
		return;
	}
	for (int i = cur; i < add.size(); i++) {
		if (r % (add[i] - 1) == 0) {
			int tmp = r / (add[i] - 1), t2 = tot*add[i];
			while (tmp%add[i] == 0) {
				dfs(i + 1, tmp, t2);
				tmp /= add[i], t2 *= add[i];
			}
			dfs(i + 1, tmp, t2);
		}
	}
}
long long solve(int n)
{
	add.clear();
	ans = 2e8 + 1;
	for (int i = 0; i < prime.size() && n >= prime[i] - 1; i++) {
		if (n % (prime[i] - 1) == 0)add.push_back(prime[i]);
	}
	int q = sqrt(n + 1.5);
	int ok = 0;
	for (int i = 2; i <= q; i++) {
		if ((n + 1) % i == 0) {
			ok = 1;
			break;
		}
	}
	if (!add.size() || !ok)return n + 1;
	dfs(0, n, 1);
	if (ans > 2e8)return 0;
	return ans;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	seive(maxn);
	while (scanf("%d", &n) == 1 && n) {
		printf("Case %d: %d %d\n", ++kase, n, solve(n));
	}
}
