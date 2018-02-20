#include<bits/stdc++.h>
using namespace std;
int T;
long long mm;
vector<pair<long long, long long>>ans;
long long C(long long m, long long n)
{
	//n = min(m - n, n);
	long long ret = 1;
	for (int i = 0; i < n; i++) {
		if (ret / (i + 1) > mm / (m - i))return mm + 1;
		ret = ret*(m - i) / (i + 1);
	}
	return ret;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	long long tmp;
	while (T--) {
		ans.clear();
		scanf("%lld", &mm);
		for (long long i = 1; C(2 * i, i) <= mm; i++) {
			long long l = i * 2;
			long long r = mm;
			while (l <= r) {
				long long mid = (l + r) / 2;
				tmp = C(mid, i);
				if (tmp == mm) {
					ans.push_back(make_pair( mid,i ));
					if (mid - i != i)ans.push_back(make_pair(mid,mid - i ));
					break;
				}
				else if (tmp < mm) {
					l = mid + 1;
				}
				else r = mid - 1;
			}
		}
		sort(ans.begin(), ans.end());
		int len = ans.size();
		printf("%d\n", len);
		for (int i = 0; i < len; i++) {
			printf("(%lld,%lld)%c", ans[i].first, ans[i].second, i + 1 == ans.size() ? '\n' : ' ');
		}
	}
}
