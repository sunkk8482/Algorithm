/*

우주신 N 통로 M

우주신 좌표

통로

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;

struct node {
	int y;
	int x;
};

struct line {
	int start;
	int end;
	double dist;
};

int arr[2000];

void init() {
	for (int i = 0; i < 2000; i++) {
		arr[i] = i;
	}
}

int find(int t) {
	if (arr[t] == t)return t;
	int ret = find(arr[t]);
	arr[t] = ret;
	return ret;
}

void set_union(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	arr[t2] = t1;
}

bool compare(line a, line b) {
	if (a.dist < b.dist)return true;
	return false;
}

int main() {
	init();
	cin >> N >> M;
	
	vector<node> people;

	vector<line> lines;

	for (int i = 0; i < N; i++) {
		int y, x;
		cin >> y >> x;
		people.push_back({ y,x });
	}

	int cnt = 0;

	for (int i = 0; i < M; i++) {
		
		int a, b;
		cin >> a >> b;
		
		if (find(a) != find(b)) {
			set_union(a, b);
			cnt++;
		}
	}

	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j<N; j++) {
			node a = people[i];
			node b = people[j];
			double dist = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
			lines.push_back({ i+1,j+1,dist });
		}
	}

	sort(lines.begin(), lines.end(), compare);

	

	
	double answer = 0;

	for (auto i : lines) {
		if (cnt == N - 1)break;
		if (find(i.start) == find(i.end))continue;
		set_union(i.start, i.end);
		cnt++;
		answer += i.dist;
	}

	printf("%.2f", answer);


}