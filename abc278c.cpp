#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int main(){
    int n,q;
    cin >> n >>q;

    set<pair<int,int>> follows;

    for(int i=0;i<q;i++){
        int type,a,b;
        cin >> type;
        if(type==1){
            cin >> a >> b;
            follows.emplace(a,b);
        }
        else if(type==2){
            cin >> a >> b;
            follows.erase({a,b});
        }
        else{
            cin >> a >> b;
            cout << (follows.count({a,b}) && follows.count({b,a})?"Yes":"No") << endl; 
        }
    }
    return 0;
}