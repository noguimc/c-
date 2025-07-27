#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    string a;
    int r = 0, g = 0, b = 0;
    cin >> a;

    // 统计 R、G、B 的数量
    for (char ch : a) {
        if (ch == 'R') {
            r = r + 1;
        } else if (ch == 'G') {
            g = g + 1;
        } else if (ch == 'B') {
            b = b + 1;
        }
    }

    int c[] = {r, g, b};
    sort(c, c + 3);
    cout << c[2];

    sort(a.begin(), a.end());
    // 输出排序后的字符串
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
    }
    cout << c[0];
    return 0;
}