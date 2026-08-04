#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> left, pair<double, int> right)
{
    if (left.first > right.first)return true;
    else if (left.first == right.first) {
        if (left.second < right.second)return true;
    }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<pair<double, int>> rates;

    sort(stages.begin(), stages.end());

    for (int stage = 1; stage <= N; ++stage) {
        auto first = lower_bound(stages.begin(), stages.end(), stage);
        auto last = upper_bound(stages.begin(), stages.end(), stage);

        int stuck = last - first;               
        int reached = stages.end() - first;   

        double failureRate = 0.0;

        if (reached > 0) {
            failureRate = static_cast<double>(stuck) / reached;
        }

        rates.push_back({ failureRate, stage });
    }
    sort(rates.begin(), rates.end(), compare);
    vector<int> answer;
    for (int i = 0; i < rates.size(); i++)
    {
        answer.push_back(rates[i].second);
    }
    return answer;
}