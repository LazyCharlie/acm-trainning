#include<bits/stdc++.h>
using namespace std;
const double g = 9.81;
double k, l, s, m;
int main()
{
	//reopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%lf%lf%lf%lf", &k, &l, &s, &m) == 4 && s > 1e-7) {
		double h = (m*g + k*l + sqrt(m*m*g*g + 2 * m*g*k*l)) / k;
		if (h < s) printf("Stuck in the air.\n");
		else {
			double minh = (m*g + k*l + sqrt((m*g + k*l)*(m*g + k*l) - k*(m*10*10 + k*l*l))) / k;
			if (minh > s&&s > 50.0 / g)printf("Killed by the impact.\n");
			else printf("James Bond survives.\n");
		}
	}
}
