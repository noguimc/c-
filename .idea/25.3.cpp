#include <bits/stdc++.h>
using namespace std;
struct a{
    string b;
    int c;
}; 

bool cmp(const a &x, const a &y) {
    return x.c > y.c;
}

int main(){
    int n = 0, c = 0;
    cin >> c >> n;
    a e[c];
    for (int i = 0; i < c; i++) {
        cin >> e[i].b >> e[i].c;
    }
    sort(e, e + c, cmp);
    cout << e[n - 1].b << endl; // 输出第n项的名字
}