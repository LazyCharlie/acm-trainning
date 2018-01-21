#include<bits/stdc++.h>
using namespace std;
char A[6][7], B[6][7];
int mul[5];
vector<char>G[5];
int T, K;
set<string>S;
string tmp;
void dfs(int cur, int x) 
{
	if (cur == 5) {
		printf("\n"); return;
	}
	int cnt = 0;
	while (x > mul[cur])x -= mul[cur], cnt++;
	printf("%c", G[cur][cnt]);
	dfs(cur + 1, x);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		S.clear();
		for (int i = 0; i < 5; i++) G[i].clear();
		scanf("%d", &K);
		for (int i = 0; i < 6; i++)scanf("%s", A[i]);
		for (int i = 0; i < 6; i++)scanf("%s", B[i]);
		for (int i = 0; i < 5; i++) {
			int vis[26] = { 0 };
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 6; k++) {
					if (A[j][i] == B[k][i] && vis[A[j][i] - 'A'] == 0) {
						G[i].push_back(A[j][i]);
						vis[A[j][i] - 'A'] = 1;
					}
				}
			}
			sort(G[i].begin(), G[i].end());
		}
		mul[4] = 1;
		for (int i = 3; i >= 0; i--) {
			mul[i] = 1LL * mul[i + 1] * G[i + 1].size();
		}
		if (mul[0] * G[0].size() < K) {
			printf("NO\n");
		}
		else dfs(0, K);
	}
}
