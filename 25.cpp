#include <bits/stdc++.h>
using namespace std;
struct a{
    string name;
    int cj[4];
};
int main(){
    a b[3];
    for (int i = 0; i < 3; i++) {
        cin >> b[i].name;
        for (int j = 0; j < 4; j++) {
            cin >> b[i].cj[j];
        }
    }
    for(int i=0;i<3;i++){
        int s = 0;
        for(int j=0;j<4;j++){
            s += b[i].cj[j];
        }
        double avg = s / 4.0;
        cout << b[i].name << " " << fixed << setprecision(2) << avg << endl;
    }
}