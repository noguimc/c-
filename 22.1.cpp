#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 0;
    cin >> a;
    int b[a];
    for (int i = 0; i < a; i++) {
        cin >> b[i];
    }
    sort(b, b + a);

    // 输出最大值（最后一个元素）
    int c = a - 1;
    cout << b[c];

    // 向前查找第一个不等于最大值的元素
    int index = c - 1;
    while (index >= 0 && b[index] == b[c]) {
        index--;
    }

    // 如果找到第二大值则输出
    if (index >= 0) {
        cout << b[index];
    }

    return 0;
}