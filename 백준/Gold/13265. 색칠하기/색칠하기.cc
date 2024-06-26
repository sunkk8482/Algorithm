#include <iostream>
#include <vector>

using namespace std;

vector<int> circle;
vector<vector<int>> line;
bool check;

void dfs(int idx) {
	for (auto i : line[idx]) {
		if (!circle[i]) {
			circle[i] = circle[idx] * -1;
			dfs(i);
		}
		if (circle[idx] == circle[i]) check = false;
	}
}

void play() {
	int n, m;
	cin >> n >> m;

	circle = vector<int>(n + 1);
	line = vector<vector<int>>(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		line[a].push_back(b);
		line[b].push_back(a);
	}
	check = true;
	for (int i = 1; i <= n; i++) {
		if (!circle[i]) {
			circle[i] = 1;
			dfs(i);
		}
	}
	if (check)cout << "possible\n";
	else cout << "impossible\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		play();
	}
}