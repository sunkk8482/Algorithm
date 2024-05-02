#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int N, S;

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int answer = -1;
	int sum = arr[0];
	while (end<N) {
		if (sum < S) {
			end++;
			sum += arr[end];
		}
		else {
			int length = end - start + 1;
			if (answer == -1) {
				answer = length;
			}
			else {
				answer = min(answer, length);
			}
			sum -= arr[start];
			start++;
		}
	}
	if (answer == -1) {
		cout << 0;
		return 0;
	}
	cout << answer;
}
/*



*/