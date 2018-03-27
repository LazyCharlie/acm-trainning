#include<bits/stdc++.h>
using namespace std;
#define a first
#define b second
typedef long long LL;
struct node {
	pair<int, int> L, R, sub;
}tree[500006];
int n, m;
LL D[500006], C[500006];
LL sum(int L, int R) {
	return C[R] - C[L - 1];
}
pair<int, int> better(pair<int, int>x, pair<int, int>y)
{
	if (sum(x.a, x.b) != sum(y.a, y.b))return sum(x.a, x.b) > sum(y.a, y.b) ? x : y;
	return x < y ? x : y;
}
void build(int x, int L, int R)
{
	if (L == R) {
		tree[x].L.a = tree[x].L.b = L;
		tree[x].R.a = tree[x].R.b = L;
		tree[x].sub.a = tree[x].sub.b = L;
		return;
	}
	int mid = L + R >> 1;
	build(x << 1, L, mid);
	build(x << 1 | 1, mid + 1, R);
	tree[x].L.a = L, tree[x].L.b = tree[x << 1].L.b;
	tree[x].R.b = R, tree[x].R.a = tree[x << 1 | 1].R.a;
	tree[x].sub = better(tree[x << 1].sub, tree[x << 1 | 1].sub);
	if (sum(L, tree[x << 1 | 1].L.b) > sum(L, tree[x].L.b))tree[x].L.b = tree[x << 1 | 1].L.b;
	if (sum(tree[x << 1].R.a, R) >= sum(tree[x].R.a, R))tree[x].R.a = tree[x << 1].R.a;
	tree[x].sub = better(make_pair(tree[x << 1].R.a, tree[x << 1 | 1].L.b), tree[x].sub);
}
pair<int, int> query_prefix(int x, int L, int R, int ls, int rs)
{
	if (L == ls&&R == rs) {
		return tree[x].L;
	}
	int mid = L + R >> 1;
	if (rs <= mid)return query_prefix(x << 1, L, mid, ls, rs);
	else if (ls >= mid + 1)return query_prefix(x << 1 | 1, mid + 1, R, ls, rs);
	else {
		pair<int, int>qL = query_prefix(x << 1, L, mid, ls, mid);
		pair<int, int>qR = query_prefix(x << 1 | 1, mid + 1, R, mid + 1, rs);
		return better(qL, make_pair(ls, qR.b));
	}
}
pair<int, int> query_suffix(int x, int L, int R, int ls, int rs)
{
	if (L == ls&&R == rs) {
		return tree[x].R;
	}
	int mid = L + R >> 1;
	if (rs <= mid)return query_suffix(x << 1, L, mid, ls, rs);
	else if (ls >= mid + 1)return query_suffix(x << 1 | 1, mid + 1, R, ls, rs);
	else {
		pair<int, int>qL = query_suffix(x << 1, L, mid, ls, mid);
		pair<int, int>qR = query_suffix(x << 1 | 1, mid + 1, R, mid + 1, rs);
		return better(qR, make_pair(qL.a, rs));
	}
}
pair<int, int> query(int x, int L, int R, int ls, int rs) {
	if (L == ls&&R == rs) {
		return tree[x].sub;
	}
	int mid = L + R >> 1;
	if (rs <= mid)return query(x << 1, L, mid, ls, rs);
	else if (ls >= mid + 1)return query(x << 1 | 1, mid + 1, R, ls, rs);
	else {
		pair<int, int>Rl = query_suffix(x << 1, L, mid, ls, mid);
		pair<int, int>Lr = query_prefix(x << 1 | 1, mid + 1, R, mid + 1, rs);
		pair<int, int> ret = better(query(x << 1, L, mid, ls, mid), query(x << 1|1, mid + 1, R, mid + 1, rs));
		ret = better(ret, make_pair(Rl.a, Lr.b));
		return ret;
	}
}
int main()
{
	int cnt = 0;
	while (scanf("%d%d", &n, &m) == 2) {
		printf("Case %d:\n", ++cnt);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &D[i]);
			C[i] = C[i - 1] + D[i];
		}
		build(1, 1, n);
		for (int i = 0; i < m; i++) {
			int aa, bb;
			scanf("%d%d", &aa, &bb);
			pair<int, int>ans = query(1, 1, n, aa, bb);
			printf("%d %d\n", ans.a, ans.b);
		}
	}
}
