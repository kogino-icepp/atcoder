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
/*#define rep(i,n) for(ll i=0;i<n;i++)
#define prep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define fore(i,v) for(auto& i:v)*/
using namespace std;
typedef long long ll;
const ll mod=1000000007;
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
//
int main(){
    int N,Q;cin >> N >> Q;
    int M = 200010;
    vector<vector<int>> box(N+1,vector<int>());
    vector<vector<int>> card(M,vector<int>());

    while(Q--){
        int t;cin >> t;
        if(t==1){
            int i,j;cin >> i >> j;
            card[i].push_back(j);
            box[j].push_back(i);
        }
        else if(t==2){
            int i;cin >> i;
            sort(box[i].begin(),box[i].end());
            for(int k=0;k<box[i].size();k++)cout << box[i][k] << " ";
            cout << endl;
        }
        else{
            int i;cin >> i;
            sort(card[i].begin(),card[i].end());
            card[i].erase(unique(card[i].begin(),card[i].end()),card[i].end());
            for(int k=0;k<card[i].size();k++)cout << card[i][k] << " ";
            cout << endl;
        }
    }
}