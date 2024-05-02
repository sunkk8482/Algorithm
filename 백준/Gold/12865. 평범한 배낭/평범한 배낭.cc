/*
	제한을 1 2 3 4 걸면서
	
	각 부분에서 최대를 구하고

	넣을 수 있을 때와 없을 때 나누는

*/

#include <iostream>
#include <algorithm>

using namespace std;
int N, K;

int arr[101][100001];

int w[101];
int v[101];

void func() {
	for (int i = 1; i <= K; i++) {
		for (int j =1; j <= N; j++) {
			if (w[j] > i) {
				arr[j][i] = arr[j - 1][i];
			}
			else {
				arr[j][i] = max(arr[j - 1][i - w[j]] + v[j], arr[j - 1][i]);
			}
		}
	}
}


int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> w[i];
		cin >> v[i];
	}
	func();
	cout << arr[N][K];
}