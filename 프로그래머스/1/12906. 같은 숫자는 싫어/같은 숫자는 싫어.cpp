#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int prev = -1;
    vector<int> answer;
    for (auto i : arr)
    {
        if (i != prev) {
            prev = i;
            answer.push_back(i);
        }
    }

    return answer;
}