#include <iostream>
#include <math.h>
#include <cfenv>
#include <iomanip>
using namespace std;

int main(){
    long long A;
    long long B;
    cin >> A >> B;
    if(B>=A/2){
        long double a=A;
        cout << fixed;
        cout << setprecision(7) <<a << endl;
        return 0;
    }
    long double x=powl(A/(2*B),2.0/3.0)-1;
    long long X=floor(x);
    if(B+A/sqrtl(X+2)-A/sqrtl(X+1)>0){
        cout << fixed;
        cout << setprecision(7) << A/sqrtl(X+1)+B*X << endl;
    }
    else{
        cout << fixed;
        cout << setprecision(7) << A/sqrtl(X+2)+B*(X+1) << endl;
    }
}