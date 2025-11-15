#include <iostream>
using namespace std;

int main() {
    int a[3];  // 只需要3个元素
    
    // 输入3个数字
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
               
                if (i != j && i != k && j != k) {
                    cout << a[i] << a[j] << a[k] << " ";
                }
            }
        }
    }
    
    return 0;
} 