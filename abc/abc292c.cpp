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
const int MA = 1000001;
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
int main(){
    ll N;cin >> N;
    ll ans=0;
    for(ll i=1;i<N;i++){
        ll x1=i;
        ll x2=N-i;
        ans+=divisor_num(x1)+divisor_num(x2);
    }
    cout << ans << endl;
}