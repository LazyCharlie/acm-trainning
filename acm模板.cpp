void phi_table(int n, int *phi)//计算1~n的所有欧拉函数，复杂度O(n(loglogn)) 
{//类似于用筛法求素数  
	for (int i = 2; i <= n; i++)phi[i] = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++)if (!phi[i]) {//如果i是素数
		for (int j = i; j <= n; j += i) {
			if (!phi[j])phi[j] = j;//初始化
			phi[j] = phi[j] / i*(i - 1);
		}
	}
}


vector<int>prime;
int vis[len + 1];
void seive(int len)//线性筛，复杂度O(N)，筛选出[2，len]所有素数 
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

//给出表达式a+b*(c-d)-e/f 建立一颗表达式树 思想：找到最后计算的运算符，括号内的运算符一定不是最后计算。 
const int maxn = 1000 + 5;
int nc = 0;
char op[maxn];
int lch[maxn], rch[maxn];
int build_tree(char *s, int x, int y)//[x,y)
{
	int i, c1 = -1, c2 = -1, p = 0;//c1表示括号外的第最后一个+-号的位置，c2表示括号外的最后一个*/号的位置
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
	if (c1 < 0)c1 = c2;//括号外面没有+- 用*/代替
	if (c1 < 0)return build_tree(s, x + 1, y - 1);//表达式最外面是一组括号 
	u = ++nc;
	lch[u] = build_tree(s, x, c1);//左子树 
	rch[u] = build_tree(s, c1 + 1, y);//右子树 
	op[u] = s[c1];
	return u;
}

//Dijkstra n2算法 采用邻接矩阵存图
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
const int INF = 0x3f3f3f3f;
int vis[maxn];//记录固定标号
int w[maxn][maxn];//w[i][j]的值表示的是点i到点j有一条权值为w[i][j]的有向边
int d[maxn];//记录点1到点i的距离，距离为d[i];
int n;//一共有n个节点，节点编号为1~n
int main()
{
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)d[i] = (i == 1 ? 0 : INF);
	for (int i = 1; i <= n; i++) {
		int x, m = INF;
		for (int y = 1; y <= n; y++)if (!vis[y] && d[y] <= m)x = y, m = d[y];//寻找不是固定标号的节点中距离最近的哪个节点
		vis[x] = 1;//改成固定标号
		for (int y = 1; y <= n; y++)d[y] = min(d[y], d[x] + w[x][y]);//更新这个固定标号节点到其他所有节点的距离
	}
}

//Dijkstra 结构体
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

//树状数组   数组下标从1-n 
const int maxn=100000+5;
int C[maxn];//辅助数组 C[i]表示x[i-lowbit(i)+1]~x[i]的和 
int lowbit(int x)
{
	return x&(-x);
}
int sum(int x){ // 求位置1-x的和 
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
 
 
//01trie 模版 
#include<bits/stdc++.h>
using namespace std;
struct node {
	node * next[2];
	int cnt;//存在多少个这样的前缀 
	node() {
		next[0] = next[1] = NULL;
		cnt = 0;
	}
}*root;
const int maxn = 300000 + 5;
int N;
long long P[maxn];
void build(){//一共N个数，这N个数事先储存在P数组中 
	root = new node();//初始化表头 
	for (int i = 0; i < N; i++) {
		node *cur = root;
		for (int j = 29; j >= 0; j--) {//p[i]数组中的最大值小于2^30 并且不小于0 
			long long st = (1LL << j)&P[i];
			if (cur->next[st > 0] == NULL) {
				cur->next[st > 0] = new node();
			}
			cur = cur->next[st > 0];
			cur->cnt++;
		}
	}
}
long long query(int x, long long num,node *cur)//查询异或最小值并且删除它 
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
