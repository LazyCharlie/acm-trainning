#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[100006];
int main()
{
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)scanf("%d", &a[i]);
		sort(a, a + n);
		int L = 0, R = n - 1;
		int bag = 0;
		while (L < R) {
			if (a[R] + a[L] <= m)L++;
			R--;
			bag++;
		}
		if (L == R)bag++;
		printf("%d\n", bag);
		if (T)printf("\n");
	}
}
