#include<bits/stdc++.h>
using namespace std;
int n, U;
int a[100006];
int main()
{
	scanf("%d%d", &n, &U);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int R = 0;
	double ans = -1;
	for (int i = 0; i < n; i++) {
		while (R + 1 < n&&a[R + 1] - a[i] <= U)R++;
		if (i + 1 < R) {
			ans = max((a[R] - a[i + 1] * 1.0) / (a[R] - a[i]),ans);
		}
	}
	printf("%.10lf", ans);
}
