#include <iostream>
#include <cmath>
using namespace std;
// 递归函数检查n是否能被从start到sqrt(n)的数整除
bool out(int n, int start) {
    // 基本情况：如果start大于sqrt(n)，说明没有找到因数，n是质数
    if (start > sqrt(n)) {
        return true;
    }
    
    // 如果n能被start整除，则n不是质数
    if (n % start == 0) {
        return false;
    }
    
    // 递归检查下一个数
    return out(n, start + 1);
}

// 主函数判断n是否为质数
bool ifs(int n) {
    // 特殊情况处理
    if (n <= 1) {
        return false;  
    }
    if (n <= 3) {
        return true;   
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;  
    }
    
    
    return out(n, 5);
}

int main() {
    int number;
    cout << "请输入一个正整数: ";
    cin >> number;
    
    if (ifs(number)) {
        cout << number << " YES" << endl;
    } else {
        cout << number << " NO" << endl;
    }
    
    return 0;
}
