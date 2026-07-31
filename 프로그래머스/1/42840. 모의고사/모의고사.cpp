#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr1 = { 1,2,3,4,5 };
vector<int> arr2 = { 2,1,2,3,2,4,2,5 };
vector<int> arr3 = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
    int a = 0;
    int b = 0;
    int c = 0;
    vector<int> answer;
    int maxx = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == arr1[i % arr1.size()  ])
        {
            a++;
            maxx = max(a, maxx);
        }
        if (answers[i] == arr2[i%arr2.size()])
        {
            b++;
            maxx = max(b, maxx);
        }
        if (answers[i] == arr3[i%arr3.size()])
        {
            c++;
            maxx = max(c, maxx);
        }
    }
    if (maxx == a)
    {
        answer.push_back(1);
    }

    if (maxx == b)
    {
        answer.push_back(2);
    }

    if (maxx == c)
    {
        answer.push_back(3);
    }
    return answer;
}