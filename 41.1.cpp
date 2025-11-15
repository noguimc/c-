#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    
    char g[100][100];
    
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> g[i][j];
        }
    }
    
    
    bool r[100][100] = {false}; 
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; ) {
            if (g[i][j] == '.') {
                j++;
                continue;
            }
            
            int k = j;
            while (k < b && g[i][j] == g[i][k]) {
                k++;
            }
            
            
            if (k - j >= 3) {
                for (int l = j; l < k; l++) {
                    r[i][l] = true;
                }
            }
            
            j = k;
        }
    }
    
    
    for (int j = 0; j < b; j++) {
        for (int i = 0; i < a; ) {
            if (g[i][j] == '.') {
                i++;
                continue;
            }
            
            int k = i;
            while (k < a && g[i][j] == g[k][j]) {
                k++;
            }
            
            
            if (k - i >= 3) {
                for (int l = i; l < k; l++) {
                    r[l][j] = true;
                }
            }
            
            i = k;
        }
    }
    
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (r[i][j]) {
                g[i][j] = '.';
            }
        }
    }
    
   
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}