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
