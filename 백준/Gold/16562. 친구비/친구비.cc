#include <iostream>
#include <algorithm>
using namespace std;

int N, M, k;

int boss[10001];

int moneys[10001];

int find(int tar) {
	if (boss[tar] == tar)return tar;
	int ret = find(boss[tar]);
	boss[tar] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	boss[t2] = t1;
}

int main() {
	cin >> N >> M >> k;
	for (int i = 1; i <= N; i++) {
		boss[i] = i;
		cin >> moneys[i];
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (moneys[find(a)] <= moneys[find(b)]) {
			setUnion(a, b);
		}
		else {
			setUnion(b, a);
		}
	}
	long long answer = 0;
	

	for (int i = 1; i <= N; i++) {
		int now_boss = find(i);
		answer += moneys[now_boss];
		moneys[now_boss] = 0;
	}
	
	if (answer > k) {
		cout << "Oh no";
	}
	else {
		cout << answer;
	}
}