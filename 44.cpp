#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    int b = 0;
    
    bool isNegative = false;
    if (a < 0) {
        isNegative = true;
        a = -a;
    }
    
    
    while (a > 0) {
        b = b * 10 + a % 10;
        a /= 10;
    }
    
    if (isNegative) {
        b = -b;
    }
    
    cout << b << endl;
    return 0;
}