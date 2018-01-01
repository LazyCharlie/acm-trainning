#include<bits/stdc++.h>
using namespace std;
long long n, m, o[4];
int cnt;
long long ans;
int main()
{
	//freopen("in.txt", "r", stdin);
	while (scanf("%lld%lld", &n, &m) == 2 && n) {
		for (int i = 0; i < 4; i++)scanf("%lld", &o[i]);
		if (o[0] < o[1])swap(o[0], o[1]);
		if (o[2] < o[3])swap(o[2], o[3]);
		long long k1 = 0, k2 = 0;
		if (o[1])k1 = 2 * o[1] - (o[1] == o[0]);
		if (o[3])k2 = 2 * o[3] - (o[2] == o[3]);
		if ((n - 1)*k1 + n < (m - 1)*k2 + m) {
			swap(n, m);
			swap(o[0], o[2]);
			swap(o[1], o[3]);
			swap(k1, k2);
		}
		if (o[1]) {//一定要记得判断！！！！！
			ans = n--*m;
			ans += n*m*k1;
			o[0] -= (k1 & 1) ? o[1] : o[1] + 1;
			o[1] = 0;
		}
		if (o[3]) {
			while (o[0] && n - m > (m - 1)*k2) {
				ans += m*n;
				n--;
				o[0]--;
			}
			ans += m--*n;
			ans += k2*m*n;
			o[2] -= (k2 & 1) ? o[3] : o[3] + 1;
			o[3] = 0;
		}
		while (o[0] || o[2]) {
			if (n == 0 || m == 0)break;
			ans += m*n;
			if (o[0] && !o[2])o[0]--, n--;
			else if (o[2] && !o[0])o[2]--, m--;
			else if (n > m)n--, o[0]--;
			else m--, o[2]--;
		}
		printf("Case %d: %lld\n", ++cnt, ans);
	}
}
