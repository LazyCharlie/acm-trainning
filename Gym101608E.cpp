#include<bits/stdc++.h>
using namespace std;
struct node {
	int x, y, dir;
};
int T, r, c, q, sr, sc;
char o[5];
char m[506][506];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int sw[256];
vector<node> path;
node move(int x, int y, int turn)
{
	node ret;
	for (int i = 0; i < 4; i++) {
		ret.dir = (turn + i) % 4;
		ret.x = x + dx[ret.dir];
		ret.y = y + dy[ret.dir];
		if (m[ret.y - 1][ret.x - 1] == '.') {
			break;
		}
	}
	return ret;
}
int main()
{
	freopen("reduce.in", "r", stdin);
	sw['U'] = 0; sw['R'] = 1; sw['D'] = 2; sw['L'] = 3;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &r, &c, &q);
		scanf("%d%d", &sr, &sc);
		scanf("%s", o);
		path.clear();
		int py = sr, px = sc, dir = sw[o[0]];
		for (int i = 0; i < r; i++) scanf("%s", m[i]);
		for (int i = 0; i < q; i++) {
			char ord[5];
			scanf("%s", ord);
			if (ord[0] == 'R')dir = (dir + 1) % 4;
			else {
				int step;
				scanf("%d", &step);
				while (step--) {
					path.push_back(move(px, py, dir));
					px = path.back().x;
					py = path.back().y;
					dir = path.back().dir;
				}
			}
		}
		int step = 0;
		int ans = 0;
		py = sr, px = sc, dir = sw[o[0]];
		while (step < path.size()) {
			node tmp = move(px, py, dir);
			if (tmp.x == path[step].x&&tmp.y == path[step].y) {
				ans++;
				while (step < path.size()&& tmp.x == path[step].x&&tmp.y == path[step].y) {
					px = tmp.x; py = tmp.y; dir = tmp.dir;
					tmp = move(px, py, dir);
					step++;
				}
			}
			else {
				ans++;
				dir = (dir + 1) % 4;
			}
		}
		printf("%d\n", ans);
	}
}
