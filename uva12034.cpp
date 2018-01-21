#include<bits/stdc++.h>
using namespace std;
const int mod = 10056;
int T, a, f[1006];
int vis[1100];
int phi[1100],C[1006][1006];
int kase;
vector<int>prime;
void getlist(int listsize)
{
	vis[1] = true;
	for (int i = 2; i <= listsize; i++)
	{
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j <= prime.size()&&i*prime[j] <= listsize; j++)
		{
			vis[i*prime[j]] = true;
			if (i%prime[j] == 0)break;
		}
	}
}
void init()
{
	getlist(1001);
	C[1][0] = C[1][1] = 1;
	for (int i = 2; i <= 1000; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	f[0] = 1;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= i; j++) {
			f[i] = (f[i] + f[i - j] * C[i][j]) % mod;
		}
	}
}
int main()
{
	init();
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &a);
		printf("Case %d: %d\n", ++kase, f[a]);
	}
}
