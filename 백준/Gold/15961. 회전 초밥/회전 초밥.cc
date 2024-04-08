#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, D, K, C, arr[3000001];
int start, cnt, answer;


unordered_map<int, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> D >> K >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < K - 1; i++) { 
		m[arr[i]]++;
	} 

	int fin = K - 1;
	for (int i = 0; i < N; i++) { 
		int del = arr[start];
		int cur = arr[fin % N];
		m[cur]++;
		int num = m.size();
		if (m.find(C) == m.end()) {
			answer = max(answer, num + 1);
		}
		else {
			answer = max(answer, num);
		}
		m[del]--;
		if (m[del] == 0) 
			m.erase(m.find(del));
		start++;
		fin++;
	}
	cout << answer;
}