#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

struct node {
	int cnt;
	int zero;
};
unordered_map<string, node> um;

int N, M;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		um[s].cnt++;
		if (um[s].zero == 0) {
			int num = 0;
			for (int j = 0; j < s.length(); j++) {
				if (s.at(j) == '0') {
					num++;
				}
			}
			um[s].zero = num;
		}
	}
	int k;
	cin >> k;
	int answer = 0;
	
	for (auto i : um) {
		int zero = i.second.zero;
		if (zero <= k && zero % 2 == k % 2) {
			answer = max(answer, i.second.cnt);
		}
	}
	cout << answer;
}