#include <bits/stdc++.h>
using namespace std;

int main() {
    int a=0;
    cin>>a;
    int b[a];
    for(int i=0;i<a;i++){
        cin>>b[i];
    }
    int c=0;
    for(int i=0;i<a;i++){
        c=c+b[i];
    }
    c=c/a;
    int d=0;
    for(int i=0;i<a;i++){
        if(b[i]>c){
            d=d+b[i]-c;
        }
    }
    cout<<d;
}