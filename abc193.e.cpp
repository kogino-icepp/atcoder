#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <iomanip>
#include <cassert>
#include <numeric>
using namespace std;
typedef long long ll;
const int mod=1000000007;
using Graph=vector<vector<int>>;
const int limit=1000000;
struct UnionFind{
    vector<int> r;
    UnionFind(int N){
        r=vector<int>(N,-1);
    }
    int root(int x){
        if(r[x]<0)return x;
        return r[x]=root(r[x]);
    }
    bool unite(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y)return false;
        if(r[x]>r[y])swap(x,y);
        r[x]+=r[y];
        r[y]=x;
        return true;
    }
    int size(int x){
        return -r[root(x)];
    }
    
};
void dfs(int v, vector<bool>&visited, vector<vector<int>>&chs,int &ans){
    if(ans==limit)return;
    ans++;
    visited[v]=true;
    for(auto nv:chs[v]){
        if(visited[nv])continue;
        dfs(nv,visited,chs,ans);
    }
}
int main(){
    int N;cin >> N;
    vector<int> X(N);
    vector<int> Y(N);
    for(int i=0;i<N;i++) cin >> X[i] >> Y[i];
    //マンハッタン距離 基本解答は45度回転させると便利になることが多いらしい(マンハッタン距離の最大値はせいぜい8通りなので)
    vector<int> V(N);
    vector<int> W(N);
    for(int i=0;i<N;i++){
        V[i]=X[i]+Y[i];
        W[i]=X[i]-Y[i];
    }
    
    sort(V.begin(),V.end());
    sort(W.begin(),W.end());
    cout << max(W[N-1]-W[0],V[N-1]-V[0]) << endl;
}