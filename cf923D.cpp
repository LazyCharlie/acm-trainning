#include<bits/stdc++.h>
using namespace std;
char S[100000 + 5], T[100000 + 5];
int Sa[100000 + 5], Sb[100000 + 5], Ta[100000 + 5], Tb[100000 + 5], tailS[100000 + 5], tailT[100000 + 5];
int Q, a, b, c, d;//B可以凭空成双产生
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%s%s", S + 1, T + 1);
	int lenS = strlen(S + 1);
	int lenT = strlen(T + 1);
	scanf("%d", &Q);
	for (int i = 1; i <= lenS; i++) {
		Sa[i] = Sa[i - 1] + (S[i] == 'A');
		Sb[i] = Sb[i - 1] + (S[i] != 'A');
		if (S[i] == 'A')tailS[i] = tailS[i - 1] + 1;
		else tailS[i] = 0;
	}
	for (int i = 1; i <= lenT; i++) {
		Ta[i] = Ta[i - 1] + (T[i] == 'A');
		Tb[i] = Tb[i - 1] + (T[i] != 'A');
		if (T[i] == 'A')tailT[i] = tailT[i - 1] + 1;
		else tailT[i] = 0;
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int ans = 1;
		int diffb = Tb[d] - Tb[c - 1] - Sb[b] + Sb[a - 1];
		int tS = min(b - a + 1, tailS[b]);
		int tT = min(d - c + 1, tailT[d]);
		if (diffb < 0 || tT - tS>0 || diffb % 2 == 1)ans = 0;
		int remain = (tS - tT) % 3 > 0;
		if (diffb - remain * 2 < 0)ans = 0;
		if (Sb[b] - Sb[a - 1] == 0 && diffb&&tS == tT)ans = 0;
		printf("%d", ans);
	}
}
