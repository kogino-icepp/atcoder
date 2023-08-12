#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
const int INF=1e9;
int main(){
    //O(NlogN)までならOK
    ll N;cin >> N;
    ll D;cin >> D;
    vector<pair<ll,ll>> kabe;
    for(ll i=0;i<N;i++){
        ll L,R;cin >> L >> R;
        kabe.emplace_back(L,R);
    }
    //ラムダ式でソートの条件を指定
    sort(kabe.begin(),kabe.end(),[](auto const& a,auto const& b){
        return a.second<b.second;
    });
    ll ans=0;
    ll pos=-1000000010;
    for(auto k:kabe){
        if(pos+D-1<k.first){
            ans++;
            pos=k.second;
            //cout << pos << endl;
        }
    }
    cout << ans << endl;
}