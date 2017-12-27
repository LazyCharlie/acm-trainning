#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e7 + 5;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
long long ans[maxn];
int T, cnt, n;
int main()
{
	for (int i = 1; i <= 30000000; i++) {
		for (int j = i * 2; j <= 30000000; j += i) {
			int c = i, a = j;
			int b = a^c;
			if (b + c == a)ans[a]++;
		}
	}
	for (int i = 1; i <= 30000000; i++)ans[i] += ans[i - 1];
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("Case %d: %lld\n", ++cnt, ans[n]);
	}
}
