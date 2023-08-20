#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    int T;cin >> T;
    rep(i,T){
        ll N,K;cin >> N >> K;
        ll X = N;
        ll L = 0;
        while(X>0){
            L += X%3;
            X/=3;
        }
        if(K>=L && K<=N){
            if((N-K)%2==0)cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else cout << "No" << endl;
    }
}