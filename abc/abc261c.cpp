#include <iostream>
#include <map>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<string,int> memo;
    for(int i=0;i<N;i++){
        string S;
        cin >> S;
        memo[S]+=1;
        if(memo[S]==1){
            cout << S << endl;
        }
        else{
            cout << S << "(" << memo[S]-1 <<")" << endl;
        }
    }
}