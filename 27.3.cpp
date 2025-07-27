#include <bits/stdc++.h>
using namespace std;
int lyjf(int a,int b){
    int c=1;
    while(c%a!=0||c%b!=0){
        c++;
    }
    return c;
}
int main(){
    long long a,b,c=1,d;
    cin>>d;
    long long e[d];
    for(int i=1;i<=d;i++){
        cin>>a>>b;
        
        e[i]=lyjf(a,b);
    }
    for(int i=1;i<=d;i++){
        cout<<e[i]<<endl;
    }
   





}