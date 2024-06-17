/*
4 5
1 1
1 1 진실
1 2 거짓
1 3 거짓
1 4 거짓 
2 4 1 진실
*/

#include <iostream>
#include <vector>
using namespace std;

int arr[100];

int N, M;

void init() {
	for (int i = 0; i < 100; i++) {
		arr[i] = i;
		//1 모르고있는놈들
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

int dat[100];

int main() {
	init();
	cin >> N >> M;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int number;
		cin >> number;
		dat[number] = 1;
	}

	vector<vector<int>> v(100);
	for (int i = 0; i < M; i++) {
		int number;
		cin >> number;
		int prev;
		cin >> prev;
		v[i].push_back(prev);
		for (int j = 1; j < number; j++) {
			int a;
			cin >> a;
			v[i].push_back(a);
			set_union(prev, a);
			if (dat[prev] == 1 || dat[a] == 1) {
				for (int k = 0; k <= N; k++) {
					if (find(k) == find(a)) {
						dat[k] = 1;
					}
				}
			}
 			prev = a;
		}
	}
	int answer = 0;


	for (int i = 0; i < M; i++) {
		bool check = true;
		for (int j = 0; j < v[i].size(); j++) {
			int num = find(v[i][j]);
			if (dat[num]) {
				check = false;
				break;
			}
		}
		if (check) {
			answer++;
		}
	}
	cout << answer;
	
}