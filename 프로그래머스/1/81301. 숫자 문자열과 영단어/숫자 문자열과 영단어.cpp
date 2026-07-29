#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	string answer = "";
	vector<int> visited(s.size() + 1, 0);
	for (int i = 0; i < s.size(); i++)
	{
		if (visited[i])continue;
		if (s[i] <= '9' && s[i] >= '0')
		{
			answer = answer + s[i];
			visited[i] = 1;
		}
		else
		{
			switch (s[i])
			{
			case 'z':
			{
				answer = answer + '0';
				for (int j = i; j < i + 4; j++)
				{
					visited[j] = 1;
				}
			}
			break;
			case 'o':
			{
				answer = answer + '1';
				for (int j = i; j < i + 3; j++)
				{
					visited[j] = 1;
				}
			}
			break;
			case 't':

			{
				if (s.substr(i, 3) == "two")
				{
					answer = answer + '2';
					for (int j = i; j < i + 3; j++)
					{
						visited[j] = 1;
					}
				}
				else
				{
					answer = answer + '3';
					for (int j = i; j < i + 5; j++)
					{
						visited[j] = 1;
					}
				}
			}
			break;
			case 'f':
			{
				if (s.substr(i, 4) == "four")
				{
					answer = answer + '4';
					for (int j = i; j < i + 4; j++)
					{
						visited[j] = 1;
					}
				}
				else
				{
					answer = answer + '5';
					for (int j = i; j < i + 4; j++)
					{
						visited[j] = 1;
					}
				}
			}
				break;
			case 's':
			{
				if (s.substr(i, 3) == "six")
				{
					answer = answer + '6';
					for (int j = i; j < i + 3; j++)
					{
						visited[j] = 1;
					}
				}
				else
				{
					answer = answer + '7';
					for (int j = i; j < i + 5; j++)
					{
						visited[j] = 1;
					}
				}
			}
				break;
			case 'e':
			{
				answer = answer + '8';
				for (int j = i; j < i + 5; j++)
				{
					visited[j] = 1;
				}
			}
				break;
			case 'n':
			{
				answer = answer + '9';
				for (int j = i; j < i + 4; j++)
				{
					visited[j] = 1;
				}
			}
				break;
			}
		}
	}



	return stoi(answer);
}