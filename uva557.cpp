#include<bits/stdc++.h>
using namespace std;
int T, n;
double ans;
double p[100006];//p[i]表示2*i个孩子时候最后两个孩子吃到不同的概率
void init()
{
	p[1] = 1;
	for (int i = 2; i <= 50000; i++) {
		p[i] = p[i - 1] * (2 * i - 3) / (2 * i - 2);
	}
}
int main()
{
	init();
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("%.4lf\n", 1 - p[n / 2]);
	}
}
