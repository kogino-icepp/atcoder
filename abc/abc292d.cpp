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
using Graph=vector<vector<int>>;
int main(){
    int N,M;cin >> N >> M;
    Graph G(N+1);
    for(int i=0;i<M;i++){
        int u,v;cin >> u >> v;
        if(u==v)G[u].push_back(v);
        else{
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    vector<bool> seen(N+1,false);
    for(int i=1;i<=N;i++){
        if(seen[i])continue;
        queue<int> que;
        que.push(i);
        int nnum=0;
        int vnum=0;
        int dcount=0;
        while(!que.empty()){
            int v=que.front();
            que.pop();
            nnum++;
            vnum+=G[v].size();
            seen[v]=true;
            for(auto nv:G[v]){
                if(v==nv){
                    dcount++;
                    continue;
                }
                if(seen[nv])continue;
                que.push(nv);
                seen[nv]=true;
            }
        }
        if(nnum!=dcount+(vnum-dcount)/2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}