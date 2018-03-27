#include<bits/stdc++.h>
using namespace std;
int p[100005], a, b;
int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}
int main()
{
	while (scanf("%d%d",&a,&b) == 2) {
		for (int i = 0; i <= 100000; i++)p[i] = i;
		int fa = find(a);
		int fb = find(b);
		int ans = 0;
		if (fa != fb) p[fa] = fb;
		else ans++;
		while (scanf("%d", &a) == 1 && a >= 0) {
			scanf("%d", &b);
			fa = find(a);
			fb = find(b);
			if (fa != fb)p[fa] = fb;
			else ans++;
		}
		printf("%d\n", ans);
	}
}
