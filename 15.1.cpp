#include <bits/stdc++.h>
using namespace std;
double max(int x,int y,int z){
    int a[3]={x,y,z};
    sort(a,a+3);
    return a[2];
}

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    double d=max(a,b,c)/max(a+b,b,c)/max(a,b,b+c);
    cout<<fixed<<setprecision(3)<<d<<endl;
    return 0;
}