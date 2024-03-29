#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct node {
	int a, b;
	int cost;
};

int boss[1001];

int N, M;

vector<node> v;

bool compare_min(node left, node right) {
	if (left.cost < right.cost)return true;
	else return false;
}

bool compare_max(node left, node right) {
	if (left.cost > right.cost)return true;
	else return false;
}

void init() {
	for (int i = 0; i <= N; i++) {
		boss[i] = i;
	}
}

int find(int tar) {
	if (boss[tar] == tar)return tar;
	int ret = find(boss[tar]);
	boss[tar] = ret;
	return ret;
}

void set_union(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	boss[t1] = t2;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M + 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	//최소값 구하기
	init();
	int min_cnt = 0;
	int min_cost = 0;
	sort(v.begin(), v.end(), compare_min);
	for (auto i : v) {
		if (boss[find(i.a)] == boss[find(i.b)])continue;
		set_union(find(i.a), find(i.b));
		if (!i.cost) {
			min_cost++;
		}
	}

	//최댓값구하기
	init();
	int max_cost = 0;
	sort(v.begin(), v.end(), compare_max);
	for (auto i : v) {
		if (boss[find(i.a)] == boss[find(i.b)])continue;
		set_union(find(i.a), find(i.b));
		if (!i.cost) {
			max_cost++;
		}
	}
	cout << (int)pow(min_cost, 2) - (int)pow(max_cost, 2);


	
}