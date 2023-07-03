#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,X,Y,Z;
    cin >> N >> X >> Y >> Z;
    vector<int> a(N+5),b(N+5);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    for(int i=0;i<N;i++){
        cin >> b[i];
    }
    vector<bool> passed(N+5,false);/*合格者の配列*/

    vector<int> c;
    for(int i=1;i<=N;i++){
        c.push_back(10000*(100-a[i])+i);/*cに数学の得点を、出席番号が効いてくる形で代入*/
    }
    sort(c.begin(),c.end());
    for(int i=0;i<X;i++){
        passed[c[i]%10000]=true;
    }
    c.clear();/*ここで一回配列をクリア*/
    for(int i=1;i<=N;i++){
        if(!passed[i]){
            c.push_back(10000*(100-b[i])+i);
        }
    }
    sort(c.begin(),c.end());
    for(int i=0;i<Y;i++){
        passed[c[i]%10000]=true;
    }
    c.clear();
    for(int i=1;i<=N;i++){
        if(!passed[i]){
            c.push_back(10000*(200-a[i]-b[i])+i);
        }
    }
    sort(c.begin(),c.end());
    for(int i=0;i<Z;i++){
        passed[c[i]%10000]=true;
    }

    for(int i=1;i<=N;i++){
        if(passed[i]){
            cout << i << endl;
        }
    }
    return 0;
}