#include<bits/stdc++.h>
using namespace std;
int phi[50005];
int n;
void phi_table(int n)//����1~n������ŷ�����������Ӷ�O(n(loglogn))
{
	for (int i = 2; i <= n; i++)phi[i] = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++)if (!phi[i]) {//���i������
		for (int j = i; j <= n; j += i) {
			if (!phi[j])phi[j] = j;//��ʼ��
			phi[j] = phi[j] / i*(i - 1);
		}
	}
}
int main()
{
	phi_table(50000);
	for (int i = 1; i <= 50000; i++) {
		phi[i] += phi[i - 1];
	}
	while (scanf("%d", &n) == 1 && n) {
		printf("%d\n", phi[n] * 2 - 1);
	}
}
