#include <bits/stdc++.h>
using namespace std;

int jys(int a) {
    int b = 0;
    for(int i = 2; i * i <= a; i++){
        while(a % i == 0){
            a = a / i;
            if(i > b){
                b = i;
            }
        }
    }
    
    if (a > 1) {
        b = a;
    }
    return b;
}
int main(){
    int a, b, c = 0;
    cin >> a;
    for (int i = 0; i < a; i++){
        cin >> b;
        int maxPrime = jys(b);
        if(maxPrime > c){
            c = maxPrime;
        }
    }
    cout << c;
    return 0;
}