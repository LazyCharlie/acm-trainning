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
void bfs()
{
	queue<int>q;
	d[1953124] = 1;
	d[0] = 0;
	q.push(1953124);
	int st[9];
	while (!q.empty()) {
		int tmp = q.front();
		for (int i = 0; i < 9; i++) {
			st[i] = tmp % 5;
			tmp /= 5;
		}
		tmp = q.front();
		int cnt = 0;
		for (int i = 0; i < 9; i++)if (st[i]) {
			for (int j = i + 1; j < 9; j++)if (st[j]) {
				if (card[i][st[i]] == card[j][st[j]]) {
					cnt++;
				}
			}
		}
		for (int i = 0; i < 9; i++)if (st[i]) {
			for (int j = i + 1; j < 9; j++)if (st[j]) {
				if (card[i][st[i]] == card[j][st[j]]) {
					if (vis[tmp - fp[i] - fp[j]] != kase) {
						vis[tmp - fp[i] - fp[j]] = kase;
						d[tmp - fp[i] - fp[j]] = 0;
						q.push(tmp - fp[i] - fp[j]);
					}
					d[tmp - fp[i] - fp[j]] += d[tmp] / cnt;
				}
			}
		}
		q.pop();
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	for (int i = 1; i <= 9; i++)fp[i] = fp[i - 1] * 5;
	while (input()) {
		++kase;
		bfs();
		printf("%.6f\n", d[0]);
	}
}
