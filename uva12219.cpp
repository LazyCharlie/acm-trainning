#include<bits/stdc++.h>
using namespace std;
int T;
struct Node {
	int Lch, Rch, hash;
	string c;
	bool operator<(const Node &a)const {
		if (hash != a.hash)return hash < a.hash;
		else if (Lch != a.Lch)return Lch < a.Lch;
		else return Rch < a.Rch;
	}
}node[500005];
int vis[500005], kase;
map<Node, int>M;
char s[500005], *p;
int cnt;
int prase()
{
	int u = ++cnt;
	Node &tmp = node[u];
	tmp.c = "";
	tmp.Lch = tmp.Rch = -1;
	tmp.hash = 0;
	while (isalpha(*p)) {
		tmp.hash *= 27;
		tmp.hash += (*p - 'a' + 1);
		tmp.c.push_back(*p);
		p++;
	}
	if (*p == '(') {
		p++; tmp.Lch = prase(); p++; tmp.Rch = prase(); p++;
	}
	if (M.count(tmp)) {
		--cnt;
		return M[tmp];
	}
	return M[tmp] = u;
}
void print(int u)
{
	if (vis[u] == kase) {
		printf("%d", u);
	}
	else {
		vis[u] = kase;
		printf("%s", node[u].c.c_str());
		if (node[u].Lch != -1) {
			printf("(");
			print(node[u].Lch);
			printf(",");
			print(node[u].Rch);
			printf(")");
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		++kase;
		M.clear();
		cnt = 0;
		scanf("%s", s);
		p = s;
		print(prase());
		printf("\n");
	}
}
