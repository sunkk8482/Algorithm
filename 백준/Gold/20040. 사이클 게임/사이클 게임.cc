#include <iostream>
#include <string>

using namespace std;

int arr[500000];
int n, m;

bool over = false;

void init() {
	for (int i = 0; i < 500000; i++) {
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
	if (t1 == t2) {
		over = true;
		return;
	}
	arr[t2] = t1;
}

int main() {
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		setUnion(a, b);
		if (over) {
			cout << i + 1;
			break;
		}
	}
	if (!over) {
		cout << 0;
	}
}
/*
	
*/