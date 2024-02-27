#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
map<string, int> boss;
int cnt[200020], parent[200020];

int find(int node) {
	if (parent[node] == node)return node;
	return parent[node] = find(parent[node]);
}

int setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return cnt[t1];
	if (t1 > t2)swap(t1, t2);
	parent[t2] = t1;
	cnt[t1] += cnt[t2];
	return cnt[t1];
}

void program() {
	boss.clear();
	for (int i = 0; i < 200010;i++) {
		cnt[i] = 1;
		parent[i] = i;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (boss.count(a) == 0) boss[a] = boss.size();
		if (boss.count(b) == 0) boss[b] = boss.size();
		cout << setUnion(boss[a], boss[b])<<"\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		program();
	}
}