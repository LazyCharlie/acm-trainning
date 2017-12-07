#include<bits/stdc++.h>
using namespace std;
deque<int>q;
char ans[1000000];
int n, t, p;
int main()
{
	while (scanf("%d", &n) == 1 && n) {
		q.clear();
		p = -1;
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);
			q.push_back(t);
		}
		for (int i = n; i >= 1; i--) {
			while (q.front() != i) {
				ans[++p] = '2';
				int b = q.back();
				q.pop_back();
				q.push_front(b);
			}
			if (i < n) {
				int ok = 0;
				while (!ok) {
					int t1 = q.front(); q.pop_front();
					int t2 = q.back();
					q.pop_back();
					q.push_front(t2);
					q.push_front(t1);
					ans[++p] = '2';
					ans[++p] = '1';
					if (t2 == i + 1)ok = 1;
				}
			}
		}
		for (int i = p; i >= 0; i--)printf("%c", ans[i]);
		printf("\n");
	}
}
