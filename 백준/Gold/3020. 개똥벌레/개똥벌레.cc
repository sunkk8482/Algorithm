#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, H;

vector<int> jong;
vector<int> suk;

int main() {
	cin >> N >> H;
	jong = vector<int>(H+1);
	suk = vector<int>(H + 1);

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		if (i % 2 == 0)suk[number]++;
		else jong[H - number + 1]++;
	}

	for (int i = 1; i <= H; i++) {
		jong[i] += jong[i - 1];
		suk[H - i] += suk[H - i + 1];
	}
	long long answer = 9223372036854775807;
	
	int cnt = 0;

	for (int i = 1; i <= H; i++) {
		if (suk[i] + jong[i] < answer) {
			cnt = 1;
			answer = suk[i] + jong[i];
		}
		else if(suk[i]+jong[i]==answer) {
			cnt++;
		}
	}
	cout << answer << " " << cnt;
}