#include<bits/stdc++.h>
using namespace std;
double d[2000000], vis[2000000];
int p[256], kase;
int card[9][5];
int fp[10] = { 1 };
char s[5];
double dfs(int x)
{
	if (x == 0)return 1;
	if (vis[x] == kase)return d[x];
	d[x] = 0;
	vis[x] = kase;
	int tmp = x, tot = 0;
	int st[9] = { 0 };
	for (int i = 0; i < 9; i++) {
		st[i] = tmp % 5;
		tmp /= 5;
	}
	for (int i = 0; i < 9; i++)if (st[i]) {
		for (int j = i + 1; j < 9; j++)if (st[j]) {
			if (card[i][st[i]] == card[j][st[j]]) {
				tot++;
				d[x] += dfs(x - fp[i] - fp[j]);
			}
		}
	}
	if (tot == 0)return d[x];
	return d[x] /= tot;
}
int main()
{
	p['A'] = 1; p['T'] = 10; p['J'] = 11; p['Q'] = 12; p['K'] = 13;
	for (int i = '2'; i <= '9'; i++)p[i] = i - '0';
	for (int i = 1; i <= 9; i++) fp[i] = fp[i - 1] * 5;
	while (scanf("%s", s) == 1) {
		++kase;
		card[0][1] = p[s[0]];
		for (int i = 1; i < 36; i++) {
			scanf("%s", s);
			card[i / 4][i % 4 + 1] = p[s[0]];
		}
		dfs(1953124);
		printf("%.6f\n", d[1953124]);
	}
}
