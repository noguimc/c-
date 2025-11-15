#include <iostream>
using namespace std;

int main() {
    int a[3][3] = {{1, 2, 3}, {3, 4, 6}, {7, 8, 9}};
    int b;
    cin >> b;
    if (b == 1) {
        for (int j = 2; j >= 0; j--) {
            for (int i = 0; i < 3; i++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        for (int j = 0; j < 3; j++) {
            for (int i = 2; i >= 0; i--) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}