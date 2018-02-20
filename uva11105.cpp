#include<bits/stdc++.h>
using namespace std;
int vis[1000006], H[1000006], n;
vector<int>prime, half;
void init()
{
	for (int i = 5; i <= 1000001; i+=4) {
		for (int j = i; j <= 1000001; j+=4) {
			if (1LL * i*j > 1000001)break;
			vis[i*j] = 1;
		}
	}
	for (int i = 5; i <= 1000001; i+=4) {
		if (!vis[i])prime.push_back(i);
	}
	for (int i = 0; i < prime.size(); i++) {
		for (int j = i; j < prime.size(); j++) {
			if (1LL * prime[i]*prime[j] > 1000001)break;
			H[prime[i]*prime[j]] = 1;
		}
	}
	for (int i = 5; i <= 1000001; i+=4) {
		if (H[i])half.push_back(i);
	}
}
int main()
{
	init();
	while (scanf("%d", &n) == 1 && n) {
		printf("%d ", n);
		int ans = lower_bound(half.begin(), half.end(), n + 1) - half.begin();
		printf("%d\n", ans);
	}
}
