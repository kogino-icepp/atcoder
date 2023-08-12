#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <iomanip>
#include <atcoder/string>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<ll,ll> P;
ll W;
ll B;

void dfs(int v,vector<vector<int>>&G,vector<int>&color,bool &hantei){
    for(auto v2:G[v]){
        if(color[v2]!=-1){
            if(color[v2]==color[v]){hantei=false;}
            continue;
        }
        color[v2]=1-color[v];
        if(color[v2]==0)W++;
        else B++;
        dfs(v2,G,color,hantei);
    }
}
int main(){
    ll N,M;cin >> N >> M;
    Graph G(N+1);
    for(ll i=0;i<M;i++){
        int u,v;cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> color(N+1,-1);
    vector<ll> white;
    vector<ll> black;
    for(ll v=1;v<=N;v++){
        if(color[v]!=-1)continue;
        W=1;
        B=0;
        color[v]=0;
        bool hantei=true;
        dfs(v,G,color,hantei);
        if(!hantei){
            cout << 0 << endl;
            return 0;
        }
        //cout << W << " " << B << endl;
        white.push_back(W);
        black.push_back(B);
    }
    ll ans=(N*(N-1)/2)-M;
    for(auto w:white){
        ans-=w*(w-1)/2;
    }
    for(auto b:black){
        ans-=b*(b-1)/2;
    }
    cout << ans << endl;
}