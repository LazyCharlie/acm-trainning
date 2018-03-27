#include<bits/stdc++.h>
using namespace std;
int vis[200];
vector<long long>prime;
long long n, ans;
int a[25];
int cnt;
unsigned long long C[101][101];
void seive(int size)
{
	vis[1] = 1;
	for (int i = 2; i <= size; i++) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size(); j++) {
			if (i*prime[j] > size)break;
			vis[i*prime[j]] = 1;
			if (i%prime[j] == 0)break;
		}
	}
	C[0][0] = 1;
	for (int i = 1; i <= 100; i++) {
		C[0][i] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[j][i] = C[j - 1][i - 1] + C[j][i - 1];
	}
}
void dfs(int cur, long long tot, long long pn, long long pk, long long up)
{
	if (pn == n&&pk < ans) {
		ans = pk;
		return;
	}
	if (pk > ans || cur >= prime.size())return;
	for (int i = 1; i <= up; i++) {
		if (ans / prime[cur] <= pk)return;
		pk *= prime[cur];
		dfs(cur + 1, tot + i, pn*C[i][tot+i], pk, i);
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	seive(100);
	while (scanf("%lld", &n) == 1) {
		if (n == 1) {
			printf("1 2\n");
			continue;
		}
		ans = LLONG_MAX;
		dfs(0, 0, 1, 1, 63);
		printf("%lld %lld\n", n, ans);
	}
}
