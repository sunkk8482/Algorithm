#include <iostream>
#include <unordered_map>

using namespace std;

struct trie {
	unordered_map<char, trie*>um;
	bool isEnd;
};
string s;
int N;
trie* root;
double ret;

void fun(trie* cur, int cnt) {
	int son = cur->um.size() > 1 ? 1 : 0;
	if ((cur->um.size() == 1) && (cur->isEnd)) {
		son = 1;
	}
	if (cur->isEnd) {
		ret += cnt;
	}
	for (auto next : cur->um) {
		fun(next.second, cnt + son);
	}
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cout << fixed;
	cout.precision(2);
	root = new trie();

	while (cin >> N) {
		root->isEnd = false;
		root->um.clear();
		ret = 0;
		for (int i = 0; i < N; i++) {
			trie* cur = root;
			cin >> s;
			for (char c : s) {
				if (cur->um.find(c) == cur->um.end()) {
					cur->um[c] = new trie();
				}
				cur = cur->um[c];
			}
			cur->isEnd = true;
		}
		for (auto next : root->um) {
			fun(next.second, 1);
		}
		ret /= N;
		cout << ret << "\n";
	}
}