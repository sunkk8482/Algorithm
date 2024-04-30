#include <iostream>
#include <algorithm>
#include <vector>

#include <cmath>
using namespace std;

struct node {
	int start;
	int end;
	double dist;
};

struct star {
	double x;
	double y;
	int index;
};

int arr[101];

void init() {
	for (int i = 0; i <= 100; i++) {
		arr[i] = i;
	}
}

int find(int tar) {
	if (arr[tar] == tar)return tar;
	int ret = find(arr[tar]);
	arr[tar] = ret;
	return ret;
}

void set_union(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	arr[t2] = t1;
}

bool compare(node left, node right) {
	if (left.dist < right.dist)return true;
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<star> stars;
	vector<node> v;

	for (int i = 1; i <= n; i++) {
		double a, b;
		cin >> a >> b;
		stars.push_back({ a,b,i });
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			double dist = sqrt(pow(stars[i].x - stars[j].x, 2) + pow(stars[i].y - stars[j].y, 2));
			v.push_back({ i,j,dist });
		}
	}

	sort(v.begin(), v.end(), compare);

	int cnt = n - 1;
	init();
	double answer = 0;
	for (auto i : v) {
		if (cnt == 0)break;
		int n1 = i.start;
		int n2 = i.end;
		if (find(n1) == find(n2))continue;
		set_union(n1, n2);
		cnt--;
		answer += i.dist;
	}

	cout << round(answer * 100) / 100;
}