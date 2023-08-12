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
#include <deque>
#include <stack>
#include <tuple>
#include <atcoder/modint>
#define rep(i,n) for(int i=0;i<n;i++)
#define prep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fore(i,v) for(auto& i:v)
using namespace std;
using namespace atcoder;
using mint = modint998244353;
typedef long long ll;
const ll mod=1000000007;
const ll INF = 101010101000;

template<typename T>
using Graph=vector<vector<int>>;
map<ll,ll> prime_factor(ll n){
    map<ll,ll> ret;
    for(ll i=2;i*i<=n;i++){
        ll tmp=0;
        while(n%i==0){
            tmp++;
            n/=i;
        }
        ret[i]=tmp;
    }
    if(n!=1)ret[n]=1;
    return ret;
}
ll divisor_num(ll n){
    map<ll,ll> pf=prime_factor(n);
    ll ret=1;
    for(auto p:pf){
        ret*=(p.second+1);
    }
    return ret;
}
void rle(string s,vector<pair<char,int>>&vec){
    int cnt=1;
    int l = s.size();
    for(int i=1;i<l;i++){
        if(s[i]!=s[i-1]){
            vec.push_back({s[i-1],cnt});
            cnt=0;
        }
        cnt++;
    }
    vec.push_back({s.back(),cnt});
}

/*struct UnionFind {
    vector<int> par; // par[i]:iの親の番号

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
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
};*/
bool wakunai(int h,int w,int H,int W){
    if(h<0 || h>=H || w<0 || w>=W)return false;
    else return true;
}

int main(){
    int H,W;cin >> H >> W;
    vector<string> mp(H);
    rep(i,H)cin >> mp[i];
    if(mp[0][0]!='s'){
        cout << "No" << endl;
        return 0;
    }
    string snuke = "snuke";
    vector<char> next(256);
    next['s'] = 'n';
    next['n'] = 'u';
    next['u'] = 'k';
    next['k'] = 'e';
    next['e'] = 's';
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    vector<vector<bool>> seen(H,vector<bool>(W,false));
    auto dfs = [&](auto &dfs, int i, int j) -> void{
        seen[i][j] = true;
        for(int k=0;k<4;k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(!wakunai(ni,nj,H,W))continue;
            if(seen[ni][nj])continue;
            if(mp[ni][nj]!=next[mp[i][j]])continue;
            dfs(dfs,ni,nj);
        }
    };
    dfs(dfs,0,0);
    cout << (seen[H-1][W-1] ? "Yes" : "No" ) << endl;
}