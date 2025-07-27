#include <bits/stdc++.h>
using namespace std;
int main(){
    int b;
    cin>>b;
    int a[b];
    for (int i=0;i<b;i++){
        cin>>a[i];
    }
    int c,d=0;
    cin>>c;
    for (int i=0;i<b;i++){
        if (a[i]==c){
            d=d+1;
        }
    }
    cout<<d<<endl;
}