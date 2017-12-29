#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
int n, rear;
long long sum[N], a[N], ans;
int p[N], L[N], R[N];
int rL, rR;
int cnt;
int main()
{
	//freopen("feelgood.in", "r", stdin);
	//freopen("feelgood.out", "w", stdout);
	while (scanf("%d", &n) == 1 && n) {
		if (cnt++)printf("\n");
		int rear = -1;
		for (int i = 1; i <= n; i++)scanf("%lld", &a[i]);
		ans = -1;
		for (int i = 1; i <= n; i++)sum[i] = sum[i - 1] + a[i];
		for (int i = 1; i <= n; i++) {
			while (rear >= 0 && a[p[rear]] >= a[i])rear--;
			if (rear < 0)L[i] = 1;
			else L[i] = p[rear] + 1;
			p[++rear] = i;
		}
		rear = -1;
		for (int i = n; i >= 1; i--) {
			while (rear >= 0 && a[p[rear]] >= a[i])rear--;
			if (rear < 0)R[i] = n;
			else R[i] = p[rear] - 1;
			p[++rear] = i;
		}
		for (int i = 1; i <= n; i++) {
			long long v = (sum[R[i]] - sum[L[i] - 1])*a[i];
			if (v > ans || (v == ans&&rR - rL > R[i] - L[i])) {
				ans = (sum[R[i]] - sum[L[i] - 1])*a[i];
				rL = L[i];
				rR = R[i];
			}
		}
		printf("%lld\n%d %d\n", ans, rL, rR);
	}
}
