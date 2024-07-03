#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N,K;

int v[1000000];

int cnt[30];

long long answer;

int main()
{
    cin>>N>>K;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        v[i]=s.size();
    }
    
    for(int i=0;i<=K;i++)
    {
        cnt[v[i]]++;
    }
    
    for(int i=0;i<N-1;i++){
        cnt[v[i]]--;
        answer+=cnt[v[i]];
        cnt[v[i+K+1]]++;
    }
    
    cout<<answer;

    return 0;
}