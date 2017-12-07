#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
struct node {
	double L, R;
	bool operator<(const node&a)const {
		return R<a.R || R == a.R&&L>a.L;
	}
}p[100006];
int n;
double step;
int main()
{
	while (scanf("%d", &n) == 1) {
		step = 0x3f3f3f3f;
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &p[i].L, &p[i].R);
			step = min(step, p[i].R - p[i].L);
		}
		sort(p, p + n);
		double l = 0, r = step;
		while (r - l > eps) {
			double mid = (l + r) / 2.0;
			double pre = -1000000;
			int ok = 1;
			for (int i = 0; i < n; i++) {
				pre = max(p[i].L, pre) + mid;
				if (pre > p[i].R) {
					ok = 0;
					break;
				}
			}
			if (ok)l = mid;
			else r = mid;
		}
		int as = 0, ms = 1;
		int s = 1, m = 1;
		for (m = 1; m <= n; m++) {
			s = round(m*l);
			if (fabs((double)s / m - l) < fabs((double)as / ms - l)) {
				as = s;
				ms = m;
			}
		}
		printf("%d/%d\n", as, ms);
	}
}
