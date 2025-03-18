#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long aInput[4001];
long long bInput[4001];
long long cInput[4001];
long long dInput[4001];


vector<long long> bSum;
vector<long long> dSum;

int main() {
	long long n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> aInput[i];
		cin >> bInput[i];
		cin >> cInput[i];
		cin >> dInput[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bSum.push_back(aInput[i] + bInput[j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dSum.push_back(cInput[i] + dInput[j]);
		}
	}

	long long answer = 0;
	sort(bSum.begin(), bSum.end());
	sort(dSum.begin(), dSum.end());

	long long start = 0;
	long long end = (n*n)-1;
	long long size = end;
	if (n == 1)size++;
	while (start < bSum.size() && end >= 0) {
		long long sum = bSum[start] + dSum[end];
		if (sum < 0) {
			start++;
		}
		else if (sum > 0) {
			end--;
		}
		else {
			long long left = bSum[start];
			long long right = dSum[end];
			long long leftCnt = 0;
			long long rightCnt = 0;
			while (start < bSum.size() &&bSum[start] == left) {
				start++;
				leftCnt++;
			}
			while (end>=0&&dSum[end] == right) {
				end--;
				rightCnt++;
			}
			answer += (rightCnt * leftCnt);
		}
	}

	cout << answer;
}