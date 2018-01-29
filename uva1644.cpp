#include<bits/stdc++.h>
using namespace std;
int vis[1300000], n;
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
	seive(1300000);
	while (scanf("%d", &n) == 1 && n) {
		if (!vis[n]) {
			printf("0\n");
			continue;
		}
		int x, y;
		for (int i = n - 1;; i--) {
			if (!vis[i]) {
				x = i;
				break;
			}
		}
		for (int i = n + 1;; i++) {
			if (!vis[i]) {
				y = i;
				break;
			}
		}
		printf("%d\n", y - x);
	}
}
