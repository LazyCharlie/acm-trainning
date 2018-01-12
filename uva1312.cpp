#include<bits/stdc++.h>
using namespace std;
struct node {
	int x, y;
	bool operator<(const node &a)const
	{
		return x == a.x&&y < a.y || x < a.x;
	}
}p[106];
int dy[106];
int T, N, W, H, ansX, ansY, ans;
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &W, &H);
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &p[i].x, &p[i].y);
			dy[i] = p[i].y;
		}
		dy[N] = 0;
		dy[N + 1] = H;
		sort(p, p + N);
		sort(dy, dy + N + 2);
		ans = 1;
		for (int i = 0; i < N + 2; i++) {
			for (int j = i + 1; j < N + 2; j++) {
				if (dy[j] - dy[i] <= ans)continue;
				int miny = dy[i], maxy = dy[j];
				int pre = 0;
				for (int k = 0; k < N; k++) {
					if (p[k].y <= miny || p[k].y >= maxy)continue;
					if (p[k].x - pre > ans&&dy[j] - dy[i] > ans) {
						ans = min(p[k].x - pre, dy[j] - dy[i]);
						ansX = pre;
						ansY = miny;
					}
					pre = p[k].x;
				}
				if (W - pre > ans&&dy[j] - dy[i] > ans) {
					ans = min(W - pre, dy[j] - dy[i]);
					ansX = pre;
					ansY = miny;
				}
			}
		}
		printf("%d %d %d\n", ansX, ansY, ans);
		if (T)printf("\n");
	}
}
