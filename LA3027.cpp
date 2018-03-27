#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 5;
char s[5];
int T, n, d[maxn], p[maxn], a, b;
int find(int x)
{
	if (x != p[x]) {
		int fx = find(p[x]);
		d[x] += d[p[x]];
		p[x] = fx;
	}
	return p[x];
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)d[i] = 0, p[i] = i;
		while (scanf("%s", s) == 1 && s[0] != 'O') {
			if (s[0] == 'E') {
				scanf("%d", &a);
				find(a);
				printf("%d\n", d[a]);
			}
			else {
				scanf("%d%d", &a, &b);
				p[a] = b;
				d[a] = abs(a - b) % 1000;
			}
		}
	}
}
