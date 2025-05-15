#include<iostream>
#include<algorithm>

using namespace std;

int N, M, K;

int arr[3001][3001];

int main(int argc, char** argv)
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[0][i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> arr[i][0];
	}

	for (int i = 1; i <= M; i++) {
		int left = arr[i][0];
		for (int j = 1; j <= N; j++) {
			int right = arr[0][j];
			if (left == right) {
				if (i - 1 == 0 || j - 1 == 0) {
					arr[i][j] = 1;
					continue;
				}
				arr[i][j] = arr[i - 1][j - 1] + 1;
			} 
		}
	}
	int answer = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			answer = max(answer, arr[i][j]);
		}
	}
	cout << answer;
	return 0;
}