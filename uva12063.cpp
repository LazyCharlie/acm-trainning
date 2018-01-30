#include<bits/stdc++.h>
using namespace std;
int T, N, K, kase;
long long d[65][65][105];
long long solve()
{
	if (!K || N % 2 == 1)return 0;
	memset(d, 0, sizeof(d));
	d[0][0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < K; k++) {
				if (i + 1 < N)d[i + 1][j][k] += d[i][j][k];
				d[i + 1][j + 1][(k + (1LL << i)) % K] += d[i][j][k];
			}
		}
	}
	return d[N][N / 2][0];
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &K); 
		printf("Case %d: %lld\n", ++kase,solve());
	}
}
