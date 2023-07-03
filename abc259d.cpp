#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
using Graph = vector<vector<int>>;
const double pi=acos(-1);

void dfs(int v,vector<vector<int>>&G,vector<bool>&seen){
    seen[v]=true;
    for(auto v2:G[v]){
        if(seen[v2])continue;
        dfs(v2,G,seen);
    }
}
int main(){
    int N;
    cin >> N;
    long long sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    vector<long long> start;
    vector<long long> stop;
    vector<pair<long long,long long>> pos;
    vector<long long> rad;
    Graph G(N);
    for(int i=0;i<N;i++){
        long long x,y,r;
        cin >> x >> y >> r;
        pos.emplace_back(x,y);
        rad.push_back(r);
        if(r*r==(x-sx)*(x-sx)+(y-sy)*(y-sy)){
            start.push_back(i);
            //cout << "start is" << i << endl;
        }
        if(r*r==(x-tx)*(x-tx)+(y-ty)*(y-ty)){
            stop.push_back(i);
            //cout << "stop is" << i << endl;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            long long dr=rad[i]-rad[j];
            long long sr=rad[i]+rad[j];
            long long dx=pos[i].first-pos[j].first;
            long long dy=pos[i].second-pos[j].second;
            //cout << dx*dx+dy*dy << " " << dr*dr << " " << sr*sr << endl;
            if(dr*dr<=dx*dx+dy*dy && sr*sr>=dx*dx+dy*dy){
                G[i].push_back(j);
                G[j].push_back(i);
                //cout << i <<" " << j << endl;
            }
        }
    }
    vector<bool> seen(N,false);
    for(auto v:start)dfs(v,G,seen);
    for(auto v:stop){
        if(seen[v]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}