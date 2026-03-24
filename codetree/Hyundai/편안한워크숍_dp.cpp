// N 배열의 길이 K 최소 길이

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int arr[110][110];


struct node
{
	int h;
	int y;
	int x;
};

bool compare(node left, node right)
{
	if (left.h < right.h)return true;
	return false;
}

vector<node> v;
int dp[110][110];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool check(int n)
{
	// n 이하가 되도록 높이가 낮은곳에서 부터 dp 확인
	int maxRouteLength = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = 1;
		}
	}

	for (auto& point : v)
	{
		for (int i = 0; i < 4; i++) {
			int ny = point.y + dy[i];
			int nx = point.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			int diff = arr[point.y][point.x] - arr[ny][nx];
			if (diff <= 0)continue;
			if (diff > n)continue;
			dp[point.y][point.x] = max(dp[point.y][point.x], 1 + dp[ny][nx]);
		}
		maxRouteLength = max(maxRouteLength, dp[point.y][point.x]);
		if (maxRouteLength >= K)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> N >> K;
	int minHeight = 2134567890, maxHeight = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			minHeight = min(minHeight, arr[i][j]);
			maxHeight = max(maxHeight, arr[i][j]);
			v.push_back({ arr[i][j],i,j });
		}
	}
	sort(v.begin(), v.end(), compare);

	// 이분탐색으로 가능한 최소 높이 구하기
	int left = 1;
	int right = maxHeight - minHeight;
	int answer = 2134567890;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (check(mid))
		{
			answer = min(answer, mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (answer == 2134567890)
	{
		cout << -1;
	}
	else {
		cout << answer;
	}

}


