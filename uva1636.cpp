#include<bits/stdc++.h>
using namespace std;
char s[105];
int main()
{
	while (scanf("%s", s+1) == 1) {
		int len = strlen(s + 1);
		int block = 0, tot = 0, pre = -1;
		for (int i = 1; i <= len; i++) {
			if (s[i] == '0'&&s[i%len + 1] == '0')block++;
			if (s[i] == '0')tot++;
		}
		if (tot*tot > block*len)printf("ROTATE\n");
		else if (tot*tot < block*len)printf("SHOOT\n");
		else printf("EQUAL\n");
	}
}
