#include<bits/stdc++.h>
using namespace std;
int p, q, r, s;
int ans[10000];
vector<int>prime;
bool vis[10001];//≥ı ºªØ 
int e[2000];
void Prime(int n)
{
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i < n; i++)
	{
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size() && i*prime[j] < n; j++)
		{
			vis[i*prime[j]] = 1;
			if (i%prime[j] == 0)break;
		}
	}
}
void add_interger(int n,int d) {
	for (int i = 0; i < prime.size(); i++) {
		while (n%prime[i] == 0) {
			n /= prime[i];
			e[i] += d;
		}
		if (n == 1)break;
	}
}
void add_factorial(int n, int d) {
	for (int i = 1; i <= n; i++) {
		add_interger(i, d);
	}
}
int main()
{
	Prime(10001);
	while (scanf("%d%d%d%d", &p, &q, &r, &s) == 4) {
		memset(e, 0, sizeof(e));
		add_factorial(p, 1);
		add_factorial(s, 1);
		add_factorial(r - s, 1);
		add_factorial(q, -1);
		add_factorial(p - q, -1);
		add_factorial(r, -1);
		double ans = 1;
		for (int i = 0; i < prime.size(); i++) {
			if (e[i]) {
				ans *= pow(prime[i], e[i]);
			}
		}
		printf("%.5lf\n", ans);
	}
}
