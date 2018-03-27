#include<bits/stdc++.h>
using namespace std;
const int maxn = 800;
struct Item {
	int tot, id;
	bool operator<(const Item &rhs)const {
		return tot > rhs.tot;
	}
	Item(int t, int i) :tot(t), id(i) {}
};
int k;
int a[maxn], b[maxn];
void merge()
{
	priority_queue<Item>q;
	for (int i = 0; i < k; i++)q.push(Item(a[i] + b[0], 0));
	for (int i = 0; i < k; i++) {
		Item item = q.top();
		q.pop();
		a[i] = item.tot;
		if (item.id + 1 < k)item.tot = item.tot - b[item.id] + b[item.id + 1], item.id++;
		q.push(item);
	}
}
int main()
{
	while (scanf("%d", &k)==1) {
		for (int i = 0; i < k; i++)scanf("%d", &a[i]);
		for (int i = 1; i < k; i++) {
			for (int j = 0; j < k; j++)scanf("%d", &b[j]);
			sort(b, b + k);
			merge();
		}
		for (int i = 0; i < k; i++)printf("%d%c", a[i], i + 1 == k ? '\n' : ' ');
	}
}
