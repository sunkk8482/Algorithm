#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 10001;
vector<bool> leave(MAX_SIZE, false); 
map<int, pair<int, int>> user; 
vector<vector<bool>> seated; 


double nearest_dist(int x, int y) {
    double dist = numeric_limits<double>::max();


    for (auto& u : user) {
        int ux = u.second.first, uy = u.second.second;
        double d = sqrt(pow(x - ux, 2) + pow(y - uy, 2));
        dist = min(dist, d);
    }

    return dist;
}


bool assign(int user_id, int N, int M) {
    double max_dist = 0;
    pair<int, int> nearest_dist_pos = { -1, -1 };


    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (seated[i][j] || seated[i + 1][j] || seated[i - 1][j] || seated[i][j - 1] || seated[i][j + 1])
                continue;

            double d = nearest_dist(i, j);

            if (d > max_dist) {
                nearest_dist_pos = make_pair(i, j);
                max_dist = d;
            }
        }
    }

    if (!user.empty() && max_dist <= 1)
        return false;


    user[user_id] = nearest_dist_pos;
    seated[nearest_dist_pos.first][nearest_dist_pos.second] = true;

    return true;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    seated.resize(N + 2, vector<bool>(M + 2, false)); 

    for (int i = 0; i < Q; ++i) {
        string op;
        int user_id;
        cin >> op >> user_id;

        if (op == "In") { 
            if (user.find(user_id) != user.end()) {
                cout << user_id << " already seated.\n";
            }
            else if (leave[user_id]) {
                cout << user_id << " already ate lunch.\n";
            }
            else {
                if (assign(user_id, N, M)) {
                    cout << user_id << " gets the seat (" << user[user_id].first << ", " << user[user_id].second << ").\n";
                }
                else {
                    cout << "There are no more seats.\n";
                }
            }
        }
        else { 
            if (leave[user_id]) {
                cout << user_id << " already left seat.\n";
            }
            else if (user.find(user_id) == user.end()) {
                cout << user_id << " didn't eat lunch.\n";
            }
            else {
                leave[user_id] = true;
                seated[user[user_id].first][user[user_id].second] = false;
                cout << user_id << " leaves from the seat (" << user[user_id].first << ", " << user[user_id].second << ").\n";
                user.erase(user_id);
            }
        }
    }

    return 0;
}