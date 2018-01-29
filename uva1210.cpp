#include<bits/stdc++.h>
using namespace std;
int vis[10006], n;
vector<int>prime;
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
int main()
{
	seive(10000);
	while (scanf("%d", &n) == 1 && n) {
		int l = 0;
		int tot = 0, ans = 0;
		for (int i = 0; i < prime.size(); i++) {
			tot += prime[i];
			while (tot > n) {
				tot -= prime[l++];
			}
			if (tot == n)ans++;
		}
		printf("%d\n", ans);
	}
}
