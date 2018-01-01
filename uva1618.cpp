#include<bits/stdc++.h>
using namespace std;
int n;
int a[5006];
int Lmin[5006][5006], Rmin[5006][5006], Lmax[5006][5006], Rmax[5006][5006];//L[i][j]表示在下标为j的元素左边第一个大于a[i]的数
int main()
{
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) {
			int id1 = -1, id2 = -1;
			for (int j = n - 1; j >= 0; j--) {
				Rmin[i][j] = id2;
				Rmax[i][j] = id1;
				if (a[j] > a[i])id1 = j;
				if (a[j] < a[i])id2 = j;
			}
		}
		int ok = 0;
		for (int p = 0; p < n; p++) {
			for (int s = p + 3; s < n; s++) {
				int q = Rmax[s][p], r;
				if (q >= 0 && q < s&&a[p] < a[s]) {
					r = Rmin[p][q];
					if (s > r&&r >= 0) {
						ok = 1;
						break;
					}
				}
				q = Rmin[s][p];
				if (q >= 0 && q < s&&a[p]>a[s]) {
					r = Rmax[p][q];
					if (s > r&&r >= 0) {
						ok = 1;
						break;
					}
				}
			}
			if (ok)break;
		}
		printf(ok ? "YES\n" : "NO\n");
	}
}
