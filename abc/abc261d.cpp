#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N,M;
    cin >> N >> M;
    long long X[5001];
    long long b[5001];
    long long dp[5001][5001];
    long long c,y;
    
    for(int i=0;i<N;i++){
        cin >> X[i+1];
    }
    for(int i=0;i<=N;i++){
        b[i]=0;
    }

    for(int i=0;i<M;i++){
        cin >> c >> y;
        b[c]=y;
    }
    dp[0][0]=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j-1]+X[i]+b[j];
            dp[i][0]=0;
            for(int j=0;j<i;j++){
                dp[i][0]=max(dp[i][0],dp[i-1][j]);
            }
        }
    }
    long long ans=0;
    for(int i=0;i<=N;i++){
        ans=max(ans,dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}