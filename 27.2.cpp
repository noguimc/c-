#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a;
    cin>>a;
    long long b;
    cin>>b;
    long long c=0;
    for(long long i=a;i<=b;i++){
        c=c*10;
        c=c+i;
    }
    cout<<c%9;
}