#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
using namespace std;

int N, M;

int map[5000][5000];

struct ck {
	int y;
	int x;
};

struct house {
	int y;
	int x;
};

vector<ck> ckV;
vector<house> houses;

int visited[10000];
vector<ck> test;

int answer = 2134567890;
void fun(int level,int now) {

	if (level == M) {
		int sum = 0;
		for (int i = 0; i < houses.size(); i++) {
			int minn = 2134567890;
			for (int j = 0; j < test.size(); j++) {
				int dist = abs(houses[i].y - test[j].y) + abs(houses[i].x - test[j].x);
				minn = min(dist, minn);
			}
			sum += minn;
		}
		answer = min(answer, sum);
		return;
	}

	for (int i = now; i < ckV.size(); i++) {
		if (visited[i])continue;
		visited[i] = 1;
		test.push_back({ckV[i].y,ckV[i].x});
		
		fun(level + 1,i);
		test.pop_back();
		visited[i] = 0;
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				houses.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				ckV.push_back({ i,j });
			}
		}
	}
	fun(0, 0);
	cout << answer;
}