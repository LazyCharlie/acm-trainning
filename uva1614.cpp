#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
struct node {
	int x, id; 
	bool operator<(const node &a)const {
		return x < a.x;
	}
}a[maxn];
int n, ans[maxn];
long long sum;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d", &n) == 1) {
		sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i].x);
			a[i].id = i;
			sum += a[i].x;
		}
		if (sum & 1) {
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		sum >>= 1;
		sort(a + 1, a + n + 1);
		for (int i = n; i >= 1; i--) {
			if (sum - a[i].x >= 0) {
				sum -= a[i].x;
				ans[a[i].id] = 1;
			}
			else ans[a[i].id] = -1;
		}
		for (int i = 1; i <= n; i++) {
			printf("%d%c", ans[i], i == n ? '\n' : ' ');
		}
	}
}
