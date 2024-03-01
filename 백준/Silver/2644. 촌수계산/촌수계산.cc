#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr[101];

int visited[101];
bool findd = false;
void fun(int to, int from, int level) {
	if (to == from) {
		findd = true;
		cout << level;
		return;
	}

	for (int i = 0; i < arr[to].size(); i++) {
		if (visited[arr[to][i]])continue;
		visited[arr[to][i]] = 1;
		fun(arr[to][i], from, level + 1);
		visited[arr[to][i]] = 0;
	}


}

int main() {
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	fun(a, b,0);

	if (findd == false) {
		cout << -1;
	}
}