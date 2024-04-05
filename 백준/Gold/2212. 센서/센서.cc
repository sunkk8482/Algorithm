#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> sensors(N);
	for (int i = 0; i < N; i++) {
		cin >> sensors[i];
	}
	sort(sensors.begin(), sensors.end());
	vector<int> diff;
	for (int i = 1; i < N; i++) {
		diff.push_back(sensors[i] - sensors[i - 1]);
	}
	sort(diff.begin(), diff.end(), greater<>());
	long long answer = 0;
	for (int i = K - 1; i < diff.size(); i++) {
		answer += diff[i];
	}
	cout << answer;
}

/*
	N개의 센서를 설치
	센서들의 정보를 수집하기 위해 집중국 세워야함
	K개 세울 수 있음

	N개의 센서가 적어도 하나의 집중국과는 통신해야함

	6 : N
	2 : K
	1 6 9 3 6 7 (좌표)

	1 3 6 7 9
	 2    6
	
	2 3 1 2
	3 2 2 1

	3 6 7 8 10 12 14 15 18 20
	7
	2 7 11 15 19
	3 1 1 2 2 2 1 3 2
	3 3 2 2 2 2 1 1 1

	
*/