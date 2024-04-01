#include <iostream>
#include <vector>
#include<algorithm>
#include <map>
using namespace std;

int boss[100001];

int N;

struct node {
	int x;
	int y;
	int z;
	int index;
};

struct link {
	int start;
	int end;
	int cost;
};

vector<node> xv;
vector<node> yv;
vector<node> zv;

vector<link> lv;

void init() {
	for (int i = 0; i <=N; i++) {
		boss[i] = i;
	}
}

int find(int tar) {
	if (boss[tar] == tar)return tar;
	int ret = find(boss[tar]);
	boss[tar] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	boss[t2] = t1;
}

bool compare_x(node left, node right) {
	if (left.x < right.x) {
		return true;
	}
	else return false;
}
bool compare_y(node left, node right) {
	if (left.y < right.y) {
		return true;
	}
	else return false;
}
bool compare_z(node left, node right) {
	if (left.z < right.z) {
		return true;
	}
	else return false;
}

bool compare(link left, link right) {
	if (left.cost < right.cost)return true;
	else return false;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		xv.push_back({ a,b,c,i });
		yv.push_back({ a,b,c,i });
		zv.push_back({ a,b,c,i });
	}

	sort(xv.begin(), xv.end(),compare_x);
	sort(yv.begin(), yv.end(), compare_y);
	sort(zv.begin(), zv.end(), compare_z);

	for (int i = 0; i < N-1; i++) {
		lv.push_back({ xv[i].index,xv[i + 1].index,xv[i + 1].x - xv[i].x });
		lv.push_back({ yv[i].index,yv[i + 1].index,yv[i + 1].y - yv[i].y });
		lv.push_back({ zv[i].index,zv[i + 1].index,zv[i + 1].z - zv[i].z });
	}

	sort(lv.begin(), lv.end(), compare);

	init();
	int unionCnt = 0;
	int sum = 0;
	for (int i = 0; i < lv.size(); i++) {
		int a = find(lv[i].start);
		int b = find(lv[i].end);
		if (a == b)continue;
		setUnion(a, b);
		unionCnt++;
		sum += lv[i].cost;
		if (unionCnt == N - 1)break;
	}
	cout << sum;

}