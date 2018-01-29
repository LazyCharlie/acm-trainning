#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}
map<long long, int>V[2];//M[i]=j表示gcd值为i的序列最长长度为j
int T, n;
long long tmp;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		V[0].clear(); V[1].clear();
		int cur = 0;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &tmp);
			V[cur ^ 1].clear();
			for (auto it = V[cur].begin(); it != V[cur].end(); it++) {
				long long g = gcd(tmp, it->first);
				if (V[cur ^ 1].count(g)) {
					V[cur ^ 1][g] = max(V[cur ^ 1][g], it->second + 1);
				}
				else V[cur ^ 1][g] = it->second + 1;
			}
			cur ^= 1;
			if (!V[cur].count(tmp))V[cur][tmp] = 1;
			for (auto it = V[cur].begin(); it != V[cur].end(); it++) {
				ans = max(ans, it->first*it->second);
			}
		}
		printf("%lld\n", ans);
	}
}
