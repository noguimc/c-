#include <bits/stdc++.h>
using namespace std;
int main() {
    int b,c;
    string a;
    cin>>c;
    for (int i=1;i<c;i++){
       cin>>a;
       if(a.find("L")!=string::npos){
            c=a.find("L");
            a[c]='l';
            a.insert(c+1,"YES");
       }else if(a.find("O")!=string::npos){
            c=a.find("O");
            a[c]='o';
            a.insert(c+1,"YES");
       }else if(a.find("V")!=string::npos){
            c=a.find("V");
            a[c]='v';
            a.insert(c+1,"YES");
       }else if(a.find("E")!=string::npos){
            c=a.find("E");
            a[c]='e';
            a.insert(c+1,"YES");
       }else{
            a="NO";
       }
       cout<<a<<endl;
    }
}