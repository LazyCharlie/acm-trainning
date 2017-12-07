#include<bits/stdc++.h>
using namespace std;
int n, T;
struct node {
	int d, p;
	bool operator<(const node&a)const {
		return p < a.p;
	}
}a[800006];
bool cmp(const node&a, const node &b) {
	return a.d < b.d;
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].p, &a[i].d);
		}
		sort(a, a + n, cmp);
		priority_queue<node>q;
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (sum + a[i].p <= a[i].d)sum += a[i].p, q.push(a[i]);
			else if (sum + a[i].p > a[i].d&&q.size() && a[i].p < q.top().p) {
				sum -= q.top().p;
				q.pop();
				q.push(a[i]);
				sum += a[i].p;
			}
		}
		printf("%d\n", q.size());
		if (T)printf("\n");
	}
}
