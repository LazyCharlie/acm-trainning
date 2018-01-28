#include<bits/stdc++.h>
using namespace std;
int a, b, p[10];//p[i]表示i位数中单种数字出现的次数(包含前导0)
int pows10[10];
char str[10];
void init()
{
	pows10[0] = 1;
	for (int i = 1; i < 10; i++) {
		pows10[i] = pows10[i - 1] * 10;
		p[i] = i*pows10[i - 1];
	}
}
int f(int a, int d)
{
	int ret = 0;
	sprintf(str, "%d", a);
	int len = strlen(str);//len表示数字的位数
	int pre[10] = { 0 };
	for (int i = 1; i <= len; i++)pre[i] = pre[i - 1] + (str[i - 1] == '0' + d);//数字a的i位之前有多少个d
	ret = p[len - 1];
	if (d == 0 && len > 2) {
		for (int i = 1; i <= len - 2; i++) {
			ret -= pows10[len - i-1];
		}
	}
	for (int i = 0; i < len; i++) {//第i位固定
		int st = i == 0 && len > 1;
		for (int j = st; j < str[i] - '0'; j++) {
			ret += p[len - i - 1];
			if (j == d)ret += pows10[len - i - 1];
			ret += pows10[len - i - 1] * pre[i];
		}
	}
	return ret + pre[len];
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	init();
	while (scanf("%d%d", &a, &b) == 2&&a) {
		if (b < a)swap(a, b);
		printf("%d", f(b, 0) - f(a - 1, 0));
		for (int i = 1; i <= 9; i++) {
			printf(" %d", f(b, i) - f(a - 1, i));
		}
		printf("\n");
	}
}
