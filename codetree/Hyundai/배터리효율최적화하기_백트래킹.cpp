#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
int arr[15][15];
int visited[15][15];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

set<vector<int>> se;

void reset()
{
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            visited[i][j] = 0;
        }
    }
}

bool inNear(const vector<int>& near, int point)
{
    return find(near.begin(), near.end(), point) != near.end();
}

void bt(vector<int> route, vector<int> near)
{
    if (route.size() == 5)
    {
        sort(route.begin(), route.end());
        se.insert(route);
        return;
    }

    int now = route.back();
    int y = now / 10000;
    int x = now % 10000;

    // near 계산
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (visited[ny][nx]) continue;

        int np = ny * 10000 + nx;
        if (inNear(near, np)) continue;

        near.push_back(np);
    }

    // 백트래킹
    for (auto point : near)
    {
        int y = point / 10000;
        int x = point % 10000;
        if (visited[y][x]) continue;

        vector<int> nextroute = route;
        nextroute.push_back(point);

        visited[y][x] = 1;
        bt(nextroute, near);
        visited[y][x] = 0;
    }
}

bool check(vector<int> first, vector<int> second)
{
    int i = 0, j = 0;
    int cnt = 0;

    while (i < first.size() && j < second.size())
    {
        if (first[i] < second[j]) i++;
        else if (first[i] > second[j]) j++;
        else {
            cnt++;
            i++;
            j++;
        }
    }

    return cnt == 2;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vector<int> rt;
            vector<int> nr;
            rt.push_back(i * 10000 + j);
            visited[i][j] = 1;
            bt(rt, nr);
            reset();
        }
    }

    vector<vector<int>> routes;
    for (auto rt : se) routes.push_back(rt);

    int answersum = -2134567890;

    for (int i = 0; i < routes.size() - 1; i++) {
        for (int j = i + 1; j < routes.size(); j++) {
            if (check(routes[i], routes[j]))
            {
                int sum = 0;
                for (auto p : routes[i]) sum += arr[p / 10000][p % 10000];
                for (auto p : routes[j]) sum += arr[p / 10000][p % 10000];
                answersum = max(sum, answersum);
            }
        }
    }

    cout << answersum;
}
