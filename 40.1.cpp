#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    int b[a];
    
    
    for (int i = 0; i < a; i++) {
        cin >> b[i];
    }
    
    
    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < a; j++) {
            if (b[i] == b[j]) {
                
                for (int k = j; k < a - 1; k++) {
                    b[k] = b[k + 1];
                }
                a--;  
                j--;  
            }
        }
    }
    
    
    for (int i = 0; i < a; i++) {
        cout << b[i] << " ";
    }
    
    return 0;
}