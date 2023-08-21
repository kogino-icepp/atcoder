#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { //データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
    int N,M;cin >> N >> M;
    priority_queue<int,vector<int>,greater<int>> que;
    vector<int> C(N+1,0);
    vector<vector<int>> mp(N+1);
    rep(i,M){
        int A,B;cin >> A >> B;
        C[B]++;
        mp[A].push_back(B);
    }
    for(int i=1;i<=N;i++){
        if(C[i]==0)que.push(i);
    }
    vector<int> ans;
    while(!que.empty()){
        int v = que.top();
        que.pop();
        ans.push_back(v);
        for(auto nv:mp[v]){
            C[nv]--;
            if(C[nv]==0)que.push(nv);
        }
    }
    if((int)ans.size()==N){
        for(auto v:ans)cout << v << " ";
        cout << endl;
    }
    else cout << -1 << endl;
    
}