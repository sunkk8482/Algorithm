#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;

vector<int> v;

int get_cnt(int mid) {
	int size = v.size();
	int now = v[0];
	int ret = 1;
	for (int i = 1; i < size; i++) {
		int dif = v[i] - now;
		if (dif >= mid) {
			ret++;
			now = v[i];
		}
	}
	return ret;
}

int main(){
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int left = 1;
	int right = v[v.size() - 1] - v[0];
	int answer = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = get_cnt(mid);
		if (cnt >= C) {
			answer = max(answer, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << answer;

}