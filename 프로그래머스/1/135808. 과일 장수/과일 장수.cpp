#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end());
    int cnt = 0;
    int minn = 2134567890;
    for (int i = score.size() - 1; i >= 0; i--)
    {

        minn = min(minn, score[i]);
        cnt++;
        if (cnt == m)
        {
            answer += (minn * m);
            cnt = 0;
            minn = 2134567890;
        }
    }
    return answer;
}