#include <string>
#include <vector>

using namespace std;

void change(string skip, char& from,int index)
{
    int cnt = 0;
    while (cnt < index)
    {
        if (from == 'Z')
            from = 'A';
        else if (from == 'z')
            from = 'a';
        else 
           from++;

        if (skip.find(from) == string::npos)
            cnt++;
    }
}

string solution(string s, string skip, int index) {
    string answer = s;
    for (int i = 0; i < s.size(); i++) {
        change(skip, answer[i], index);
    }
    return answer;
}