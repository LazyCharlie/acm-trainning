#include<bits/stdc++.h>
using namespace std;
struct step {
	int l, r, o;
}ans[80][4][4][5];
char s[80], res[80];
int d[80][4][4][5];//0表示没有动，1表示左脚踩，2表示右脚踩，3表示左脚移动，4表示右脚移动
int o[256];
int score(int x, int y) 
{
	if (x == y)return 3;
	if ((x + 2) % 4 == y)return 7;
	return 5;
}
void mov(int i, int l, int r, int p, int nl, int nr, int np)
{
	int mark = 0;
	if (np == 1 || np == 3) {
		if (p == 0 || p == 2 || p == 4)mark = 1;
		else mark = score(l, nl);
	}
	else if (np == 2 || np == 4) {
		if (p == 0 || p == 1 || p == 3)mark = 1;
		else mark = score(r, nr);
	}
	if (d[i + 1][nl][nr][np] > d[i][l][r][p] + mark) {
		d[i + 1][nl][nr][np] = d[i][l][r][p] + mark;
		step & res = ans[i + 1][nl][nr][np];
		res.l = l;
		res.r = r;
		res.o = p;
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	o['U'] = 0, o['L'] = 1, o['D'] = 2, o['R'] = 3, o['.'] = 4;
	while (scanf("%s", s) == 1 && s[0] != '#') {
		int len = strlen(s);
		memset(d, 0x3f, sizeof(d));
		d[0][1][3][0] = 0;
		for (int i = 0; i < len; i++) {
			int c = o[s[i]];
			for (int l = 0; l < 4; l++) {
				for (int r = 0; r < 4; r++) {
					if (l == r)continue;
					for (int p = 0; p < 5; p++) {
						if (c == 4)mov(i, l, r, p, l, r, 0);
						if (l != c) {//左脚无动作
							if (r == c)mov(i, l, r, p, l, r, 2);
							if (((r + 2) % 4 == c || c == 4 && (r + 2) % 4 != l) && l != 3)mov(i, l, r, p, l, (r + 2) % 4, 4);
							if (((r + 1) % 4 == c || c == 4 && (r + 1) % 4 != l) && l != 3)mov(i, l, r, p, l, (r + 1) % 4, 4);
							if (((r + 3) % 4 == c || c == 4 && (r + 3) % 4 != l) && l != 3)mov(i, l, r, p, l, (r + 3) % 4, 4);
						}
						if (r != c) {//右脚无动作
							if (l == c)mov(i, l, r, p, l, r, 1);//左脚踩
							if (((l + 2) % 4 == c || c == 4 && (l + 2) % 4 != r) && r != 1)mov(i, l, r, p, (l + 2) % 4, r, 3);//左脚移动到对面（确保右脚不在左）
							if (((l + 1) % 4 == c || c == 4 && (l + 1) % 4 != r) && r != 1)mov(i, l, r, p, (l + 1) % 4, r, 3);//左脚移动到相邻位置（确保右脚不在左）
							if (((l + 3) % 4 == c || c == 4 && (l + 3) % 4 != r) && r != 1)mov(i, l, r, p, (l + 3) % 4, r, 3);//左脚移动到相邻位置（确保右脚不在左）
						}
					}
				}
			}
		}
		int l = 0, r = 0, k = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int p = 0; p < 5; p++) {
					if (d[len][l][r][k] > d[len][i][j][p]) {
						l = i, r = j, k = p;
					}
				}
			}
		}
		//cout << d[len][l][r][k] << "\n";
		res[len] = '\0';
		for (int i = len; i > 0; i--) {
			step&tmp = ans[i][l][r][k];
			if (k == 0) {
				res[i - 1] = '.';
			}
			else if (k & 1) {
				res[i - 1] = 'L';
			}
			else res[i - 1] = 'R';
			l = tmp.l;
			r = tmp.r;
			k = tmp.o;
		}
		printf("%s\n", res);
	}
}
