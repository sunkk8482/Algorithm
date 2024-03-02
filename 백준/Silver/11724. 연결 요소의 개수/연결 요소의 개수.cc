#include <iostream>
#include <vector>

using namespace std;

int visited[1000001];

vector<int> v[1001];

int N, M;


void fun(int n) {
	visited[n] = 1;

	for (int i = 0; i < v[n].size(); i++) {
		if (visited[v[n][i]])continue;
		fun(v[n][i]);
	}
}

int main() {
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;

		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++){
		if (visited[i] == 0) {
			answer++;
			fun(i);
		}
	}
	cout << answer;
}