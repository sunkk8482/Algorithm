#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;

int arr[9];
int answer[9];
int visited[9];
void fun(int level) {
	if (level == M) {
		for (int i = 0; i < level; i++) {
			cout << answer[i]<<" ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		answer[level] = i;
		fun(level + 1);
	}
}

int main() {
	cin >> N>>M;
	fun(0);
}