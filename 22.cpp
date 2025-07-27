#include <iostream>
using namespace std;
int f(int x,int y){
    if (y%2==0&&y>0){
        return f(x,y/2)*f(x,y/2);

    }
    if (y%2==1&&y>0){
        return f(x,y/2)*f(x,y/2)*x;
    }
    if (y==0){
        return 1;
    }
}
int main() {
    int x,y;
    cin>>x>>y;
    cout<<f(x,y);
    return 0;
}