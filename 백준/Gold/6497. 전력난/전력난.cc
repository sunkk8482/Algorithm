#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;

int boss[200001];

struct node {
	int a, b;
	int price;
};

vector<node> v;

bool compare(node left, node right) {
	if (left.price < right.price) return true;
	if (left.price > right.price)return false;
	return false;
}



int find(int tar) {
	if (boss[tar] == tar)return tar;
	int ret = find(boss[tar]);
	boss[tar] = ret;
	return ret;
}

void set_union(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	boss[b] = a;
}
int full = 0;
bool flag = false;
void input() {
	cin >> m >> n;
	int a, b, c;
	if (m == 0 && n == 0) {
		flag = true;
		return;
	}
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
		full += c;
	}
	
}
void init() {
	for (int i = 0; i < 200001; i++) {
		boss[i] = i;
	}
	v.clear();
	full = 0;
}
int main() {
	while (1) {
		init();
		input();
		if (flag)return 0;
		sort(v.begin(), v.end(), compare);

		int union_cnt = 0;
		int sum = 0;

		for (auto i : v) {
			if (find(i.a) == find(i.b))continue;
			set_union(find(i.a), find(i.b));
			union_cnt++;
			sum += i.price;
			if (union_cnt == n - 1) break;
		}

		cout << full - sum<<"\n";
	}
}