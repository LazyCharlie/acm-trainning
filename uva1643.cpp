#include<bits/stdc++.h>
using namespace std;
pair<double, double>v1, v2,t;
double operator*(pair<double, double> a, pair<double, double>b)
{
	return a.first*b.first + a.second*b.second;
}
const double sqrt2 = sqrt(2);
double angle(pair<double, double>a, pair<double, double>b)
{
	return acos((a*b) / (sqrt(a.first*a.first + a.second*a.second)*sqrt(b.first*b.first + b.second*b.second)));
}
int main()
{
	int N;
	while (scanf("%d", &N) == 1 && N) {
		scanf("%lf%lf%lf%lf", &v1.first, &v1.second, &v2.first, &v2.second);
		if (v1.second*v2.first < v2.second*v1.first)swap(v1, v2);//0A的斜率大于0B
		double S = 0, tmp, len = 0;
		for (int i = 0; i < N; i++) {
			scanf("%lf", &tmp);
			len += tmp*sqrt2;
			S -= tmp*tmp / 2;
		}
		double th1 = angle(v1, v2);
		t = { -1.0,1.0 };
		double th2 = angle(v1, t);
		double OB = sin(th2) / sin(th1)*len;
		t = { 1,-1 };
		double th3 = angle(v2, t);
		S += OB*len*sin(th3)*0.5;
		printf("%.3lf\n", S);
	}
}
