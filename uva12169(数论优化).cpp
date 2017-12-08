#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll M = 10001;
int n;
ll a[210];
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0) {
		x = 1LL, y = 0LL;
		return a;
	}
	int ans = exgcd(b, a%b, x, y);
	int temp = x;
	x = y;
	y = temp - a / b*y;
	return ans;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i += 2)scanf("%lld", &a[i]);
	for (int i = 0; i < M; i++) {                 //枚举a,根据a[2]={[(a[0]*i+b)%10001]*i+b}%10001 
		ll k, b;  	                      //有a[2]=[(a[0]*i+b)*i+b)]%10001 
		ll ans = exgcd(M, -(i + 1), k, b); //问题转化为求扩展欧几里德：10001*k-(i+1)*b=a[0]*i*i-a[2]
		b *= (a[0] * i*i - a[2]) / ans;
		b = (b%M + M) % M;
		int ok = 1;
		for (int p = 1; p <= 2 * n; p += 2) {
			a[p] = (a[p - 1] * i + b) % M;
			if (p < 2 * n - 1 && (a[p] * i + b) % M != a[p + 1]) {
				ok = 0;
				break;
			}
		}
		if (ok)break;
	}
	for (int i = 1; i <= 2 * n; i += 2)printf("%lld\n", a[i]);
}
