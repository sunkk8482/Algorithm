#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,E;

struct node{
    int end;
    int dist;
};

bool operator<(node left,node right){
    if(left.dist<right.dist)return false;
    else return true;
}

int dist[1000];

vector<node> v[1000];

priority_queue<node> pq;

void init(){
    for(int i=0;i<1000;i++){
        dist[i]=2134567890;
    }
}

void djkstra(int start){
    pq.push({start,0});
    dist[start]=0;
    while(!pq.empty()){
        node now = pq.top();
        pq.pop();
        if(now.dist>dist[now.end])continue;
        for(auto i : v[now.end]){
            int nextdist = dist[now.end] + i.dist;
            if(nextdist>dist[i.end])continue;
            pq.push({i.end,nextdist});
            dist[i.end]=nextdist;
        }
    }
}

int main()
{
    cin>>N>>E;
    for(int i=0;i<E;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    
    int v1,v2;
    cin>>v1>>v2;
    

    
    int dist_one=0;
    int dist_two=0;
    init();
    djkstra(1);
    int zero_one = dist[v1];
    int zero_two = dist[v2];
    
    init();
    djkstra(v1);
    int one_two = dist[v2];
    int one_N=dist[N];

    
    init();
    djkstra(v2);
    int two_one = dist[v1];
    int two_N=dist[N];
    
    int d1 = zero_one+one_two+two_N;
    int d2 = zero_two+one_two+one_N;
    int answer = min(d1,d2);
    if(one_two>=2134567890||answer>=2134567890){
        cout<<-1;
        return 0;
    }
    cout<<answer;
    
    return 0;
}