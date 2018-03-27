void phi_table(int n, int *phi)//����1~n������ŷ�����������Ӷ�O(n(loglogn)) 
{//��������ɸ��������  
	for (int i = 2; i <= n; i++)phi[i] = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++)if (!phi[i]) {//���i������
		for (int j = i; j <= n; j += i) {
			if (!phi[j])phi[j] = j;//��ʼ��
			phi[j] = phi[j] / i*(i - 1);
		}
	}
}


vector<int>prime;
int vis[len + 1];
void seive(int len)//����ɸ�����Ӷ�O(N)��ɸѡ��[2��len]�������� 
{
	vis[1] = 1;
	for (int i = 2; i <= len; i++) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size(); j++) {
			if (1LL * prime[j] * i > len)break;
			vis[prime[j] * i] = 1;
			if (i%prime[j] == 0)break;
		}
	}
}

//�������ʽa+b*(c-d)-e/f ����һ�ű��ʽ�� ˼�룺�ҵ��������������������ڵ������һ�����������㡣 
const int maxn = 1000 + 5;
int nc = 0;
char op[maxn];
int lch[maxn], rch[maxn];
int build_tree(char *s, int x, int y)//[x,y)
{
	int i, c1 = -1, c2 = -1, p = 0;//c1��ʾ������ĵ����һ��+-�ŵ�λ�ã�c2��ʾ����������һ��*/�ŵ�λ��
	int u;
	if (y - x == 1) {
		u = ++nc;
		lch[u] = rch[u] = 0;
		op[u] = s[x];
		return u;
	}
	for (i = x; i < y; i++) {
		switch (s[i]) {
		case '(':p++; break;
		case ')':p--; break;
		case '+':case '-':if (!p)c1 = i; break;
		case '*':case '/':if (!p)c2 = i; break;
		}
	}
	if (c1 < 0)c1 = c2;//��������û��+- ��*/����
	if (c1 < 0)return build_tree(s, x + 1, y - 1);//���ʽ��������һ������ 
	u = ++nc;
	lch[u] = build_tree(s, x, c1);//������ 
	rch[u] = build_tree(s, c1 + 1, y);//������ 
	op[u] = s[c1];
	return u;
}

//Dijkstra n2�㷨 �����ڽӾ����ͼ
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
const int INF = 0x3f3f3f3f;
int vis[maxn];//��¼�̶����
int w[maxn][maxn];//w[i][j]��ֵ��ʾ���ǵ�i����j��һ��ȨֵΪw[i][j]�������
int d[maxn];//��¼��1����i�ľ��룬����Ϊd[i];
int n;//һ����n���ڵ㣬�ڵ���Ϊ1~n
int main()
{
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)d[i] = (i == 1 ? 0 : INF);
	for (int i = 1; i <= n; i++) {
		int x, m = INF;
		for (int y = 1; y <= n; y++)if (!vis[y] && d[y] <= m)x = y, m = d[y];//Ѱ�Ҳ��ǹ̶���ŵĽڵ��о���������ĸ��ڵ�
		vis[x] = 1;//�ĳɹ̶����
		for (int y = 1; y <= n; y++)d[y] = min(d[y], d[x] + w[x][y]);//��������̶���Žڵ㵽�������нڵ�ľ���
	}
}

//Dijkstra �ṹ��
const int maxn = 1000 + 5;
struct Edge {
	int from, to, dist;
	Edge(int u, int v, int d) :from(u), to(v), dist(d) {}
};
struct Dijkstra {
	int n, m;
	vector<Edge>edges;
	vector<int>G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];
	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++)G[i].clear();
		edges.clear();
	}
	void AddEdge(int from, int to, int dist) {
		edges.push_back(Edge(from, to, dist));
		m = edges.size();
		G[from].push_back(m - 1);
	}
};

//��״����   �����±��1-n 
const int maxn=100000+5;
int C[maxn];//�������� C[i]��ʾx[i-lowbit(i)+1]~x[i]�ĺ� 
int lowbit(int x)
{
	return x&(-x);
}
int sum(int x){ // ��λ��1-x�ĺ� 
	int ret=0;
	while (x>0){
		ret+=C[x];
		x-=lowbit(x);
	}
	return ret;
} 
void add(int x,int d)
{
	while (x<=n){
		C[x]+=d;
		x+=lowbit(x);
	}
 } 
 
 
//01trie ģ�� 
#include<bits/stdc++.h>
using namespace std;
struct node {
	node * next[2];
	int cnt;//���ڶ��ٸ�������ǰ׺ 
	node() {
		next[0] = next[1] = NULL;
		cnt = 0;
	}
}*root;
const int maxn = 300000 + 5;
int N;
long long P[maxn];
void build(){//һ��N��������N�������ȴ�����P������ 
	root = new node();//��ʼ����ͷ 
	for (int i = 0; i < N; i++) {
		node *cur = root;
		for (int j = 29; j >= 0; j--) {//p[i]�����е����ֵС��2^30 ���Ҳ�С��0 
			long long st = (1LL << j)&P[i];
			if (cur->next[st > 0] == NULL) {
				cur->next[st > 0] = new node();
			}
			cur = cur->next[st > 0];
			cur->cnt++;
		}
	}
}
long long query(int x, long long num,node *cur)//��ѯ�����Сֵ����ɾ���� 
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
