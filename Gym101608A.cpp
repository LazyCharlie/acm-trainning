#include<bits/stdc++.h>
using namespace std;
int T, n, k;
int main()
{
	freopen("tabs.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		if (n == 1)printf("0\n");
		else if (k == 1 || k == n)printf("1\n");
		else printf("2\n");
	}
}
