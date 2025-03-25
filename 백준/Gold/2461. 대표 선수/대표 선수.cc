#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

vector<int> v[1001];

struct node {
	int ability;
	int cls;
	int number;
};

bool operator< (node left, node right)  {
	if (left.ability < right.ability)return false;
	return true;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			v[i].push_back(num);
		}
	}
	for (int i = 0; i < N; i++) {
		sort(v[i].begin(),v[i].end());
	}
	priority_queue < node> pq;
	int minn = 2134567890;
	int maxx = -1;
	int answer = 2134567890;
	for (int i = 0; i < N; i++) {
		maxx = max(maxx, v[i][0]);
		pq.push({ v[i][0],i,0 });
	}
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		// 가장 작은거 뽑기
		
		answer = min(answer, maxx - now.ability);
		if (now.number + 1 == M)break;
		maxx = max(maxx, v[now.cls][now.number + 1]);
		pq.push({ v[now.cls][now.number + 1],now.cls,now.number + 1 });
	}
	cout << answer;
}



/*
3 4
12 16 43 67
7 17 48 68
14 15 54 77

7 12 14 15 16 17 

17 16 14

*/