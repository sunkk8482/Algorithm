#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[201];

void init() {
	for (int i = 0; i < 201; i++) {
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
	init();
	int N;
	cin >> N;
	int M;
	cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 1) {
				setUnion(i+1, j+1);
			}
		}
	}
	bool avail = true;
	int first;
	cin >> first;

	for (int i = 1; i <= N; i++) {
		find(i);
	}
	int boss = find(first);

	for (int i = 1; i < M; i++) {
		int num;
		cin >> num;
		if (find(num) != boss) {
			avail = false;
			break;
		}
	}
	if (avail) {
		cout << "YES";
	}
	else{ cout << "NO";
	}
}