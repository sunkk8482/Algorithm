#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int V, E;
int N,K;
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
	for (int i = 0; i < N; i++) {
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

vector<char> sarr;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		char s;
		cin >> s;
		sarr.push_back(s);
	}

	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		line.push_back({ a,b,c });
	}



	sort(line.begin(), line.end(), compare);
	init();
	int target = N - 1;
	int selectCount = 0;
	int result = 0;
	bool finish = false;
	for (auto i : line) {
		if (find(i.a) == find(i.b))continue;
		if (sarr[i.a - 1] == sarr[i.b - 1])continue;
		setUnion(i.a, i.b);
		result += i.price;
		selectCount += 1;
		if (selectCount == target)
		{
			finish = true;
			break;
		}
	}
	if (!finish) {
		cout << -1;
		return 0;
	}
	cout << result;
}