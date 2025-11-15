#include <bits/stdc++.h>
using namespace std;
string miu(int a){
    while(a%3==0){
        a=a/3;
    }if(a==1){
        return "true";
    }else{
        return "false";
    }
}


int main(){
    int a;
    cin>>a;
    cout<<miu(a)<<endl;




    return 0;
}