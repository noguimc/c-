#include <bits/stdc++.h>
using namespace std;

int main() {
    int a=0,b=0;
    cin>>a>>b;
    int c[a][b];


    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> c[i][j];
        }
    }
    
    int d;
    cin >> d;
    
    if (d == 1) {
        for (int i = 0; i < a; i++) {
            for (int j = b - 1; j >= 0; j--) {
                cout << c[i][j];
                if (j > 0) cout << " "; 
            }
            cout << endl;
        }
    }
    
    if (d == 0) {
        for (int i = a - 1; i >= 0; i--) {
            for (int j = 0; j < b; j++) {
                cout << c[i][j];
                if (j < b - 1) cout << " "; 
            }
            cout << endl;
        }
    }
    
    return 0;
}

