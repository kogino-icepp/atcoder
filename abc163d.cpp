#include <iostream>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    long long ans=0;
    long long end=0;
    long long first=0;
    int n=N;
    for(int i=K;i>=1;i--){
        end+=n;
        n--;
        first+=i-1;
    }
    for(int i=K;i<=N+1;i++){
        ans+=end-first+1;
        first+=i;
        end+=N-i;
    }
    cout << ans%1000000007 << endl;
}