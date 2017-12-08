#include<bits/stdc++.h>
using namespace std;
struct node {
	int l, r;
	bool operator<(const node&a)const {
		return l < a.l || l == a.l&&r < a.r;
	}
}p[100006];
int T, n;
int main()
{
	scanf("%d", &T);
	while (T--) {
		int cnt = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)scanf("%d%d", &p[i].l, &p[i].r);
		sort(p, p + n);
		int cur = p[0].r;
		for (int i = 1; i < n; i++) {
			if (cur < p[i].l)cnt++, cur = p[i].r;
			else if (cur < p[i].r)cur++;
		}
		printf("%d\n", cnt);
	}
}
