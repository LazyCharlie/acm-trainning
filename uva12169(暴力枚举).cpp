#include<bits/stdc++.h>
using namespace std;
const int M = 10001;
int n, a[205];
void solve()
{
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			int ok = 1;
			for (int k = 1; k <= 2 * n; k += 2) {
				a[k] = (a[k - 1] * i + j) % M;
				if (k < 2 * n - 1 && (a[k] * i + j) % M != a[k + 1]) {
					ok = 0;
					break;
				}
			}
			if (ok)return;
		}
	}
}
int main()
{
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < 2 * n; i += 2)scanf("%d", &a[i]);
		solve();
		for (int i = 1; i < 2 * n; i += 2)printf("%d\n", a[i]);
	}
}
