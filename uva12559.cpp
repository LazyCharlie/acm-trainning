#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
struct circle {
	int x, y, r;
	circle(int xx = 0, int yy = 0, int rr = 0) :x(xx), y(yy), r(rr) {}
	bool operator<(const circle &a)const {
		if (r != a.r)return r < a.r;
		if (x != a.x)return x < a.x;
		return y < a.y;
	}
};
vector<circle>ans;
int n, m, T, cnt;
char G[105][105];
vector<pair<int, int>>L[52];
bool cross(int x, int y, int r)
{
	double a = hypot(x - 0.5, y - 0.5);
	double w = hypot(x - 0.5, y + 0.5);
	double s = hypot(x + 0.5, y - 0.5);
	double d = hypot(x + 0.5, y + 0.5);
	return (a < r || w < r || s < r || d < r) && (a > r || w > r || s > r || d > r);
}
void init()
{
	rep(r, 5, 51) {
		rep(x, -r, r + 1) {
			rep(y, -r, r + 1) {
				double R = hypot(x, y);
				if ((int)floor(R + 0.5) == r || cross(x, y, r)) {
					L[r].push_back({ x,y });
				}
			}
		}
	}
}
int main()
{
	init();
	scanf("%d", &T);
	while (T--) {
		ans.clear();
		printf("Case %d: ", ++cnt);
		scanf("%d%d", &n, &m);//m行n列
		rep(i, 0, m) {
			scanf("%s", G[i]);
		}
		rep(x, 5, n - 5) {
			rep(y, 5, m - 5) {
				int maxr = min(min(x, y), min(n - x - 1, m - y - 1));
				rep(r, 5, maxr + 1) {
					int c = 0, ct = 0;
					for (auto S : L[r]) {
						if (G[S.second + y][S.first + x] == '1')c++;
						else ct++;
						if (ct * 100 > 5 * L[r].size())break;//加速判断
					}
					if (c * 100 >= 95 * L[r].size())ans.push_back(circle(x, y, r));
				}
			}
		}
		sort(ans.begin(), ans.end());
		printf("%d", ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf(" (%d,%d,%d)", ans[i].r, ans[i].x, ans[i].y);
		}
		printf("\n");
	}
}
