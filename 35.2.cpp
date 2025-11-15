#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 0;
    cin >> a;
    
    // 创建数组表示牌的状态（1表示正面，0表示反面）
    int b[a];
    
    // 初始化所有牌为正面（1）
    for (int i = 0; i < a; i++) {
        b[i] = 1;
    }
    
    
    for (int bs = 2; bs <= a; bs++) {
        
        for (int i = bs - 1; i < a; i += bs) {
            b[i] = 1 - b[i];  
        }
    }
    
    
    for (int i = 0; i < a; i++) {
        if (b[i]==1){
            cout<<i+1;
        }
    }
    cout << endl;
    
    return 0;
}