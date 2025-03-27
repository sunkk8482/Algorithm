#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long n;

int main() {
	cin >> n;
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
 	long long answer = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i+1; j < n; j++) { 
			long long sum = v[i] + v[j];
			auto low = lower_bound(v.begin() + j+1, v.end(), -sum);
			auto up = upper_bound(v.begin() + j + 1, v.end(), -sum);
			if (low == v.end())continue;
			if (*low != (-sum))continue;
			answer += (up - low);
		}
	}
	cout << answer;
}

/*

	-6 -5 -4 -4 0 1 2 2 3 7
*/