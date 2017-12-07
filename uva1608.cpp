#include<bits/stdc++.h>
using namespace std;
int T, n, a[200006];
int L[200006], R[200006];
map<int, int>M;
int dfs(int L1, int R1)
{
	if (L1 >= R1)return 1;
	int l = L1, r = R1;
	while (l <= r) {
		if (R[l] > R1&&L[l] < L1) {
			if (!dfs(L1, l - 1))return 0;
			if (!dfs(l + 1, R1))return 0;
			return 1;
		}
		if (R[r] > R1&&L[r] < L1) {
			if (!dfs(L1, r - 1))return 0;
			if (!dfs(r + 1, R1))return 0;
			return 1;
		}
		l++;
		r--;
	}
	return 0;
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]), L[i] = -1, R[i] = n;
		M.clear();
		for (int i = 0; i < n; i++) {
			if (M.count(a[i])) {
				L[i] = M[a[i]];
				M[a[i]] = i;
			}
			M[a[i]] = i;
		}
		M.clear();
		for (int i = n - 1; i >= 0; i--) {
			if (M.count(a[i])) {
				R[i] = M[a[i]];
				M[a[i]] = i;
			}
			M[a[i]] = i;
		}
		int ans = dfs(0, n - 1);
		printf(ans ? "non-boring\n" : "boring\n");
	}
}
