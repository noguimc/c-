#include <bits/stdc++.h>
using namespace std;
struct a {
    string name;
    string cj[6];
};
int main(){
    int c=0;
    cin>>c;
    vector<a> b(c); // 定义存储结构体的数组
    for (int i = 0; i < c; i++) {
        cin >> b[i].name;
        if (b[i].name.length() < 7 || b[i].name.length() > 10) {
            cout << "Invalid name length for " << b[i].name << endl;
            return 1; // 退出程序
        }
        for (int j = 0; j < 6; j++) {
            cin >> b[i].cj[j];
            if (b[i].cj[j].length() != 6 || !all_of(b[i].cj[j].begin(), b[i].cj[j].end(), ::isdigit)) {
                cout << "Invalid cj value: " << b[i].cj[j] << endl;
                return 1; // 退出程序
            }
        }
    }
}