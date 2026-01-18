#include <bits/stdc++.h>
using namespace std;
int main(){
    int *p;
    int a=10;
    p=&a;
    cout <<"p =" <<p <<";a="<<a<<"; *q="<<*p<<endl;
    int &ref =a;
    ref =10;
    cout <<"ref =" <<ref << ";a=" <<a<<"; *q="<<*p<<endl;
    return 0;
}