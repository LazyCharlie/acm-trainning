#include<bits/stdc++.h>
using namespace std;
int T, n, L, t;
int cnt;
pair<int,int> pos[10006];
char str[4][10] = { "L","Turning","R","Fell off" };
struct ant {
	int p, id;
	int state;
	bool operator<(const ant&a)const {
		return p < a.p;
	}
}s[10006];
pair<int, int>ans[10006];
char ch;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d:\n", ++cnt);
		scanf("%d%d%d", &L, &t, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %c ", &s[i].p, &ch);
			s[i].id = i + 1;
			int k = ch == 'R' ? 1 : -1;
			pos[i].first = s[i].p + k*t;
			pos[i].second = k;
		}
		sort(s, s + n);
		sort(pos, pos + n);
		for (int i = 0; i < n; i++) {
			ans[s[i].id].first = pos[i].first;
			ans[s[i].id].second = pos[i].second + 1;
			if (i&&pos[i].first == pos[i - 1].first) {
				ans[s[i - 1].id].second = ans[s[i].id].second = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (ans[i].first >= 0 && ans[i].first <= L) {
				printf("%d ", ans[i].first);
				printf("%s\n", str[ans[i].second]);
			}
			else printf("%s\n", str[3]);
		}
		printf("\n");
	}
}
