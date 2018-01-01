#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
int n, m, T;
int a[1000006];
int pre[1000006];
int ans[1000006];
set<int>S;
int main()
{
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		S.clear();
		scanf("%d%d", &n, &m);
		memset(pre, 0, sizeof(pre));
		memset(ans, 0, sizeof(ans));
		rep(i, 1, m + 1) {
			scanf("%d", &a[i]);
			if (!a[i])S.insert(i);
		}
		int ok = 1;
		rep(i, 1, m + 1) {
			if (a[i]) {
				auto it = S.upper_bound(pre[a[i]]);
				if (it == S.end() || *it > i) {
					ok = 0;
					break;
				}
				else {
					ans[*it] = a[i];
					S.erase(it);
					pre[a[i]] = i;
				}
			}
		}
		printf(ok ? "YES\n" : "NO");
		if (ok)rep(i, 1, m + 1) {
			if (a[i] == 0)printf("%d ", ans[i]);
		}
		printf("\n");
	}
}
