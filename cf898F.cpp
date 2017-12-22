#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 6;
const long long mod = 1e9 + 7;
long long base[maxn], st[maxn], sum[maxn];//sum[i]代表区间[0,i]数位组成的大整数对mod的模
char s[maxn];
int len;
void print_ans(int l, int r)
{
	for (int i = 0; i < l; i++)printf("%d", st[i]);
	printf("+");
	for (int i = l; i < r; i++)printf("%d", st[i]);
	printf("=");
	for (int i = r; i < len; i++)printf("%d", st[i]);
}
bool ok(int l, int r) {
	if (st[r] == 0 && len - r > 1 || st[l] == 0 && r - l > 1)return false;
	long long s1 = sum[l - 1];
	long long s2 = ((sum[r - 1] - sum[l - 1] * base[r - l]) % mod + mod) % mod;
	long long s3 = ((sum[len - 1] - sum[r - 1] * base[len - r]) % mod + mod) % mod;
	if ((s1 + s2) % mod == s3) {
		int cur1 = l - 1, cur2 = r - 1;
		int flag = 0, a = 0, b = 0;
		int cnt = 0;
		while (cur2 >= l || cur1 >= 0 || flag) {
			if (cur2 >= l)b = st[cur2--];
			if (cur1 >= 0)a = st[cur1--];
			if (len - cnt - 1 < r || st[len - cnt - 1] != (a + b + flag) % 10)return false;
			cnt++;
			if (a + b + flag > 9)flag = 1;
			else flag = 0;
			a = b = 0;
		}
		if (cnt != len - r)return false;
		return true;
	}
	return false;
}
int main()
{
	scanf("%s", s);
	len = strlen(s);
	for (int i = 0; i < len; i++)st[i] = s[i] - '0';
	base[0] = 1LL;
	for (int i = 1; i < len; i++) {
		base[i] = (base[i - 1] * 10) % mod;
	}
	for (int i = 0; i < len; i++) {
		sum[i] += st[i];
		if (i)sum[i] += sum[i - 1] * 10;
		sum[i] %= mod;
	}
	for (int i = len / 2; i >= 0; i--) {//枚举左边或者中间的长度   l_len+1==rl 或者 l_len+1==r1en
		if (len - i * 3 > 2)break;
		int lpos = i, rpos = len - i;  //分成[0,lpos) [lpos,rpos)[rpos,len)三段
		if (lpos > 0 && rpos > lpos&&ok(lpos, rpos))return print_ans(lpos, rpos), 0;
		lpos = len - i * 2; rpos = lpos + i;
		if (lpos > 0 && rpos > lpos&&ok(lpos, rpos))return print_ans(lpos, rpos), 0;
		lpos = i, rpos = len - i - 1;
		if (lpos > 0 && rpos > lpos&&ok(lpos, rpos))return print_ans(lpos, rpos), 0;
		lpos = len - i * 2 - 1; rpos = lpos + i;
		if (lpos > 0 && rpos > lpos&&ok(lpos, rpos))return print_ans(lpos, rpos), 0;
	}
}
