#include<bits/stdc++.h>
using namespace std;
int T;
double a, b, S;
const double eps = 1e-6;
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%lf%lf%lf", &a, &b, &S);
		double ans;
		if (S < eps)ans = 0;
		else if (S >= a*b)ans = 100;
		else ans = S*(log(a*b / S) + 1) / (a*b) * 100;
		printf("%.6lf%%\n", 100-ans);
	}
}
