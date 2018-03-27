#include<bits/stdc++.h>
using namespace std;
int n;
char s[106];//Ьиеїa?a   Лђеп??
int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 1; i < n; i++) {
		if (s[i - 1] == s[i] && s[i] != '?') {
			printf("No\n");
			return 0;
		}
	}
	int ok = 0;
	if (s[0] == '?' || s[n - 1] == '?')ok = 1;
	for (int i = 1; i < n; i++) {
		if (i + 1 < n&&s[i - 1] != '?'&&s[i + 1] == s[i - 1] && s[i] == '?')ok = 1;
		if (s[i] == s[i - 1] && s[i] == '?')ok = 1;
	}
	printf(ok ? "Yes\n" : "No\n");
}
