#include<bits/stdc++.h>
using namespace std;
int vis[2000];
vector<int>prime;
int d[15][3000];
int a, b;
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
	seive(1120);
	d[0][0] = 1;
	for (int c = 0; c < prime.size(); c++) {
		for (int i = 13; i >= 0; i--) {
			for (int j = 0; j <= 1120; j++) {
				d[i + 1][j + prime[c]] += d[i][j];
			}
		}
	}
	while (scanf("%d%d", &a, &b) == 2 && a) {
		printf("%d\n", d[b][a]);
	}
}
