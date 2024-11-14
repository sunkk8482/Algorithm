#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int boss[1002];

int arr[1002][1002];

void init() {
	for (int i = 0; i < 1002; i++) {
		boss[i] = i;
	}
}

int find(int b) {
	if (boss[b] == b)return b;
	int ret =find(boss[b]);
	boss[b] = ret;
	return ret;
}

void set_union(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	boss[t1] = t2;
}

struct node {
	int start;
	int end;
};

struct da {
	node dir;
	int cost;
};

bool comapre(da a, da b) {
	if (a.cost < b.cost)return true;
	return false;
}

int main() {
	int n;
	init();
	cin >> n;
	vector<da> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			v.push_back({ {i,j},arr[i][j] });
		}
	}
	sort(v.begin(), v.end(), comapre);
	long long answer = 0;
	int num = n - 1;
	for (auto i : v) {
		if (num == 0)break;
		if (i.cost == 0)continue;
		if (find(i.dir.start) == find(i.dir.end))continue;
		num--;
		set_union(i.dir.start, i.dir.end);
		answer += i.cost;
	}
	cout << answer;
}