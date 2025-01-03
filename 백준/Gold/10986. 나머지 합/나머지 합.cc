#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main() {
	cin >> N >> M;
	vector<long long> v(1010, 0);
	long long sum = 0;
	long long answer = 0;

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		sum += number;
		v[sum % M]++;
		if (sum % M == 0) {
			answer++;
		}
	}

	for (int i = 0; i <= M; i++) {
		answer += v[i] * (v[i] - 1) / 2;
	}
	cout << answer;

}