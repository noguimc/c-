#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[100];string n;
    cin>>n;
    int len=n.length();
    for(int i=1;i<len+1;i++){
        a[i-1]=n[i-1]-'0';
    }
    for(int i=len-1;i>-1;i--){
       
        cout<<a[i];
        
    }
}