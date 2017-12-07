#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, d, pt;
char ch, ans[maxn];
int main()
{
	while (scanf("%d%d", &n, &d) == 2 && n) {
		getchar();
		pt = 0;
		int t = d;
		for (int i = 0; i < n; i++) {
			ch = getchar();
			while (d&&pt > 0 && ans[pt - 1] < ch) {
				pt--;
				d--;
			}
			ans[pt++] = ch;
		}
		ans[n - t] = '\0';
		printf("%s\n", ans);
	}
}
