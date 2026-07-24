#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<long long> vNum;
    while (n != 0)
    {
        vNum.push_back(n % 10);
        n /= 10;
    }
    sort(vNum.rbegin(), vNum.rend());
    for (auto s : vNum)
    {
        answer *= 10;
        answer += s;

    }
    return answer;
}