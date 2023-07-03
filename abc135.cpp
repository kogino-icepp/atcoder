#include <iostream>
using   namespace std;

int n,P[50],Q[50];
bool check(int* v){
    for(int i=0;i<n;i++){
        if(v[i]!=i+1){
            return false;
        }
    }
    return true;
}
string solve(){
    if(check(P))return "YES";
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<n;k++){
                Q[k]=P[k];
            }
            swap(Q[i],Q[j]);
            if(check(Q))return "YES";
        }
    }
    return "NO";
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> P[i];
    }
    cout << solve() << endl;
}