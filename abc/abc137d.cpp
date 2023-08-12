#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> Q[101010];
int A[101010],B[101010];
int main(){
    int N,M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> A[i] >> B[i];
    }
    for(int i=0;i<N;i++){
        Q[A[i]].push_back(B[i]);
    }
    //Qのラベルが日数、格納されている値が報酬
    priority_queue<int> que;
    int ans=0;
    //日数が早いものから順に見ていく
    for(int m=1;m<M+1;m++){
        //とある日数の中で大きいものから順にブッシュしていく
        for(auto &b:Q[m]){
            que.push(b);
        }
        if(!que.empty()){
            ans+=que.top();
            que.pop();
        }
    }
    cout << ans << endl;
}