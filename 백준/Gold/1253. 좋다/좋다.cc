#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int answer;
vector<int>v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int left = 0;
		int right = n - 1;
		while (left < right) {
			if (left == i) {
				left++;
				continue;
			}
			if (right == i) {
				right--;
				continue;
			}
			if (v[i] > v[left] + v[right]) {
				left++;
			}
			else if (v[i] == v[left] + v[right]) {
				answer++;
				break;
			}
			else {
				right--;
			}
		}
	}
	cout << answer;
}