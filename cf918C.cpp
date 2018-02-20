#include<bits/stdc++.h>
using namespace std;
char s[5005];
int L[5005][5005];
int main()
{
	int ans = 0;
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		int l = 0, q = 0;
		for (int j = i; j < len; j++) {
			if (s[j] == '(')l++;
			else if (s[j] == ')') {
				if (q && !l)q--;
				else l--;
			}
			else q++;
			if (l < 0)break;
			if (q >= l && (l + q) % 2 == 0)L[i][j] = 1;
		}
	}
	for (int i = len - 1; i >= 0; i--) {
		int r = 0, q = 0;
		for (int j = i; j >= 0; j--) {
			if (s[j] == ')')r++;
			else if (s[j] == '(') {
				if (q && !r)q--;
				else r--;
			}
			else q++;
			if (r < 0)break;
			if (q >= r && (r + q) % 2==0 && L[j][i])ans++;
		}
	}
	printf("%d\n", ans);
}
