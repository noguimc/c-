#include <bits/stdc++.h>
using namespace std;

int main() {
    int c;
    cin >> c;

    int a[c][c], b = 0;

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    // 计算并输出主对角线的和
    for (int i = 0; i < c; i++) {
        b += a[i][i];
    }
    cout <<   b << endl;
    b = 0; // 重置b，以便计算副对角线的和

    // 计算并输出副对角线的和
    for (int i = 0; i < c; i++) {
        b += a[i][c - i - 1];
    }
    cout <<   b << endl;

    return 0;
}
