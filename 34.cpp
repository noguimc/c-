#include <bits/stdc++.h>
using namespace std;
int abc(const string& numberStr, int targetDigit) {
    int count = 0;
    
    for (char digitChar : numberStr) {
        if (isdigit(digitChar)) {
            int digit = digitChar - '0';
            if (digit == targetDigit) {
                count++;
            }
        }
    }
    
    return count;
}
int main(){
    return 0;
    int a,b;
    cin>>a;
    cout<<count;
}