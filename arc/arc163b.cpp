#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
//A1,A2の範囲を求めて
int inf = 2000000000;
int main(){
    int N,M;cin >> N >> M;
    int A1,A2;cin >> A1 >> A2;
    vector<int> A(N-2);
    rep(i,N-2)cin >> A[i];
    sort(A.begin(),A.end());
    int ans = inf;
    rep(i,N-1-M){
        ans = min(ans,max(A1-A[i],0)+max(A[M+i-1] - A2, 0));
    }
    cout << ans << endl;
}
