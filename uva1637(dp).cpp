#include<bits/stdc++.h>
using namespace std;
double d[2000000];
int vis[2000000];
char card[9][5];
int kase;
int fp[10] = { 1 };
bool input()
{
	char s[5];
	for (int i = 0; i < 9; i++) {
		for (int j = 1; j <= 4; j++) {
			if (scanf("%s", s) != 1)return false;
			card[i][j] = s[0];
		}
	}
	return true;
}
double dfs(int x)
{
	if (x == 0)return 1;
	if (vis[x] == kase)return d[x];
	vis[x] = kase;
	double sum = 0;
	int cnt = 0, st[9], tmp = x;
	for (int i = 0; i < 9; i++) {
		st[i] = tmp % 5;
		tmp /= 5;
	}
	for (int i = 0; i < 9; i++)if (st[i]) {
		for (int j = i + 1; j < 9; j++)if (st[j]) {
			if (card[i][st[i]] == card[j][st[j]]) {
				cnt++;
				sum += dfs(x - fp[i] - fp[j]);
			}
		}
	}
	if (cnt == 0)return d[x] = 0;
	return d[x] = sum / cnt;
}
int main()
{
	for (int i = 1; i <= 9; i++)fp[i] = fp[i - 1] * 5;
 	while (input()) {
		++kase;
		printf("%.6f\n", dfs(1953124));
	}
}
