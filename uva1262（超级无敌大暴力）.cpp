#include<bits/stdc++.h>
using namespace std;
char A[6][7], B[6][7];
int T, K;
set<string>S;
string tmp;
void dfs(int cur)
{
	if (cur == 5) {
		S.insert(tmp);
		return;
	}
	int vis[26] = { 0 };
	for (int i = 0; i < 6; i++) {
		if (vis[A[i][cur]-'A'])continue;
		for (int j = 0; j < 6; j++) {
			if (A[i][cur] == B[j][cur]) {
				tmp += A[i][cur];
				vis[A[i][cur]-'A'] = 1;
				dfs(cur + 1);
				tmp.pop_back();
			}
		}
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		S.clear();
		scanf("%d", &K);
		for (int i = 0; i < 6; i++)scanf("%s", A[i]);
		for (int i = 0; i < 6; i++)scanf("%s", B[i]);
		dfs(0);
		int cnt = 0;
		for (auto it = S.begin(); it != S.end(); it++, cnt++) {
			if (cnt + 1 == K) {
				cout << *it << endl;
				break;
			}
		}
		if (cnt == S.size())printf("NO\n");
	}
}
