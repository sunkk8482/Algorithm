#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
using namespace std;


struct node {
	string name;
	int type;
};
unordered_map<string, vector<node>> files;
unordered_map<string, int> answer;

int n, m;
int t_cnt, f_cnt;

void func(string s) {
	for (auto i : files[s]) {
		if (i.type==0) {
			if (!answer[i.name]) {
				answer[i.name] = 1;
				t_cnt++;
			}
			f_cnt++;
			continue;
		}
		func(i.name);
	}
}

string tok(string s) {
	int slash_num = 0;
	
	for (auto i : s) {
		if (i == '/')slash_num++;
	}
	if (slash_num == 0)return s;
	string ret = "";
	while (slash_num) {
		ret= s.substr(s.find('/')+1);
		slash_num--;
	}
	return ret;
}

vector<string> parsing(string s) {
	vector<string> v;
	istringstream ss(s);
	string stringbuffer;

	while (getline(ss, stringbuffer, '/')) {
		v.push_back(stringbuffer);
	}
	return v;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		string a, b;
		int c;
		cin >> a >> b >> c;
		if (c == 1) {
			files[a].push_back({ b,1 });
		}
		else if (c == 0) {
			files[a].push_back({ b,0 });
		}
	}

	int l;
	cin >> l;
	for (int i = 0; i < l; i++) {
		string d;
		cin >> d;
		d = tok(d);
		vector<string> v = parsing(d);
		func(v.back());
		int dif= 0 ;
		int cnt = 0;
		cout << t_cnt << " " << f_cnt << "\n";
		answer.clear();
		t_cnt = 0;
		f_cnt = 0;
	}

}