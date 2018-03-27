#include<bits/stdc++.h>
using namespace std;
int n, a, b;
string s[3] = { "queue\n","priority queue\n","stack\n" };
queue<int>q;
priority_queue<int>pq;
stack<int>S;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d", &n) == 1) {
		int pos[3] = { 1,1,1 };
		queue<int>().swap(q);
		priority_queue<int>().swap(pq);
		stack<int>().swap(S);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			if (a == 1) {
				if (pos[0])q.push(b);
				if (pos[1])pq.push(b);
				if (pos[2])S.push(b);
			}
			else {
				if (!q.size()||pos[0] && q.front() != b)pos[0] = 0;
				else if (pos[0]&&q.size())q.pop();
				if (!pq.size()||pos[1]&&pq.top() != b)pos[1] = 0;
				else if (pos[1]&&pq.size())pq.pop();
				if (!S.size()||pos[2] && S.top() != b)pos[2] = 0;
				else if (pos[2]&&S.size())S.pop();
			}
		}
		int tot = 0;
		for (int i = 0; i < 3; i++)tot += pos[i];
		if (tot == 0)printf("impossible\n");
		else if (tot > 1)printf("not sure\n");
		else {
			for (int i = 0; i < 3; i++) {
				if (pos[i]) {
					printf("%s", s[i].c_str());
				}
			}
		}
	}
}
