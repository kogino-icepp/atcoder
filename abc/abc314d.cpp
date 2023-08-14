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
#include <deque>
#include <stack>
#include <atcoder/modint>
#define rep(i,n) for(int i=0;i<n;i++)
#define prep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fore(i,v) for(auto& i:v)
using namespace std;

int main(){
    int N;cin >> N;
    string S;cin >> S;
    int Q;cin >> Q;
    vector<pair<int,char>> status;
    rep(i,N){
        status.push_back({0,S[i]});
    }
    pair<int,int> change = {};
    bool hantei = false;
    rep(i,Q){
        int t,x;
        char c;
        cin >> t >> x >> c;
        if(t==1){
            status[x-1] = {i,c};
        }
        else if(t==2 || t==3){
            hantei = true;
            change = {i,t};
        }
    }
    rep(i,N){
        if(!hantei || status[i].first>=change.first)cout << status[i].second;
        else if (change.second == 2)cout << static_cast<char>(tolower(status[i].second));
        else cout << static_cast<char>(toupper(status[i].second));
    }
    cout << endl;
}