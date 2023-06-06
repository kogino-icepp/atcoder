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
//const int mod=1000000007;
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
vector<vector<ll>> mat_mul(vector<vector<ll>> a,vector<vector<ll>>b,ll mod){
    int n=a.size();
    vector<vector<ll>> res(n,vector<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                res[i][j]+=a[i][k]*b[k][j];
                res[i][j]%=mod;
            }
        }
    }
    return res;
}
vector<vector<ll>> mat_pow(vector<vector<ll>>a,ll b,ll mod){
    int n=a.size();
    vector<vector<ll>> res(n,vector<ll>(n));
    for(int i=0;i<n;i++)res[i][i]=1;
    while(b){
        if(b&1)res = mat_mul(res,a,mod);
        a = mat_mul(a, a, mod);
        b >>= 1;
    }
    return res;
}
int main(){
    ll a,x,m;
    cin >> a >> x >> m;
    vector<vector<ll>> f = {{a,1},{0,1}};
    vector<vector<ll>> ans = mat_pow(f,x,m);
    cout << ans[0][1] << endl;
}