#include<bits/stdc++.h>
using namespace std;
int L, R;
long long h[1005], maxn;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d%d", &L, &R) == 2 && L) {
		maxn = 0;
		for (int i = L; i <= R; i += 2) {
			scanf("%lld", &h[(i - L) / 2]);
		}
		int Ld = (-1 - L) / 2, Rd = Ld + 1;
		for (int i = -1; i >= L; i -= 2) {
			if (h[(i - L) / 2] > h[Ld])Ld = (i - L) / 2;
		}
		for (int i = 1; i <= R; i += 2) {
			if (h[(i - L) / 2] > h[Rd])Rd = (i - L) / 2;
		}
		long long Left = 0, right = 0;
		int id = (R - L) / 2 + 1 , preh = 0;
		h[id] = 0;
		for (int i = (R - L) / 2; i >= Rd; i--) {
			if (id > (R - L) / 2 || h[i] >= h[id]) {
				right += h[id] * (id - i) * 2;
				id = i;
			}
		}
		id = -1;
		for (int i = 0; i <= Ld; i++) {
			if (id < 0 || h[i] >= h[id]) {
				Left += (id < 0 ? 0 : h[id])*(i - id) * 2;
				id = i;
			}
		}
		if (h[Ld] < h[Rd]) {
			long long extra = 0;
			int flag = 0;
			for (int i = (1 - L) / 2; i <= (R - L) / 2; i++) {
				if (h[i] > h[Ld]) {
					extra = (i - Ld) * 2 * h[Ld];
					if (flag)extra = min(Left, (i - flag)*h[flag] * 2) + (flag - Ld) * 2 * h[Ld];
					break;
				}
				else if (h[i] == h[Ld] && !flag) {
					flag = i;
				}
			}
			printf("%lld\n", Left + extra);
		}
		else if (h[Ld] > h[Rd]) {
			long long extra = 0;
			int flag = 0;
			for (int i = (-1 - L) / 2; i >= 0; i--) {
				if (h[i] > h[Rd]) {
					if (flag)extra = (Rd - flag) * 2 * h[Rd]+ min(right, (flag - i)*h[flag] * 2);
					else extra = (Rd - i) * 2 * h[Rd];
					break;
				}
				else if (h[i] == h[Rd] && !flag) {
					flag = i;
				}
			}
			printf("%lld\n", right + extra);
		}
		else printf("%lld\n", h[Ld] * (Rd - Ld) * 2 + min(Left, right) * 2);
	}
}
