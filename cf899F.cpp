#include<bits/stdc++.h>
using namespace std;
int n, m;
set<int>M[256];
char s[200006];
int tree[200006], vis[200006];
int LL, RR;
char ch;
int lowbit(int x) { return x&(-x); }
void add(int x, int y)
{
	for (int i = x; i <= n; i += lowbit(i))tree[i] += y;
}
int getsum(int x)
{
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))ans += tree[i];
	return ans;
}
int search(int pos)
{
	int L = 1, R = n;
	while (L < R) {
		int mid = L + (R - L) / 2;
		int tmp = getsum(mid);
		if (tmp < pos)L = mid + 1;
		else R = mid;
	}
	return L;
}
void del(int Lpos, int Rpos, char ch)
{
	auto it = M[ch].lower_bound(Lpos);
	while (it != M[ch].end() && *it <= Rpos) {
		vis[*it] = 1;
		add(*it,-1);
		it = M[ch].erase(it);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)add(i, 1), M[s[i]].insert(i);
	for (int i = 0; i < m; i++) {
		cin >> LL >> RR >> ch;
		int l = search(LL);
		int r = search(RR);
		del(l, r, ch);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i])printf("%c", s[i]);
	}
}
