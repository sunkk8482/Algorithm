#include <iostream>
#include <algorithm>
using namespace std;

int arr[501];

int main() {
	int H, W;
	cin >> H >> W;
	int answer = 0;

	for (int i = 0; i < W; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < W - 1; i++) {
		int left = 0;
		int right = 0;
		for (int j = i; j >= 0; j--) {
			left = max(left, arr[j]);
		}
		for (int j = i; j < W; j++) {
			right = max(right, arr[j]);
		}

		if (left == 0 || right == 0)continue;

		int mini = min(left, right);

		answer += mini - arr[i];
	}

	cout << answer;
}

/*

1 2 3 1 2






*/