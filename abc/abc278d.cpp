#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int &a:A){
        cin >> a;
    }
    int base=0;
    map<int,long long> M;
    for(int i=0;i<n;i++){
        M[i] = A[i];
    }
    int Q;cin >> Q;
    for(int q=0;q<Q;q++){
        int t;cin >> t;
        if(t==1){
            int x;cin >>x;base=x;
            M.clear();
        }
        else if(t==2){
            int i,x;
            cin  >> i >> x;
            M[i-1]+=x;
        }
        else if(t==3){
            int i;
            cin >> i;
            cout << base+M[i-1] << endl;
        }
    }
}