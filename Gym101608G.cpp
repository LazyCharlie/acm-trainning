#include<bits/stdc++.h>
using namespace std;
int T, n, v;
int a[100006], ans;
int num[20];
void op(int nn,int o)
{
	for (int i = 0; i < 20; i++) {
		if (nn % 2)num[i] += o;
		nn /= 2;
	}
}
int todigit()
{
	int ret = 0;
	for (int i = 0; i < 20; i++) {
		ret += (num[i] > 0) << i;
	}
	return ret;
}
int main()
{
	freopen("wifi.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &v);
		memset(num, 0, sizeof(num));
		ans = 0;
		for (int i = 0; i < n; i++)scanf("%d", &a[i]);
		int l = 0;
		for (int i = 0; i < n; i++) {
			op(a[i], 1);
			while (l <= i && (todigit() | a[i]) > v) {
				op(a[l++], -1);
			}
			if (l == i + 1)continue;
			ans = max(ans, i - l + 1);
		}
		printf("%d\n", ans);
	}
}
