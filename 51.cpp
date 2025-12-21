#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    int *p1=&x;
    int *p2=&y;
    int **p3=&p1;
    *p1=3;
    *p2=5;
    cout<<x<<y<<endl;
    **p3=+10;
    cout<<x<<endl;
    return 0;
}