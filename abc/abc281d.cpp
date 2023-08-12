#include <iostream>
#include <algorithm>
using namespace std;
//何が何由来のノイズなのかはさておきとりあえず棘を殺す用
int main(){
    int N,M,K;
    cin >> N >> M >> K;
    vector<int> A;
    vector<int> B;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        A.push_back(a);
        if(i<M) B.push_back(a);
    }
    sort(B.begin(),B.end());
    long long sum=0;
    for(int i=0;i<K;i++){
        sum+=B.at(i);
    }
    int max=B.at(K-1);
    cout << sum << " ";
    for(int i=0;i<N-M;i++){
        if(A[i]<=max){
            sum-=A[i];
            sum+=B.at(K);
        }
        if()
    }
}