#include<bits/stdc++.h>
using namespace std;
int T, n;
double ans;
double p[100006];//p[i]��ʾ2*i������ʱ������������ӳԵ���ͬ�ĸ���
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
