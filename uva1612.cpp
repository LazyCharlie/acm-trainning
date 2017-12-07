#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
int n;
double a[16390][3], res[16390];
int L[16390];
int cnt = 0;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d", &n) == 1 && n) {
		printf("Case %d: ",++cnt);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%lf", &a[i][j]);
			}
		}
		for (int i = 0; i < n; i++)scanf("%d", &L[i]), L[i]--;
		double pre = 10000;
		int ans = 1;
		for (int i = 0; i < n; i++) {
			double maxn = -1;
			for (int j = 0; j < 8; j++) {
				double sum = 0;
				for (int k = 0; k < 3; k++) {
					if ((j >> k) & 1) {
						sum += a[L[i]][k];
					}
				}
				if (sum < pre - eps || fabs(sum - pre)<eps&&i&&L[i] > L[i - 1]) {
					maxn = max(maxn, sum);
				}
			}
			if (maxn < -eps) {
				ans = 0;
				break;
			}
			res[L[i]] = maxn;
			pre = maxn;
		}
		if (!ans)printf("No solution\n");
		else printf("%.2lf\n", res[L[n - 1]]);
	}
}
