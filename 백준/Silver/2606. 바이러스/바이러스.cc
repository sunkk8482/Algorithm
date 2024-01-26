#include <iostream>
#include<vector>
#include <set>
using namespace std;

vector<int> v[101];
int n;
int m;
set<int> answer;
int visited[101];
int cnt = 0;
void fun(int node) {
	if (visited[node])return;
	visited[node] = 1;
	for (int i = 0; i < v[node].size(); i++) {
		fun(v[node][i]);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	fun(1);
	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		if (visited[i] == 1) {
			cnt++;
		}
	}
	cout << cnt - 1;
}