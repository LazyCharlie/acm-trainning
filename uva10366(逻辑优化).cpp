#include<bits/stdc++.h>
using namespace std;
int T, L, R;
long long h[1006], ans;
long long & H(int x)
{
	return h[(x - L) / 2 + 1];
}
int main()
{
	while (scanf("%d%d", &L, &R) == 2 && L) {
		
		for (int i = L; i <= R; i += 2) {
			scanf("%d", &H(i));
		}
		H(R + 2) = 0;
		int Lx = 0, Rx = 0;
		for (int i = -1; i >= L; i -= 2) {
			if (!Lx || H(Lx) < H(i))Lx = i;
		}
		for (int i = 1; i <= R; i += 2) {
			if (!Rx || H(Rx) < H(i))Rx = i;
		}
		int id = L - 2;
		long long Left = 0, Right = 0;
		for (int i = L; i <= Lx; i+=2) {
			if (H(id) <= H(i))Left += (i - id)*H(id), id = i;
		}
		id = R + 2;
		for (int i = R; i >= Rx; i-=2) {
			if (H(id) <= H(i))Right += (id - i)*H(id), id = i;
		}
		if (H(Lx) > H(Rx)) {
			int equal = 0, big = 0;
			for (int i = -1; i >= Lx; i -= 2) {
				if (H(i) == H(Rx) && !equal) {
					equal = i;
				}
				if (H(i) > H(Rx)) {
					big = i;
					break;
				}
			}
			if (equal)printf("%lld\n", Right + (Rx - equal)*H(Rx) + min(Right, (equal - big)*H(equal)));
			else printf("%lld\n", Right + (Rx - big)*H(Rx));
		}
		if (H(Lx) < H(Rx)) {
			int equal = 0, big = 0;
			for (int i = 1; i <= Rx; i += 2) {
				if (H(i) == H(Lx) && !equal) {
					equal = i;
				}
				if (H(i) > H(Lx)) {
					big = i;
					break;
				}
			}
			if (equal)printf("%lld\n", Left + (equal-Lx)*H(Lx) + min(Left, (big - equal)*H(equal)));
			else printf("%lld\n", Left + (big - Lx)*H(Lx));
		}
		if (H(Lx) == H(Rx)) {
			printf("%lld\n", (Rx - Lx)*H(Lx) + min(Left, Right) * 2);
		}
	}
}
