#include <iostream>
using namespace std;


int out(int n) {
    if (n <= 1) {
        return n;
    }
    return 2 * out(n - 1) + 1;
}

int main() {
    int n;
    cin >> n;
    cout << out(n);
    
    return 0;
}
