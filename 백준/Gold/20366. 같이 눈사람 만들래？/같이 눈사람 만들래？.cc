#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int N;

vector<int> v;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int answer = 2134567890;
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			int sum = v[i] + v[j];
			int left = i + 1;
			int right = N - 1;
			while (left < right) {
				if (left == i || left==j) {
					left++;
					continue;
				}
				if (right == j || right==i) {
					right--;
					continue;
				}
				int sum2 = v[left] + v[right];
				answer = min(answer, abs(sum - sum2));
				if (sum2 > sum) {
					right--;
				}
				else {
					left++;
				}
			}
		}
	}
	cout << answer;
}

/*
2 3 5 5 9 11 13

2 3 

5 5

먼저 2개를 뽑은 뒤


*/