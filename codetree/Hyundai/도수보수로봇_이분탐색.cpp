#include <iostream>

using namespace std;

int N, K;

int X[100010];

bool Evaluate(int n)
{
	// n의 길이로 몇개 필요한지 계산
	int cnt = 1;
	int last = 1;
	for (int i = 2; i <= N; i++) {
		int diff = X[i] - X[last] + 1;
		if (diff <= n) continue;
		last = i;
		cnt++;
	}
	return cnt <= K;
}

int BSearch(int s, int e)
{
	if (s > e)return X[N] - X[1] + 1;
	int mid = (s + e) / 2;
	if (Evaluate(mid))
	{
		return min(mid,BSearch(s, mid - 1));
	}
	else
	{
		return BSearch(mid + 1, e);
	}
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> X[i + 1];
	}

	// 1부터 최대길이 그 사이로 이분탐색
	cout << BSearch(1, X[N] - X[1] + 1);
}
