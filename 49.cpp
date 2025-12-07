#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    
    int b=0;
    
    for (int i = 1; i <= n; i++) {
        
        
        b = b ^ i;
        cout << b << endl;
    }
    
    return 0;
}