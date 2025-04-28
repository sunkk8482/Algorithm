#include <iostream>
#include <vector>

using namespace std;

int arr[21][21];
int visited[21][21];

int n, m;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
};

vector<node> start;
vector<int> v;
vector<vector<int>> permutation;

void makePermutation(int n, int r, int depth) {
	if (r == depth) {
		vector<int> n;
		for (auto i : v) {
			n.push_back(i);
		}
		permutation.push_back(n);
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(v[i], v[depth]);
		makePermutation(n, r, depth + 1);
		swap(v[i], v[depth]);
	}
}
vector<node> max_route;
int max_sum = 0;
void dfs(int y, int x, int sum, vector<node> route) {
	if (route.size() == 4) {
		if (sum > max_sum) {
			max_sum = sum;
			max_route = route;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (visited[ny][nx])continue;
		visited[ny][nx] = 1;
		vector<node> next = route;
		next.push_back({ ny,nx });
		dfs(ny, nx, sum + arr[ny][nx], next);
		visited[ny][nx] = 0;
	}
}

int calc(vector<int> seq) {
	int ret = 0;
	vector<int> startfruit;
	for (auto i : start) {
		startfruit.push_back(arr[i.y][i.x]);
	}
	for (auto i : seq) {
		for (int j = 0; j < m; j++) {
			if (i != j) {
				arr[start[j].y][start[j].x] = 0;
			}
		}
		int y = start[i].y;
		int x = start[i].x;
		visited[y][x] = 1;
		dfs(y, x, arr[y][x], { {y,x} });
		for (auto i : max_route) {
			arr[i.y][i.x] = 0;
		}
		max_route.clear();
		ret += max_sum;
		max_sum = 0;
		for (int j = 0; j < m; j++) {
			if (i != j) {
				arr[start[j].y][start[j].x] = startfruit[j];
			}
		}
	}
	return ret;
}

int main() {
	int answer = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		v.push_back(i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int y, x;
		cin >> y >> x;
		start.push_back({ y - 1,x - 1 });
	}
	makePermutation(m, m, 0);
	int origin[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			origin[i][j] = arr[i][j];
		}
	}

	for (auto i : permutation) {
		int ret = calc(i);
		answer = max(ret, answer);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = origin[i][j];
			}
		}
		fill(visited[0], visited[21], 0);
	}
	cout << answer;
}