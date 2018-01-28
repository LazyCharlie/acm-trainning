#include<bits/stdc++.h>
using namespace std;
int T, k, t[15];
char solved[20];
pair<int,int> p[30];
int str[30];
int main()
{
	freopen("scoreboard.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &k);
		scanf("%s", solved);
		memset(str, 0, sizeof(str));
		for (int i = 0; i < k; i++)str[solved[i] - 'A'] = 1;
		for (int i = 0; i < 13; i++)scanf("%d", &p[i].first), p[i].second = 'A' + i;
		sort(p, p + 13);
		for (int i = 12; i >= 0; i--) {
			if (str[p[i].second - 'A'] == 0) {
				printf("%c\n", p[i].second);
				break;
			}
		}
	}
}
