#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int arr[100001];

void init() {
	for (int i = 1; i <= N; i++) {
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

struct line {
	int from;
	int to;
	int cost;
};

vector<line> v;

bool compare(line left, line right) {
	if (left.cost < right.cost)return true;
	if (left.cost > right.cost)return false;
	return false;
}

int main() {
	cin >> N >> M;
	init();
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	sort(v.begin(), v.end(), compare);
	int answer = 0;
	int townCnt = N;
	for (int i = 0; i < v.size(); i++) {
		if (townCnt == 2)break;
		int from = v[i].from;
		int to = v[i].to;
		if (find(from) == find(to))continue;
		setUnion(from, to);
		answer += v[i].cost;
		townCnt--;
	}
	cout << answer;


}