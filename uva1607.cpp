#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int a1,a2;
	int o; 
}input[200006];
int output(int k)
{
	for(int i=1;i<=m;i++){
		int a=input[i].a1;
		int b=input[i].a2;
		int va=a<0?-a<=k:input[a].o;
		int vb=b<0?-b<=k:input[b].o;
		input[i].o=va+vb<2;
	}
	return input[m].o;
}
int main()
{
	int T;scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&input[i].a1,&input[i].a2);
		}
		int x=output(0);
		int y=output(n);
		if (x==y){
			for(int i=0;i<n;i++)printf("1");
			printf("\n");
			continue;
		}
		int L=1,R=n;
		while (L<R){
			int M=L+(R-L)/2;
			if (output(M)==x){
				L=M+1;
			}
			else R=M;
		}
		for(int i=1;i<L;i++)printf("1");
		printf("x");
		for(int i=L+1;i<=n;i++)printf("0");
		printf("\n");
	}
 } 
