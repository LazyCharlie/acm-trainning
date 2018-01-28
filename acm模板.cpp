void phi_table(int n, int *phi)//计算1~n的所有欧拉函数，复杂度O(n(loglogn)) 
{//类似于用筛法求素数  
	for (int i = 2; i <= n; i++)phi[i] = 0;
	phi[i] = 1;
	for (int i = 2; i <= n; i++)if (!phi[i]) {//如果i是素数
		for (int j = i; j <= n; j++) {
			if (!phi[j])phi[j] = j;//初始化
			phi[j] = phi[j] / i*(i - 1);
		}
	}
}


vector<int>prime;
int vis[len+1];
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
