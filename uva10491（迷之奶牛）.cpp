#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
	while (scanf("%d%d%d", &a, &b, &c) == 3) {
		printf("%.5f\n", 1.0*a / (a + b)*b / (a + b - c - 1) + 1.0*b / (a + b)*(b - 1) / (a + b - c - 1));
	}
}
