#include<bits/stdc++.h>
using namespace std;
int T;
int n, a[505], cnt;
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		cnt = 0;
		for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[i] > a[j])cnt++;
			}
		}
		if ((cnt & 1) == 0 || (n & 1) == 0) {
			printf("possible\n");
		}
		else printf("impossible\n");
	}
}
