#include <bits/stdc++.h>
using namespace std;

// 更高效的检查方法
bool hasNoSeven(int num) {
    while (num > 0) {
        if (num % 10 == 7) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    int a;
    cin >> a;
    int b[a];
    
    // 读取所有输入
    for (int i = 0; i < a; i++) {
        cin >> b[i];
    }
    
    // 找到最大值，用于优化
    int max_val = 0;
    for (int i = 0; i < a; i++) {
        if (b[i] > max_val) {
            max_val = b[i];
        }
    }
    
    
    vector<int> prefix(max_val + 1, 0);
    for (int i = 1; i <= max_val; i++) {
        prefix[i] = prefix[i-1] + (hasNoSeven(i) ? 1 : 0);
    }
    
    
    for (int i = 0; i < a; i++) {
        cout << prefix[b[i]] << endl;
    }
    
    return 0;
}