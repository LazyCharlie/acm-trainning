#include<bits/stdc++.h>
using namespace std;
int n, m[100006];
int main()
{
	scanf("%d", &n);
	for (int i=0; i < n; i++)scanf("%d", &m[i]);
	deque<int>S;
	for (int i = n - 1; i >= 0; i--) {
		while (S.size() && m[S.back()] < m[i])S.pop_back();
		S.push_back(i);
	}
	long long ans = 0;
	int cur = m[S.front()];
	for (int i = n - 1; i >= 0; i--) {
		if (S.size())ans += cur - m[i];
		if (S.size()&&i == S.front())S.pop_front();
		if (S.size()&&m[S.front()] < cur)cur--;
	}
	printf("%lld", ans);
}
