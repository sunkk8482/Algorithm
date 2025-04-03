#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

int get_dist(int x, int y, int a, int b) {
    return abs(x - a) + abs(y - b);
}

struct info {
    int n;
    int m;
    int r;
    int c;
    int k;
};

bool finish = false;

char move_ch[4] = { 'd','l','r','u'};

int dy[4] = { 0,-1,1,0 };
int dx[4] = { 1,0,0,-1 };
string ans = "";

void dfs(int x, int y, info in, int cnt, string s) {
    if (!finish) {
        int dist = get_dist(x, y, in.r, in.c);
        if (in.k - cnt - dist < 0)return;
        if ((in.k - cnt - dist) % 2 == 1)return;
        
        if (cnt == in.k) {
            if (x == in.r && y == in.c) {
                finish = true;
                ans = s;
            }
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx<1 || ny<1 || nx>in.n || ny>in.m)continue;
            dfs(nx, ny, in, cnt + 1, s + move_ch[i]);
            if (finish)break;
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    dfs(x, y, { n,m,r,c,k }, 0, "");
    if (finish) {
        answer = ans;
    }
    else {
        answer = "impossible";
    }
    return answer;
}
