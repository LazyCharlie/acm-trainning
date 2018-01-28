#include<bits/stdc++.h>
using namespace std;
int T, r[505], n;
int main()
{
	freopen("overcode.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)scanf("%d", &r[i]);
		sort(r, r + n);
		int ans = 0;
		int i = 0;
		while (i < n) {
			if (i + 5 < n&&r[i + 5] - r[i] <= 1000)ans++, i += 6;
			else i++;
		}
		printf("%d\n", ans);
	}
}
