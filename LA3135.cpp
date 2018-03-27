#include<bits/stdc++.h>
using namespace std;
struct node {
	int t, x, cur;
	bool operator<(const node &a)const {
		if (cur != a.cur)return cur > a.cur;
		return x > a.x;
	}
}tmp;
priority_queue<node>q;
int Q, P, T;
char s[100];
int main()
{
	int cnt = 0;
	while (scanf("%s", s) == 1 && s[0] != '#') {
		scanf("%d%d", &tmp.x, &tmp.t);
		tmp.cur = tmp.t;
		q.push(tmp);
	}
	scanf("%d", &T);
	while (T--) {
		tmp = q.top();
		q.pop();
		printf("%d\n", tmp.x);
		tmp.cur += tmp.t;
		q.push(tmp);
	}
}
