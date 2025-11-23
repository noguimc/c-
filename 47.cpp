#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;
    
    for(int i=1;i<8;i++){
        if (a[0]=='0'){
            cout<<a<<endl;
            break;
        }
        if(a[i]=='0'){
            a[i]='1';
        }
        if(a[i]=='1'){
            a[i]='0';
        }

    }
    if (a[0]!='0'){
        cout<<a<<endl;
    }
    for(int i=1;i<8;i++){
        if (a[0]=='0'){
            cout<<a<<endl;
            break;
        }
        if(a[7]=='0'){
            a[7]='1';

        }else{
            a[7]='0';
        }     





    }
    if (a[0]!='0'){
        cout<<a;
    }
    return 0;
}