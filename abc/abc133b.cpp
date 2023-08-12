#include <iostream>
#include <cmath>
using namespace std;

bool is_integer( double x ){
  return floor(x)==x;
}
int main(){
    int n,d;
    cin >> n >> d;
    int pos[n][d];
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin >> pos[i][j];
        }
    }
    int num=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double dis2=0;
            for(int k=0;k<d;k++){
                dis2+=(pos[i][k]-pos[j][k])*(pos[i][k]-pos[j][k]);
            }
            double dis=sqrt(dis2);
            if(is_integer(dis)){
                num+=1;
            }
        }
    }
    cout << num << endl;
}