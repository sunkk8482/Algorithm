#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> v;
	vector<int> dat(2300001);
	for (int i = 0;i < n;i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		dat[tmp]++;
	}
	int x;
	cin >> x;
	int answer = 0;
	for (int i = 0;i < n;i++) {
		if (x - v[i] >= 0 && dat[x - v[i]] == 1 && x - v[i] > v[i]) {
			answer++;
		}
	}
	cout << answer;
}