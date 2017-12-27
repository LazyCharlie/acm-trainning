#include<bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 20;
int vis[maxn], cnt[maxn], cur[maxn], p[maxn];
vector<int>prime, ans;
int n, m;
void init(int m)
{
	prime.clear();
	int M = sqrt(m + 0.5);
	for (int i = 2; i <= M; i++) {
		if (m%i == 0) {
			prime.push_back(i);
			while (m%i == 0)m /= i;
		}
	}
	if (m > 1)prime.push_back(m);
}
int main()
{
	while (scanf("%d%d", &n, &m) == 2) {
		init(m);
		memset(cnt, 0, sizeof(cnt));
		memset(cur, 0, sizeof(cur));
		ans.clear();
		int err = 0, tmp = m;
		for (int i = 0; i < prime.size(); i++) {
			while (tmp%prime[i] == 0)cnt[i]++, tmp /= prime[i];
		}
		for (int i = 0; i < prime.size(); i++) {
			if (cnt[i])err++;
		}
		for (int i = 0; i < (n + 1) / 2; i++) {
			int big = n - i;
			int sma = i;
			for (int j = 0; j < prime.size(); j++) {
				int flag = cur[j] >= cnt[j];
				while (sma&&sma%prime[j] == 0)sma /= prime[j], cur[j]--;
				while (sma&&big%prime[j] == 0)big /= prime[j], cur[j]++;
				err += flag - (cur[j] >= cnt[j]);
				if (sma <= 1 && big <= 1)break;
			}
			if (!err)ans.push_back(i + 1);
		}
		for (int i = ans.size() - 1; i >= 0; i--) {
			if (n - ans[i] + 1 > ans[i])ans.push_back(n - ans[i] + 1);
		}
		printf("%d\n", ans.size());
		if (!ans.size())printf("\n");
		for (int i = 0; i < ans.size(); i++) {
			printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
		}
	}
}
