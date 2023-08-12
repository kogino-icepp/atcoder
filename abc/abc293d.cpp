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
using Graph2 = vector<vector<pair<int,int>>>;
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
/*struct UnionFind{
    vector<int> r;
    UnionFind(int N){
        r=vector<int>(N,-1);
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
    }
};*/
int main(){
    int N,M;cin >> N >> M;
    Graph G(N+1);
    vector<int> dim(N+1,0);
    for(int i=0;i<M;i++){
        int a,c;
        char b,d;
        cin >> a >> b >> c >> d;
        G[a].push_back(c);
        G[c].push_back(a);
        dim[a]++;
        dim[c]++;
    }
    int X,Y;
    X=0;
    Y=0;
    vector<bool> seen(N+1,false);
    for(int i=1;i<=N;i++){
        if(seen[i])continue;
        queue<int> que;
        que.push(i);
        bool which=true;
        while(!que.empty()){
            int v=que.front();
            que.pop();
            if(dim[v]!=2)which=false;
            for(auto nv:G[v]){
                if(seen[nv])continue;
                que.push(nv);
                seen[nv]=true;
            }
        }
        if(which)X++;
        else Y++;
    }
    cout << X << " " << Y << endl;
}