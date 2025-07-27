#include <iostream>
#include <cmath>
using namespace std;
int out(int n){
    if(n<=1){
        return n;
    }
    return (out(n-1)+1)*2;
}
int main(){
    int b;
    cin>>b;
    cout<<out(b);
    
    return 0;
}