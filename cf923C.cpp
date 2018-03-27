#include<bits/stdc++.h>
using namespace std;
struct node {
	node * next[2];
	int cnt;
	node() {
		next[0] = next[1] = NULL;
		cnt = 0;
	}
}*root;
const int maxn = 300000 + 5;
int N;
long long P[maxn], A[maxn];
long long solve(int x, long long num,node *cur)
{
	if (x < 0)return num;
	long long nc = (1LL << x)&num;
	if (nc) {
		if (cur->next[1] && cur->next[1]->cnt) {
			long long ret = solve(x - 1, num ^ (1LL << x), cur->next[1]);
			cur->next[1]->cnt--;
			return ret;
		}
		else  {
			long long ret = solve(x - 1, num, cur->next[0]);
			cur->next[0]->cnt--;
			return ret;
		}
	}
	if (cur->next[0]&&cur->next[0]->cnt) {
		long long ret = solve(x - 1, num, cur->next[0]);
		cur->next[0]->cnt--;
		return ret;
	}
	long long ret = solve(x - 1, num ^ (1LL << x), cur->next[1]);
	cur->next[1]->cnt--;
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	root = new node();
	for (int i = 0; i < N; i++) {
		scanf("%lld", &P[i]);
		node *cur = root;
		for (int j = 29; j >= 0; j--) {
			long long st = (1LL << j)&P[i];
			if (cur->next[st > 0] == NULL) {
				cur->next[st > 0] = new node();
			}
			cur = cur->next[st > 0];
			cur->cnt++;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%lld ", solve(29, A[i], root));
	}
}
