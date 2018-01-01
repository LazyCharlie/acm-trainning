#include<bits/stdc++.h>
using namespace std;
int T, a, b, c, n;
int cur = 0;
void step(int dis) {
	cur += dis;
	printf(" %d", cur);
}
void walk(int pa, int pb, int ad, int bd) {
	int cnt = c / 3;
	for (int i = 0; i < cnt + (c % 3 > 0); i++)step(3);
	step(pa);
	for (int i = 0; i < cnt; i++)step(-3);
	step(pb);
	for (int i = 0; i < cnt + (c % 3 == 2); i++)step(3);
	a -= ad;
	b -= bd;
	if (c % 3 == 1)step(2);
}
int main()
{
	freopen("jumping.in", "r", stdin);
	freopen("jumping.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		printf("0");
		scanf("%d%d%d", &a, &b, &c);
		cur = 0;
		n = a + b + c;
		if (c % 3 == 0 && c) {
			walk(1, 1, 2, 0);
		}
		if (c % 3 == 1) {
			walk(-2, 1, 1, 2);
		}
		if (c % 3 == 2) {
			walk(-1, -1, 2, 0);
		}
		while (a > 1)step(1), a--;
		while (cur + 2 <= n&&b > 0)step(2), b--;
		if (a) {
			if (cur + 1 <= n) {
				step(1);
			}
			else step(-1);
		}
		for (int i = 0; i < b; i++)step(-2);
		printf("\n");
	}
}
