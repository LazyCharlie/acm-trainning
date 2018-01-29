#include<bits/stdc++.h>
using namespace std;
struct node {
	int x, y;
}p[10006];
const int dx[6] = { 0,-1 ,-1,0,1,1};//¡ý¨L¨I¡ü¨J¨K
const int dy[6] = { -2,-1,1,2,1,-1 };
int r[6] = { 1,0,1,1,1,1 };
int a, b;
void init()
{
	int xx = 0, yy = 0;
	int cur = 1;
	int q = 1, pt = 0;
	while (cur < 10000) {
		for (int i = 1; i < r[pt] + q; i++) {
			xx += dx[pt];
			yy += dy[pt];
			p[++cur] = { xx,yy };
		}
		pt++;
		if (pt == 6) {
			q++;
			pt = 0;
		}
	}
}
int main()
{
	init();
	while (scanf("%d%d", &a, &b) == 2 && a) {
		int x = abs(p[a].x - p[b].x);
		int y = abs(p[b].y - p[a].y);
		y -= x;
		if (y < 0)y = 0;
		printf("The distance between cells %d and %d is %d.\n", a, b, x + y / 2);
	}
}

