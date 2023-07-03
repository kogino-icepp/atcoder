#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
using Graph = vector<vector<int>>;


int main(){
    int N;cin >> N;
    map<int,vector<int>> G;
    
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> que;
    set<int> S;
    S.insert(1);
    que.push(1);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(auto nv:G[v]){
            if(!S.count(nv)){
                que.push(nv);
                S.insert(nv);
            }
        }
    }
    cout << *S.rbegin() << endl;
}