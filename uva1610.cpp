#include<bits/stdc++.h>
using namespace std;
int n;
string s[1006];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		sort(s, s + n);
		int mid = n / 2 - 1;
		string ans;
		for (int i = 0; i < s[mid].size(); i++) {
			if (s[mid + 1].size() > i&&s[mid + 1][i] == s[mid][i]) {
				ans += s[mid][i];
			}
			else {
				if (s[mid][i] + 1 == s[mid + 1][i] && s[mid + 1].size() == i + 1) {//ABCC ABD
					ans += s[mid][i];
					int cur = i + 1;
					while (cur < s[mid].size()) {
						if (s[mid][cur] == 'Z') {
							ans += s[mid][cur];
						}
						else {
							if (cur < s[mid].size() - 1)ans += s[mid][cur] + 1;
							else ans += s[mid][cur];
							break;
						}
						cur++;
					}
				}
				else {
					if (i < s[mid].size() - 1)ans += s[mid][i] + 1;
					else ans += s[mid][i];
				}
				break;
			}
		}
		cout << ans << endl;
	}
}
