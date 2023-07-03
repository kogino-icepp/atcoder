#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dx={0,-1,-1,-1,0,1,1,1};
vector<int> dy={1,1,0,-1,-1,-1,0,1};
int main() {
    int N;cin >> N;
    vector<vector<char>> mp(N,vector<char>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> mp[i][j];
        }
    }
    vector<string> all;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<8;k++){
                string S;
                int x=i;int y=j;
                for(int l=0;l<N;l++){
                    S.push_back(mp[x][y]);
                    x+=dx[k]+N;
                    y+=dy[k]+N;
                    x%=N;y%=N;
                }
                all.push_back(S);
            }
        }
    }
    sort(all.begin(),all.end(),greater<string>());
    cout << all[0] << endl;
}
