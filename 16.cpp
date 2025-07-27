#include <iostream>
#include <cmath>
using namespace std;


bool ok(int c) {
    int a = 1; 
    
    
    int s = sqrt(c);
    
    
    for (int i = 2; i <= s; i++) {
        if (c % i == 0) {
            a += i;
            
            if (i != c / i) {
                a += c / i;
            }
        }
    }
    
    
    return a == c;
}

int main() {
    int n;
    
    cin >> n;
    
    
    
    int no;
    no=0;
    for (int i = 2; i <= n; i++) {
        if (ok(i)) {
            cout << i << " ";
            no=1;
        }
    }
    
    
    if (no==0) {
        cout << "NULL";
    }
    
    cout << endl;
    return 0;
}
