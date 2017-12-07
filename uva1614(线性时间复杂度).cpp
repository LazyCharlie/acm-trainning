#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int a[maxn];
int n, ans[maxn];
long long sum;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d", &n) == 1) {
		sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (sum & 1) {
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		sum >>= 1;
		for (int i = n; i >= 1; i--) {
			if (sum - a[i] >= 0) {
				sum -= a[i];
				ans[i] = 1;
			}
			else ans[i] = -1;
		}
		for (int i = 1; i <= n; i++) {
			printf("%d%c", ans[i], i == n ? '\n' : ' ');
		}
	}
}
