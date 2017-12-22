#include<bits/stdc++.h>
using namespace std;
const int mx = 1e3 + 6;
const int mm = (1 << 16) - 1;
const int INF = 0x3f3f3f3f;
int n, a[4], st[mx];//位压缩
char s[4][mx];//读入字符串
int d[mx][mm + 6];//d[i][j]表示0~i-1行都已经变成dot 并且i~i+3行的状态是j
vector<int>mark[4];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 4; i++)scanf("%d", &a[i]);
	for (int i = 0; i < 4; i++)scanf("%s", s[i]);
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 4; i++) {
			st[j] |= (s[i][j] == '*') << i;
		}
	}
	memset(d, 0x3f, sizeof(d));
	int S = 0;
	for (int i = 0; i < 4; i++)S |= st[i] << (i * 4);
	d[0][S] = 0;
	for (int i = 1; i <= 4; i++) { //枚举方框的大小
		for (int j = 0; j <= 4 - i; j++) {
			mark[i - 1].push_back(mm);
			int & SS = mark[i - 1].back();
			for (int k = j; k < j + i; k++) {
				for (int g = 0; g < i; g++) {
					SS ^= 1 << (g * 4 + k);   //预处理，使得每次覆盖操作可以在O(1)内完成
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = mm; j >= 0; j--) {
			if (d[i][j] == INF)continue;//d[i][j]==INF表示该状态不可达
			if (!(j & 15)) { //如果该状态可达，并且第i列全部都是dot
				int SS = j >> 4 | (st[i + 4] << 12);//那么该状态可以转化成d[i+1][j&SS]
				d[i + 1][SS] = min(d[i][j], d[i + 1][SS]);
			}
			for (int k = 1; k <= 4 && k + i <= n; k++) {
				for (auto p : mark[k - 1]) {
					d[i][j&p] = min(d[i][j&p], d[i][j] + a[k - 1]);
				}
			}
		}
	}
	printf("%d\n", d[n][0]);
}
