#include <iostream>
#include <string>
#include <string.h>
#include <unordered_set>

int score_dat[9] = { 0,0,0,1,1,2,3,5,11 };
using namespace std;

unordered_set<string> se;

struct Trie {
	bool finish;
	Trie* next[26];

	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i]) {
				delete next[i];
			}
		}
	}

	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
		}
		else {
			int curr = *key - 'A';
			if (next[curr] == NULL) {
				next[curr] = new Trie();
			}
			next[curr]->insert(key + 1);
		}
	}

	Trie* find(const char* key) {
		if (*key == '\0') {
			return this;
		}
		int curr = *key - 'A';
		if (next[curr] == NULL)return NULL;
		next[curr]->find(key + 1);
	}
};

char arr[30][4][4];

struct score {
	int score;
	string s;
	int num;
};

int visited[4][4];

int dy[8] = {-1,1,0,0,-1,-1,1,1};
int dx[8] = { 0,0,-1,1,-1,1,1,-1 };

score now_score = { 0,"",0 };

void dfs(Trie* now, int y,int x,int z,string s) {
	if (now->finish) {
		se.insert(s);

		//now_score.num++;
		//now_score.score += score_dat[s.length()];
		//if (now_score.s.length() < s.length()) {
		//	now_score.s = s;
		//}
		//else if (now_score.s.length() == s.length()){
		//	if (s > now_score.s) {
		//		now_score.s = s;
		//	}
		//}
	}

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)continue;
		if (visited[ny][nx])continue;

		if (now->next[arr[z][ny][nx]-'A'] == NULL)continue;
		string next_s = s + arr[z][ny][nx];
		visited[ny][nx] = 1;
		dfs(now->next[arr[z][ny][nx]-'A'],  ny, nx, z, next_s);
		visited[ny][nx] = 0;
	}

}

int main() {
	Trie* root = new Trie();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char s[9];
		cin >> s;
		root->insert(s);
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			string ss;
			cin >> ss;
			for (int k = 0; k < 4; k++) {
				arr[i][j][k] = ss.at(k);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		now_score = { 0,"",0 };
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (root->next[arr[i][j][k] - 'A'] != NULL) {
					string s = "";
					s += arr[i][j][k];
					visited[j][k] = 1;
					dfs(root->next[arr[i][j][k]-'A'], j, k, i, s);
					visited[j][k] = 0;
				}
			}
		}
		int aa = -1;
		int max_score=0;
		string answer="";
		int max_num;
		for (auto i : se) {
			max_score += score_dat[i.length()];
			if (answer.length() < i.length()) {
				answer = i;
			}
			else if (answer.length() == i.length()) {
				if (answer > i) {
					answer = i;
				}
			}
		}
		cout << max_score << " " << answer << " " << se.size() << "\n";
		se.clear();
	}
}