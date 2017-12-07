#include<bits/stdc++.h>
double L, D, x, y;
int n;
struct node {
	double x, y;
	bool operator<(const node &a)const {
		return y<a.y || y == a.y&&x>a.x;
	}
}p[100006];
int main()
{
	while (scanf("%lf", &L) == 1) {
		scanf("%lf%d", &D, &n);
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &x, &y);
			p[i].x = x - sqrt(D*D - y*y);
			p[i].y = x + sqrt(D*D - y*y);
		}
		sort(p, p + n);
		double pre = p[0].y;
		for (int i = 1; i < n; i++) {
			if (pre < p[i].x) {
				pre = p[i].y;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}
