#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[2][3] = {
        {4, 3, 1},
        {5, 6, 2}
    };
    
    
    int b[3][2];
    
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            b[j][1-i] = a[i][j];
        }
    }
    
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}