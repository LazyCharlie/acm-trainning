#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
int T;
char s1[maxn], s2[maxn];
int c1, c2, t1, cnt;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		printf("Case %d: ",++cnt);
		scanf("%s%s", s1, s2);
		int len = strlen(s1);
		c1 = c2 = t1 = 0;
		for (int i = 0; i < len; i++) {
			if (s1[i] == '1')c1++;
			if (s2[i] == '1')c2++;
			if (s1[i] == '?')t1++;
		}
		if (c1 > c2) {
			printf("-1\n");
			continue;
		}
		int ans = t1 * 2;
		for (int i = 0; i < len; i++) {
			if (s1[i] == '?') {
				if (s2[i] == '0') {
					if (c1 + t1 - 1 >= c2)s1[i] = '0';
					else s1[i] = '1', c1++;
					t1--;
				}
				else if (s2[i] == '1') {
					if (c1 + 1 <= c2)s1[i] = '1', c1++;
					else s1[i] = '0';
					t1--;
				}
			}
		}
		int ct = 0;
		for (int i = 0; i < len; i++) {
			if (s1[i] == '0'&&s2[i] == '1'&&c1 < c2) {
				s1[i] = '1';
				c1++;
				ans += 2;
			}
		}
		for (int i = 0; i < len; i++) {
			if (s1[i] != s2[i])ans++;
		}
		ans += c2 - c1;
		printf("%d\n", ans / 2);
	}
}
