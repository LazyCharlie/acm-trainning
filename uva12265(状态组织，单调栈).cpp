#include<bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
struct node {
	int c, h;
};
int T, n, m;
char s[N];
int ans[N >> 1], H[N];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		memset(ans, 0, sizeof(ans));
		memset(H, 0, sizeof(H));
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			stack<node>S; 
			for (int j = 0; j < m; j++) {
				if (s[j] == '#')stack<node>().swap(S), H[j] = 0;
				else {
					H[j]++;
					int ok = 0, lc;
					while (S.size() && S.top().h > H[j])lc = S.top().c, S.pop(), ok = 1;
					if (ok && (S.empty() || H[j] - lc > S.top().h - S.top().c)) {
						S.push({ lc,H[j] });
					}
					if (S.empty() || j - S.top().c < H[j] - S.top().h) {
						ans[1 + H[j]]++;
						S.push({ j,H[j] });
					}
					else {
						ans[j - S.top().c + 1 + S.top().h]++;
					}
				}
			}
		}
		for (int i = 1; i <= n + m; i++) {
			if (ans[i])printf("%d x %d\n", ans[i], i * 2);
		}
	}
}
