#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int record[2][1001];
struct info {
	int first;
	int second;
	int ftos;
	int stof;
};

int main() {
	cin >> N;
	vector<info> v;
	fill(record[0], record[2], 2134567890);
	v.push_back({ 0,0,0,0 });
	for (int i = 0; i < N - 1; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({ a,b,c,d });
	}
	int lasta, lastb;
	cin >> lasta >> lastb;
	v.push_back({ lasta,lastb,0,0 });
	record[0][1] = v[1].first;
	record[1][1] = v[1].second;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			int next;
			//그대로 가는거
			if (j == 0) {
				next = record[j][i] + v[i + 1].first;
			}
			else if (j == 1) {
				next = record[j][i] + v[i + 1].second;
			}	
			if (record[j][i + 1] > next) record[j][i + 1] = next;
			// 전환
			if (j == 0) {
				next = record[j][i] + v[i + 1].second + v[i].ftos;
				if (record[1][i + 1] > next) record[1][i + 1] = next;
			}
			else if (j == 1) {
				next = record[j][i] + v[i + 1].first + v[i].stof;
				if (record[0][i + 1] > next) record[0][i + 1] = next;
			}
		}
	}

	cout << min(record[0][N], record[1][N]);

}