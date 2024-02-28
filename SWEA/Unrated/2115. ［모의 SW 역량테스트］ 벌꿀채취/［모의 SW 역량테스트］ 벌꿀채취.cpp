#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, C;

int map[10][10];

int visited[10][10];

vector<int> one;
vector<int> two;



int fun() {

	int one_limit = pow(2, one.size());
	int two_limit = pow(2, two.size());

	int one_max = 0;
	int two_max = 0;
	for (int i = 0; i < one_limit; i++) {
		int tar = i;
		int sum = 0;
		int ret = 0;
		for (int j = 0; j < one.size(); j++) {
			if (tar & 0x1) {
				sum += one[j];
				ret += pow(one[j], 2);
			}
			tar >>= 1;
		}
		if (sum <= C) {
			one_max = max(one_max, ret);
		}
	}
	for (int i = 0; i < two_limit; i++) {
		int tar = i;
		int sum = 0;
		int ret = 0;
		for (int j = 0; j < two.size(); j++) {
			if (tar & 0x1) {
				sum += two[j];
				ret += pow(two[j], 2);
			}
			tar >>= 1;
		}
		if (sum <= C) {
			two_max = max(two_max, ret);
		}
	}
	return two_max + one_max;
}

void program() {
	cin >> N >> M >> C;

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j + M - 1 >= N)continue;
			for (int k = 0; k < M; k++) {
				visited[i][j + k] = 1;
				one.push_back(map[i][j + k]);
			}
			
			for (int k = i; k < N; k++) {
				if (k == i) {
					if (j + M >= N)continue;
					for (int l = j+M; l < N; l++) {


						if (l + M - 1 >= N)continue;
						for (int m = 0; m < M; m++) {
							visited[k][l + m] = 2;
							two.push_back(map[k][l + m]);
						}

						int ret = fun();
						result = max(result, ret);

						for (int m = 0; m < M; m++) {
							visited[k][l + m] = 0;
							two.clear();
						}
					}
				}
				else {
					for (int l = 0; l < N; l++) {
						if (l + M - 1 >= N)continue;
						for (int m = 0; m < M; m++) {
							visited[k][l + m] = 2;
							two.push_back(map[k][l + m]);
						}
						int ret = fun();
						result = max(result, ret);


						for (int m = 0; m < M; m++) {
							visited[k][l + m] = 0;
							two.clear();
						}
					}
				}


				
			}
			for (int k = 0; k < M; k++) {
				visited[i][j + k] = 0;
				one.clear();
			}
		}
	}
	cout << result;

}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "#" << i + 1 << " ";
		program();
		cout << "\n";
	}

}