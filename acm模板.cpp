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
