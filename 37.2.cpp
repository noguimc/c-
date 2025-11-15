#include <bits/stdc++.h>
using namespace std;
int f(int n){
    if (n==1){
        return 1;
    }if(n==2){
        return 3;
    }else{
        return 3*f(n-1)-2*f(n-2);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}