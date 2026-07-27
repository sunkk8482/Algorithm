#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for (int i = p.size(); i <= t.size(); i++)
    {
        if (stoll(t.substr(i - p.size(), p.size())) <= stoll(p))answer++;
    }
    return answer;
}