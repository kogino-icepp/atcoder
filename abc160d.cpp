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
vector<vector<int>> G;

int main(){
    int X,Y,A,B,C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A);
    vector<ll> q(B);
    vector<ll> r(C);
    for(int i=0;i<A;i++)cin >> p[i];
    for(int i=0;i<B;i++)cin >> q[i];
    for(int i=0;i<C;i++)cin >> r[i];
    sort(p.begin(),p.end(),greater<ll>());
    sort(q.begin(),q.end(),greater<ll>());
    sort(r.begin(),r.end(),greater<ll>());
    ll ans=0;
    int px=X-1;
    int qx=Y-1;
    for(int i=0;i<C;i++){
        if(px>=0 && qx >=0){
            if(r[i]<=p[px] && r[i]<=q[qx])break;
            else if(r[i]<=p[px] && r[i]>q[qx]){
                q[qx]=r[i];
                qx--;
            }
            else if(r[i]>p[px] && r[i]<=q[qx]){
                p[px]=r[i];
                px--;
            }
            else{
                if((r[i]-p[px])>(r[i]-q[qx])){
                    p[px]=r[i];
                    px--;
                }
                else{
                    q[qx]=r[i];
                    qx--;
                }
            }
        }
        else if(px>=0 && qx<0){
            if(r[i]<=p[px])break;
            else{
                p[px]=r[i];
                px--;
            }
        }
        else{
            if(r[i]<=q[qx])break;
            else{
                q[qx]=r[i];
                qx--;
            }
        }
    }
    for(int i=0;i<X;i++)ans+=p[i];
    for(int i=0;i<Y;i++)ans+=q[i];
    cout << ans << endl;
}