#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
int arr[10001];

struct node {
	int a, b;
	int price;
};

vector<node> line;

bool compare(node a, node b) {
	return a.price < b.price;
}

void init() {
	for (int i = 0; i < V; i++) {
		arr[i] = i;
	}
}

int find(int tar) {
	if (arr[tar] == tar)return tar;
	int ret = find(arr[tar]);
	arr[tar] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	arr[t2] = t1;
}

int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		line.push_back({ a,b,c });
	}

	sort(line.begin(), line.end(), compare);
	init();
	int target = V - 1;
	int selectCount = 0;
	int result = 0;
	for (auto i : line) {
		if (find(i.a) == find(i.b))continue;
		setUnion(i.a, i.b);
		result += i.price;
		selectCount += 1;
		if (selectCount == target)break;
	}
	cout << result;
}