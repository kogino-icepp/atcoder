#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<string,int> mp;
    vector<string> lis;
    int max=-1;
    for(int i=0;i<N;i++){
        string S;
        cin >> S;
        if(mp[S]==0){
            lis.push_back(S);
        }
        mp[S]+=1;
        if(mp[S]>max){
            max=mp[S];
        }
    }
    sort(lis.begin(),lis.end());
    for(auto& i:lis){
        if(mp[i]==max){
            cout << i << endl;
        }
    }
}