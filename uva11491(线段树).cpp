#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, d;
char s[maxn];
struct pii {
	int x, y;
	bool operator<(const pii&a)const {
		if (a.x != x)return x < a.x;
		else return a.y < y;
	}
};
pii tree[maxn << 2];
void build(int x, int L, int R)
{
	if (L == R) {
		tree[x].x = s[L] - '0';
		tree[x].y = L;
		return;
	}
	int mid = L + R >> 1;
	build(x << 1, L, mid);
	build(x << 1 | 1, mid + 1, R);
	tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
}
pii query(int x, int L, int R, int ls, int rs)
{
	if (L == ls&&R == rs) {
		return tree[x];
	}
	int mid = L + R >> 1;
	if (rs <= mid)return query(x<<1, L, mid, ls, rs);
	else if (ls >= mid + 1)return query(x<<1|1, mid + 1, R, ls, rs);
	return max(query(x<<1, L, mid, ls, mid), query(x<<1|1, mid + 1, R, mid + 1, rs));
}
int main()
{
	while (scanf("%d%d", &n, &d) == 2 && n) {
		scanf("%s", s+1);
		build(1, 1, n);
		int cur = 1, len = d;
		for (int i = 0; i < n - d; i++) {
			pii ans = query(1, 1, n, cur, cur + len);
			len -= ans.y - cur;
			printf("%d", ans.x);
			cur = ans.y + 1;
		}
		printf("\n");
	}
}

