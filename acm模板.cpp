void phi_table(int n, int *phi)//����1~n������ŷ�����������Ӷ�O(n(loglogn)) 
{//��������ɸ��������  
	for (int i = 2; i <= n; i++)phi[i] = 0;
	phi[i] = 1;
	for (int i = 2; i <= n; i++)if (!phi[i]) {//���i������
		for (int j = i; j <= n; j++) {
			if (!phi[j])phi[j] = j;//��ʼ��
			phi[j] = phi[j] / i*(i - 1);
		}
	}
}


vector<int>prime;
int vis[len+1];
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
