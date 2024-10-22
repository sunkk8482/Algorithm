#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int   K, N;

vector<long long> v;

long long max_number = -1;

int main() {
	cin >> K >> N;
	long long num;

	for (int i = 0; i < K; i++) {
		cin >> num;
		max_number = max(max_number, num);
		v.push_back(num);
	}

	long long start = 0;
	long long end = max_number*2;
	long long answer = 0;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = 0;
		for (auto i : v) {
			if (mid != 0) {
				sum += (i / mid);
			}
		}
		if (sum < N) {
			end = mid - 1;
		}
		if (sum >= N) {
				answer = mid;
			
			start = mid + 1;
		}
	}

	cout << answer;
}
