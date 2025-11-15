#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int a;
    cin>>a;
    int b[a],c;
    for(int i=0;i<a;i++){
        cin>>b[i];
    }
    c=b[1]-b[0];
    for(int i=0;i<a-1;i++){
        if(b[i+1]-b[i]>c){
            c=b[i+1]-b[i];
            break;
        }
    }cout<<c;


    return 0;
}