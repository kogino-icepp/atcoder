#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  
  vector<string> S(H);
  for(auto &x : S) cin >> x;
  
  int ans = 0;
  for(int i = 0; i < H - 1; i++){
    for(int j = 0; j < W - 1; j++){
      int sum = 0;
      sum += (S[i][j] == '#');
      sum += (S[i + 1][j] == '#');
      sum += (S[i][j + 1] == '#');
      sum += (S[i + 1][j + 1] == '#');
      
      if(sum == 1 || sum == 3) ans++;
    }
  }
  
  cout << ans;
}