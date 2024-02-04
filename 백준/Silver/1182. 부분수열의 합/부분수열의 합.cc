#include <iostream>

using namespace std;

int N, S;

int arr[20];

int visited[20];

int answer[20];

int ans = 0;

void fun(int level,int cnt,int idx) {
	if (level == cnt) {
		int sum = 0;
		for (int i = 0; i < level; i++) {
			sum += answer[i];
		}
		if (sum == S) {
			ans++;
		}
		return;
	}
	
	for (int i = idx; i < N; i++) {
		if (visited[i] == 1)continue;
		answer[level] = arr[i];
		visited[i] = 1;
		fun(level + 1, cnt,i+1);
		visited[i] = 0;
	}

}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		fun(0, i, 0);
	}
	cout << ans;
}