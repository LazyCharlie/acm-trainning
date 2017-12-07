#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[10006];
pair<int, int> ans[20006];
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int pos;
			for (int j = i; j <= n; j++) {
				if (a[j] == i) {
					pos = j;
					break;
				}
			}
			int len = n - i + 1;
			if (pos > len / 2 + i) {
				int st = (len & 1) ? i + 1 : i;
				ans[cnt++] = { st,n };
				for (int j = 0; j < len / 2; j++) {
					swap(a[st + j], a[st + j + len / 2]);
				}
				pos -= len / 2;
			}
			if (pos != i) {
				ans[cnt++] = { i,pos * 2 - i - 1 };
				for (int j = 0; j < pos - i; j++) {
					swap(a[i + j], a[pos + j]);
				}
			}
		}
		printf("%d\n", cnt);
		for(int i=0;i<cnt;i++)printf("%d %d\n",ans[i].first,ans[i].second);
	}
}
