#include <bits/stdc++.h>
using namespace std;
struct a {
    string b; // id 可能有前导0，改为string
    int c;
};
bool s(a x, a y) {
    if (x.c >= 60 && y.c < 60) return true;
    if (x.c < 60 && y.c >= 60) return false;
    if (x.c >= 60 && y.c >= 60) {
        if (x.c != y.c) return x.c > y.c;
        return x.b < y.b;
    }
    if (x.b != y.b) return x.b < y.b;
    return x.c > y.c;
}
int main(){
    int c = 0;
    cin >> c;
    a e[c];
    for (int i =0;i<c;i++){
        cin >> e[i].b >> e[i].c;
    }
    sort(e, e + c, s);
    for (int i = 0; i < c; i++) {
        cout << e[i].b << endl;
    }
}