#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    
    cin >> a >> b >> c;

    int n = 0; 

    
    
    for (int x = 0; x <= c / a; ++x) {
        
        int r = c - a * x;
        
        
        if (r % b == 0) {
            int y = r / b;
            if (y >= 0) {
                n++;
                
            }
        }
    }

    cout <<  n << endl;

    return 0;
}
