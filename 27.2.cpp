#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a, b, c = 0;
    cin >> a;
    cin >> b;

    for(long long i = a; i <= b; i++){
        long long p = 1; 
        long long d = i;
        while(d != 0){
            p *= 10; 
            d /= 10;
        }
        c = c * p + i; 
    }
    cout << c;
    return 0;
}