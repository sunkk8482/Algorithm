#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n;
vector<int> sum;

bool bs(int t) {
	int start = 0;
	int end = sum.size()- 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (sum[mid] == t) {
			return true;
		}
		if (sum[mid] > t) {
			end = mid - 1;
		}
		if (sum[mid] < t) {
			start = mid + 1;
		}
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		v.push_back(number);
	}
	for (int i = 0; i < n ; i++) {
		for (int j = i ; j < n; j++) {
			sum.push_back(v[i] + v[j]);
		}
	}
	sort(v.begin(), v.end());
	sort(sum.begin(),sum.end());
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			int dif = v[i] - v[j];
			
			bool result = bs(dif);
			if (result) {
				cout << v[i];
				return 0;
			}


		}
	}
}