#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

vector<int> crain;
vector<int> box;



int main() {
	int n;
	cin >> n;
	crain = vector<int>(n);

	for (int i = 0; i < n; i++) {
		cin >> crain[i];
	}
	cin >> n;
	box = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}
	sort(crain.begin(), crain.end());
	sort(box.begin(), box.end());
	int cnt = 0;
	if (crain.back() < box.back()) {
		cout << -1;
		return 0;
	}
	while (!box.empty()) {
		cnt++;
		for (int i = crain.size() - 1; i >= 0; i--) {
			for (int j = box.size() - 1; j >= 0; j--) {
				if (crain[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
	}
	cout << cnt;

}