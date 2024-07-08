#include <iostream>
#include <vector>
using namespace std;

int boss[1000000];

vector<int> v;

int N, M;

void init() {
	for (int i = 0; i < 1000000; i++) {
		boss[i] = i;
	}
}

int find(int n) {
	if (boss[n] == n)return n;
	int ret = find(boss[n]);
	boss[n] = ret;
	return ret;
}

void set_union(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	boss[t2] = t1;
}

int main() {
	init();
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		set_union(a, b);
	}
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int answer = 0;
	int now_boss = find(v[0]);
	for (auto i : v) {
		int res = find(i);
		if (res != now_boss) {
			answer++;
			now_boss = res;
		}
	}

	cout << answer;
}