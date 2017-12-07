#include<bits/stdc++.h>
using namespace std;
int n;
char table[1030][1030];
vector<int>win, lose;
int main()
{
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; i++) {
			scanf("%s", table[i] + 1);
		}
		for (int i = 2; i <= n; i++) {
			if (table[1][i] == '1')win.push_back(i);
			else lose.push_back(i);
		}
		int cur = n;
		while (cur > 1) {
			vector<int>win2, lose2, final;
			for (int i = 0; i < lose.size(); i++) {
				int ok = 0;
				for (int j = 0; j < win.size(); j++) {
					if (!win[j])continue;
					if (table[win[j]][lose[i]] == '1') {
						printf("%d %d\n", lose[i], win[j]);
						win2.push_back(win[j]);
						win[j] = 0;
						ok = 1;
						break;
					}
				}
				if (!ok)final.push_back(lose[i]);
			}
			int ok = 0;
			for (int i = 0; i < win.size(); i++) {
				if (!win[i])continue;
				if (!ok) {
					printf("1 %d\n", win[i]);
					ok = 1;
				}
				else final.push_back(win[i]);
			}
			for (int i = 0; i < final.size(); i += 2) {
				printf("%d %d\n", final[i], final[i + 1]);
				if (table[final[i]][final[i + 1]] == '1') {
					if (table[1][final[i]] == '1')win2.push_back(final[i]);
					else lose2.push_back(final[i]);
				}
				else {
					if (table[1][final[i + 1]] == '1')win2.push_back(final[i + 1]);
					else lose2.push_back(final[i + 1]);
				}
			}
			win = win2;
			lose = lose2;
			cur >>= 1;
		}
	}
}
