#include <string>
#include <vector>

#include <math.h>
using namespace std;

string tobit(int n,int num)
{
    string ret = "";
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        ret = ((num & 0x01) == 0) ? "0" + ret : "1" + ret;
        num >>= 1;
        cnt++;
    }
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> sarr1;
    vector<string>sarr2;
    for (auto i : arr1)
    {
        sarr1.push_back(tobit(n,i));
    }
    for (auto i : arr2)
    {
        sarr2.push_back(tobit(n,i));
    }
    for (int i = 0; i < n; i++) {
        string temp = "";
        for (int j = 0; j < n; j++) {
            if (sarr1[i][j] == '1' || sarr2[i][j] == '1')
            {
                temp.push_back('#');
            }
            else {
                temp.push_back(' ');
            }
        }
        answer.push_back(temp);
    }
    return answer;
}

int main()
{
    solution(6, { 46,33,33,22,31,50 }, { 27,56,19,14,14,10 });
}