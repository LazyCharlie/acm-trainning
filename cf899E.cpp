#include<bits/stdc++.h>
using namespace std;
const int maxn = 200006;
struct node {
	int num, cnt, id;
	bool operator<(const node &a)const
	{
		if (cnt == a.cnt)return a.id < id;
		return cnt < a.cnt;
	}
	bool operator==(const node &a)const
	{
		return num == a.num&&cnt == a.cnt&&id == a.id;
	}
}d[maxn];
int tmp, n, pre;
int L[maxn], R[maxn], cnt;
priority_queue<node>que, del;
int main()
{
	scanf("%d", &n);
	pre = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp != pre) {
			L[cnt + 1] = cnt;
			R[cnt] = cnt + 1;
			++cnt;
			d[cnt].id = cnt;
			d[cnt].num = tmp;
			pre = tmp;
		}
		d[cnt].cnt++;
	}
	R[cnt] = cnt + 1;
	L[cnt + 1] = cnt;
	for (int i = 1; i <= cnt; i++)que.push(d[i]);
	int ans = 0;
	while (R[0] != cnt + 1) {
		while (del.size() && del.top() == que.top())del.pop(), que.pop();
		node t = que.top();
		que.pop();
		int l = L[t.id];
		int r = R[t.id];
		R[l] = r;
		L[r] = l;
		if (d[l].num == d[r].num&&l&&r < cnt + 1) {
			del.push(d[l]);
			del.push(d[r]);
			d[l].cnt += d[r].cnt;
			que.push(d[l]);
			R[l] = R[r];
			L[R[r]] = l;
		}
		ans++; 
	}
	printf("%d", ans);
}
