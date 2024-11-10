#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int tree[300000];
int arr[300000];
long long answer;

void addTree(int left, int right, int node, int num) {
	if (num<left || num>right)return;
	tree[node]++;
	if (left == right)return;
	int mid = (left + right) / 2;
	addTree(left, mid, node * 2, num);
	addTree(mid + 1, right, node * 2 + 1, num);
}
void delTree(int left, int right, int node, int num) {
	if (num<left || num>right)return;
	tree[node]--;
	if (left == right)return;
	int mid = (left + right) / 2;
	delTree(left, mid, node * 2, num);
	delTree(mid + 1, right, node * 2 + 1, num);
}

void getMid(int left, int right, int node,int cnt) {

	if (left == right) {
		answer += left;
		return;
	}
	int mid = (left + right) / 2;
	if (tree[node*2] >= cnt) {
		getMid(left, mid, node * 2,cnt);
	}
	else {
		getMid(mid + 1, right, node * 2 + 1,cnt-tree[node*2]);
	}

}

int main() {
	cin >> N >> K;
	int Max = 0;
	int Min = 9999999;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		Max = max(Max, arr[i]);
		Min = min(Min, arr[i]);
	}

	for (int i = 0; i < K; i++) {
		addTree(Min, Max, 1, arr[i]);
	}
	getMid(Min, Max, 1, (K + 1) / 2);

	for (int i = K; i < N; i++) {
		addTree(Min, Max, 1, arr[i]);
		delTree(Min, Max, 1, arr[i - K]);
		getMid(Min, Max, 1, (K + 1) / 2);
	}
	cout << answer;
}