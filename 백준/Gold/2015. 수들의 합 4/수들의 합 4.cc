#include <iostream>
#include <map>


using namespace std;

int N, K;

int arr[300000];

long long sum[300000];

long long answer;

map<long long, long long> m;

int main() {
	cin >> N >> K;

	for(int i=1;i<=N;i++){
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
		if (sum[i] == K) {
			answer++;
		}
	}

	for (int i = 1; i <= N; i++) {
		answer += m[sum[i] - K];
		m[sum[i]]++;
	}

	cout << answer;
}
