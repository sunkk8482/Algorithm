#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int par[100001];

struct tree{
    int x1, x2, num;
}arr[100001];

bool cmp (const tree &a, const tree &b){
    return a.x1 < b.x1;
}

int find(int num){
    if(num==par[num]) return num;
    return par[num] = find(par[num]); 
}
void unite(int a, int b){
    int pa=find(a), pb=find(b);
    par[pa]=pb;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        par[i] = i;
        cin>> arr[i].x1 >> arr[i].x2 ;
        int y; cin>>y;
        arr[i].num=i;
    }
    sort(arr+1, arr+n+1, cmp);

    int idx=1, end=arr[1].x2;
    for(int i=2; i<=n; i++){
        if(arr[i].x1 <= end){
            if(arr[i].x2 <= end) unite(arr[idx].num, arr[i].num);
            else{
                unite(arr[idx].num, arr[i].num);
                idx=i, end=arr[i].x2;
            }
        }
        else{
            idx=i, end=arr[i].x2;
        }
    }

    for(int i=0; i<q; i++){
        int a,b; cin>>a>>b;
        if(find(a)==find(b)) cout<<"1\n";
        else cout<<"0\n";
    }
    return 0;
}