#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int index = 0;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] == ' ')
        {
            index = 0;
            continue;
        }
        if (index % 2 == 0)
        {
            if (s[i] <= 'z' && s[i] >= 'a')
            {
                s[i] -= 32;
            }
        }
        else
        {
            if (s[i] <= 'Z' && s[i] >= 'A')
            {
                s[i] += 32;
            }
        }
        index++;
    }
    return s;
}

int main()
{
    string s = solution("try hello world");
}