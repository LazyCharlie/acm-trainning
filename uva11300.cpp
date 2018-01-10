#include<bits/stdc++.h>
using namespace std;
int n;
long long M,A[1000006], C[1000006], sum;
int main()
{
	while (scanf("%d", &n) == 1 && n) {
		sum = 0;
		for (int i = 0; i < n; i++)scanf("%llu", &A[i]), sum += A[i];
		M = sum / n;
		for (int i = 1; i < n; i++) {
			C[i] = C[i - 1] + M - A[i - 1];
		}
		sort(C, C + n);
		long long x1 = C[(n - 1) / 2];
		unsigned long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += abs(x1 - C[i]);
		}
		printf("%llu\n", ans);
	}
}
