#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int arr[1001];

void init() {
	for (int i = 0; i < 1001; i++) {
		arr[i] = i;
	}
}

int find(int tar) {
	if (arr[tar] == tar)return tar;
	int ret = find(arr[tar]);
	arr[tar] = ret;
	return ret;
}

void set_union(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	arr[t2] = t1;
}

struct node {
	int s;
	int e;
	int cost;
};

vector<node> v;
bool compare(node left, node right) {
	if (left.cost < right.cost)return true;
	return false;
}

void func(int a, int b) {
	init();
	set_union(a, b);
	int cnt = N - 2;
	int answer = 0;
	for (int i = 0; i < M; i++) {
		if (cnt == 0)break;
		int s, e;
		s = v[i].s;
		e = v[i].e;
		if (find(s) == find(e))continue;
		cnt--;
		set_union(s, e);
		answer += v[i].cost;
	}
	cout << answer<<"\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	sort(v.begin(), v.end(), compare);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		func(a, b);
	}
}
/*

a b 비용 c


x y 팀장이면 t의 최솟값
*/